#include "TCPSocket.h"

using namespace std;

#define _TCP_RESET_DATA_

////////////////////////////////////////////////////////////////////////
#define safeDel(pData) { try { if (pData){delete pData; pData = 0;}} catch(...){ } pData = 0; }
////////////////////////////////////////////////////////////////////////

// ���ݴ�������
#define CMD_DEALDAT_NORMAL_CLOSE          0                   // ����ʾ�ر�
#define CMD_DEALDAT_ERROR                 1                   // ������
#define CMD_DEALDAT_OK                    2                   // ������ȷ
/////////////////////////////////////////////////////////////////////////

// ��������
#define DK_MAPPED                        0x01                // ӳ������
#define DK_ENCRYPT                       0x02                // �������� 
#define DK_COMPRESS                      0x04                // ѹ������ 

// �ں�����
#define MDM_KN_COMMAND                   0                   // �ں�����
#define SUB_KN_DETECT_SOCKET             1                   // �������
#define SUB_KN_VALIDATE_SOCKET           2                   // ��֤���� 


////////////////////////////////////////////////////////////////////////////
//static int g_nSocketIdx = 0;
//static map<int, CTCPSocket*> g_SocketMap;

//SocketDataQueue* Instance = nullptr;
///////////////////////////////////////////////////////////////////////////

void resetAllSocket()
{
	log("not null %d", 99);
	CSocketDataQueue::GetInstance()->resetData();
	//g_nSocketIdx = 0;
}

//////////////////////////////////////////////////////////////////
//CTCPSocket
//////////////////////////////////////////////////////////////////
CTCPSocket::CTCPSocket(void)
{
	m_cbShutReason = 0;
	m_Socket = INVALID_SOCKET;
	m_nSocketIdx = -1;

	m_wRecvLen = 0;

	m_pSocketSink = 0;
	m_pThread = nullptr;
	m_cbSocketStatus = SOCKET_STATUS_IDLE;
	m_nSocketTimeOut = SOCKET_TIME_OUT;

	m_pSocketDataQueue = new (std::nothrow) SocketDataQueue();
    m_pSocketDataQueue->createThread(*this);
}

CTCPSocket::~CTCPSocket(void)
{
	if (m_pThread)
	{
		m_pThread->join();
	}
	safeDel(m_pThread);
	m_Socket = INVALID_SOCKET;
	m_nSocketIdx = -1;
	m_wRecvLen = 0;

	m_cbSocketStatus = SOCKET_STATUS_IDLE;
}

// ���ýӿ�
bool CTCPSocket::SetTCPSocketSink(ITCPSocketSink* pIUnknownEx)
{
	if (m_pSocketSink != pIUnknownEx)
	{
		m_pSocketSink = pIUnknownEx;
	}
	return true;
}

unsigned int CTCPSocket::getTickCount()
{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
	static unsigned long s_mode = 0;
	static unsigned long s_tt = 0;
	if (s_mode == 0)
	{
		unsigned long tps = (unsigned long)sysconf(_SC_CLK_TCK);
		if (1000 % tps == 0)
		{
			s_tt = 1000 / tps;
			s_mode = 1;
		}
		else
		{
			s_tt = tps;
			s_mode = 2;
		}
	}
	struct tms t;
	const unsigned long dw = (unsigned long)times(&t);
#else
	return GetTickCount();
#endif
}

// ���ӷ��� V
unsigned char CTCPSocket::Connect(const char* url, unsigned short wPort)
{
	hostent* hp = gethostbyname(url);

	// ֪ͨʧ��
	if (hp == 0)
	{
		log("get host failed\n");
		return CONNECT_FAILURE;
	}

	sockaddr_in local;
	memset(&local, 0, sizeof(local));
	// ���ӵķ�����IP��ַ
	memcpy((char*)&local.sin_addr, hp->h_addr, hp->h_length);

	// ���ӵ�Э������
	local.sin_family = hp->h_addrtype;
	// ���ӵķ������˿�
	local.sin_port = htons(wPort);

	log("socket connect...������ ip=%s port=%d\n", url, wPort);

	// ���ӷ�����
	try
	{
		// ����socket
		int nRet = SOCKET_ERROR;

		// ȷ�����ӳɹ�
		for (int n = 0; n < 100; n++)
		{
			m_Socket = socket(AF_INET, SOCK_STREAM, 0);

			// ֪ͨʧ��
			if (m_Socket == INVALID_SOCKET)
			{
				//�����׽���ʧ��!
				return CONNECT_FAILURE;
			}

			nRet = connect(m_Socket, (const sockaddr*)&local, sizeof(local));
			if ((nRet == SOCKET_ERROR) && (IsBusy() == false)) 
			{ continue; }

			int rsize = MAX_TCP_BUF;
			if (setsockopt(m_Socket, SOL_SOCKET, SO_RCVBUF, (const char*)&rsize, sizeof(rsize)) == -1)
			{
				int errCode = socket_error();
				log("setsockopt SO_RCVBUF failed. %d \n", errCode);
				socket_close(m_Socket);
				continue;
			}

			int wsize = MAX_TCP_BUF;
			if (setsockopt(m_Socket, SOL_SOCKET, SO_SNDBUF, (const char*)&wsize, sizeof(wsize)) == -1)
			{
				int errCode = socket_error();
				log("setsockopt SO_SNDBUF failed. %d \n", errCode);
				socket_close(m_Socket);
				continue;
			}
			break;
		}

		if ((nRet == SOCKET_ERROR) && (IsBusy() == false))
		{
			log("connet server failed. \n");
			CloseSocket(SHUT_REASON_EXCEPTION);
			return CONNECT_FAILURE;
		}
	}
	catch(...)
	{
		log("connet server exception. \n");
		return CONNECT_EXCEPTION;
	}


	log("connet server ok. \n");


	if (m_nSocketIdx == -1)
	{
		//m_nSocketIdx = g_nSocketIdx++;
		//g_SocketMap[m_nSocketIdx] = this;
	}
	m_cbSocketStatus = SOCKET_STATUS_CONNECT;

	// �����߳�
	try
	{
		if (m_pThread)
		{
			log("wait thread release");

			m_pThread->join();
			safeDel(m_pThread);
		}
		m_pThread = new std::thread(&CTCPSocket::recvData, this);
		m_pThread->detach();
	}
	catch(...)
	{
		log("create connect thread fail!");

		CC_ASSERT(0);
		return CONNECT_FAILURE;
	}

	log("connect 1.\n");
}

// ״̬��ȡ
bool CTCPSocket::IsAlive() const 
{
	if (!(m_Socket != INVALID_SOCKET) && (m_cbSocketStatus == SOCKET_STATUS_CONNECT))
	{
		return false;
	}
	return (m_Socket != INVALID_SOCKET) && (m_cbSocketStatus == SOCKET_STATUS_CONNECT);
}

// socket busy
bool CTCPSocket::IsBusy()
{
#ifdef _WIN32
	// WSAGetLastError��ָ�ú��������ϴη������������.
	log("IsBusy %w", WSAGetLastError());
	return WSAGetLastError() == WSAEWOULDBLOCK;
#else
	int err = errno;
	return err == EAGAIN || err == EINPROGRESS;
#endif
}

// ��ȡSocket
int CTCPSocket::GetSocket() const
{
	return (int)m_Socket;
}
// �������� V
int CTCPSocket::socket_recv(int sSocket, char* data, int nSize)
{
	unsigned int nFlage = 0;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	nFlage = MSG_NOSIGNAL;
#endif
	return recv(sSocket, data, nSize, nFlage);
}
//��������
int CTCPSocket::socket_send(int sSocket, const char* data, int nSize)
{
	unsigned int nFlags = 0;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	nFlags = MSG_NOSIGNAL;
#endif
	return send(sSocket, data, nSize, nFlags);
}
// �ر�
void CTCPSocket::socket_close(int s)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	shutdown(s, SD_BOTH);
	closesocket(s);
#else
	close(s);
#endif
}
// socket ����
int CTCPSocket::socket_error()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	/*�����ϴη������������.��һ�ض���Windows Sockets API����ָ��һ�������Ѿ�����,�ú�����Ӧ��������ö�Ӧ�Ĵ������.*/
	return WSAGetLastError();
#else
	return error;
#endif
}
//sleep V
void CTCPSocket::socket_sleep(unsigned int nMillions)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	Sleep(nMillions);
#else
	usleep(nMillions*1000);
#endif
}

// ���ݷ���
unsigned short CTCPSocket::SendData(ByteBuffer& buffer)
{
	if (!IsAlive())
	{
		return false;
	}
	/*
	// ��������
	unsigned char cbDataBuf[MAX_TCP_BUF] = {0};
	memset(cbDataBuf, 0, sizeof(cbDataBuf));
	
	// ���ð���Ϣ
	int nPackSize = sizeof(TCP_Head) + nDataSize;
	// ���ݰ���С
	CVConvt::SetValue_VORD(cbDataBuf, 2, nPackSize); //0���汾��ʶ 1��У���ֶ�  2�����ݴ�С
	// ������
	CVConvt::SetValue_VORD(cbDataBuf, 4, wMainCmdID);
	// ������
	CVConvt::SetValue_VORD(cbDataBuf, 6, wSubCmdID);
	// ��ֵ
	if (nDataSize > 0)
	{
		memcpy(&cbDataBuf[sizeof(TCP_Head)], data, nDataSize);
	}
	
	// ��������
	nPackSize = EncryptBuffer(cbDataBuf, nPackSize, sizeof(cbDataBuf));
	*/
	// ��������
	//return CTCPSocket::socket_send((int)m_Socket, (const char*)cbDataBuf, nPackSize);

	return 0;
}

void CTCPSocket::onSendThreadStarted(void)
{
	if(!cSocket)
		return false;

	m_SocketState = LuaSocketState::SOCKET_CONNECTING;

	bool ret = true;
	int ret_num = 1;
	ret = cSocket->Connect(m_ip,m_port);
	if (ret == false)
	{
		m_SocketState = LuaSocketState::SOCKET_CONNECTION_FAILURE;
	}
	else
	{
		m_SocketState = LuaSocketState::SOCKET_CONNECTED;
	}
	if(ret == false)
		ret_num = 0;

	_wsHelper->sendMessageToUIThread( new SocketData(-102 ,4, (char*)&ret_num,CONNECT_RET));

	return (LuaSocketState::SOCKET_CONNECTED == m_SocketState);
}

// �����̺߳���
void CTCPSocket::onSendThreadLoop(void)
{

}

// ���ݽ��� V
void* CTCPSocket::RecvData(void* p)
{
	char cbDataBuffer[MAX_TCP_BUF] = {};
	memset(cbDataBuffer, 0, sizeof(cbDataBuffer));

	int nSocketIdx = *(int*)p;
	CTCPSocket* pTCPSocket = g_SocketMap[nSocketIdx];
	if (pTCPSocket == 0)
	{
		log("recv data err!");
		return 0;
	}

	while(pTCPSocket->IsAlive())
	{
		int nDataSize = socket_recv(pTCPSocket->GetSocket(), cbDataBuffer, sizeof(cbDataBuffer));
		if (nDataSize == SOCKET_ERROR)
		{
			int nErrCode = socket_error();
			if (nErrCode == LHS_EWGULDBLOCK)
			{
				socket_sleep(20);
				continue;
			}

			if (nErrCode == LHS_EAGAIN)
			{
				continue;
			}
			//��ӡ������Ϣ
			log("recv err!%d\n", nErrCode);
			// ��������
			if (nErrCode == 10004L) //WSAEINTR
			{
				break;
			}
			// ��ʱ����
			if (nErrCode == 10060L)  //WSAETIMEDOUT
			{
				//pTCPSocket->resetSocket();
				log("time out");
			}

			if (CSocketDataQueue::GetInstance())
			{
				CSocketDataQueue::GetInstance()->push(nSocketIdx, CMD_DEALDAT_ERROR, 0, 0);
			}
			break;
		}

		if (0 == nDataSize)
		{
			break;
		}

		if (CSocketDataQueue::GetInstance())
		{
			CSocketDataQueue::GetInstance()->push(nSocketIdx, CMD_DEALDAT_OK, cbDataBuffer, nDataSize);
		}
	}

	if (CSocketDataQueue::GetInstance())
	{
		CSocketDataQueue::GetInstance()->push(nSocketIdx, CMD_DEALDAT_NORMAL_CLOSE, 0, 0);
	}

	return 0;
}

// ���ݽ��� V
void CTCPSocket::recvData()
{
	char cbDataBuffer[MAX_TCP_BUF] = {};
	memset(cbDataBuffer, 0, sizeof(cbDataBuffer));
	//socket_sleep(200);
	while(this->IsAlive())
	{
		int nDataSize = socket_recv(this->GetSocket(), cbDataBuffer, sizeof(cbDataBuffer));
		if(nDataSize == SOCKET_ERROR)
		{
			int nErrCode = socket_error();
			if (nErrCode == LHS_EWGULDBLOCK)
			{
				socket_sleep(20);
				continue;
			}
			if (nErrCode == LHS_EAGAIN)
			{
				continue;
			}
			//��ӡ������Ϣ
			log("recv err:%d\n", nErrCode);
			// �ж�����
			if (nErrCode == 10004L)
			{
				break;
			}
			// ��ʱ����
			if (nErrCode == 10060L)
			{
				log("time out");
			}

			if (CSocketDataQueue::GetInstance())
			{
				CSocketDataQueue::GetInstance()->push(m_nSocketIdx, CMD_DEALDAT_ERROR, 0, 0);
			}
			break;
		}
		if (0 == nDataSize)
		{
			break;
		}

		if (CSocketDataQueue::GetInstance())
		{
			CSocketDataQueue::GetInstance()->push(m_nSocketIdx, CMD_DEALDAT_OK, cbDataBuffer, nDataSize);
		}
	}

	if (CSocketDataQueue::GetInstance())
	{
		CSocketDataQueue::GetInstance()->push(m_nSocketIdx, CMD_DEALDAT_NORMAL_CLOSE, 0, 0);
	}

	return;
}
// ����
bool CTCPSocket::OnSocketNotifyErr(int nErrCode)
{
	log("shut down Code %d", nErrCode);
	// CloseSocket(SHUT_REASON_EXCEPTION)
	return true;
}
// ����Ͷ�� V
bool CTCPSocket::OnSocketNotifyRead(void* data, int nDataSize)
{
	if (m_pSocketSink == NULL)
	{
		return false;
	}

	// ��������
	memcpy(&m_cbBufRecieve[m_wRecvLen], data, nDataSize);
	// ���չ�������
	m_wRecvLen += nDataSize;
	m_nSocketTimeOut = SOCKET_TIME_OUT;

	// ��������
	unsigned short wPacketSize = 0;
	unsigned char  cbDataBuffer[MAX_TCP_BUF] = {};
	unsigned short wUnpackIndex = 0;
	try
	{
		while((m_wRecvLen - wUnpackIndex) >= sizeof(TCP_Head)) // ���ڰ�ͷ
		{
			wPacketSize = CVConvt::GetValue_WORD(m_cbBufRecieve, 2); //���ݳ��ȣ�������ͷ�ģ�
			unsigned char cbDataKind = m_cbBufRecieve[0]; // �汾��ʶ
			assert(cbDataKind == m_cbEncryptType); //�������� 
			assert(wPacketSize <= MAX_TCP_BUF);
			if (cbDataKind != m_cbEncryptType)
			{
				log("ֻ֧��ӳ�����");
				throw("ֻ֧��ӳ�����");
			}

			if (wPacketSize > MAX_TCP_BUF)
			{
				log("���ݰ�̫�� %d", wPacketSize);
				throw("���ݰ�̫��");
			}

			if (m_wRecvLen < wPacketSize)
			{
				return false;
			}

			/**
			* recv���صĳ���>=һ�������ȣ����Զ���һ���Ƶ���һ����λ��memmove
			*/
			// ��������
			memcpy(cbDataBuffer, m_cbBufRecieve, wPacketSize);
			m_wRecvLen -= wPacketSize; //
			memmove(m_cbBufRecieve, m_cbBufRecieve + wPacketSize, m_wRecvLen); //m_cbBufRecieve�ǳ���ͷ���������

			//��������
			unsigned short wRealySize = CrevasseBuffer(cbDataBuffer, wPacketSize);
			// assert(wPealySize >= sizeof(TCP_Head));

			if (wRealySize < sizeof(TCP_Head))
			{
				CloseSocket(SHUT_REASON_NORMAL);

				// �ر����е�socket
				resetAllSocket();
				break;
			}

			// ��������
			unsigned short wDataSize = wRealySize - sizeof(TCP_Head);  //���ݳ���
			void* pDataBuffer = cbDataBuffer + sizeof(TCP_Head);       //ָ���Ƶ�������ʼλ��

			TCP_Command Command;
			Command.wMainCmdID = CVConvt::GetValue_WORD(cbDataBuffer, 4);  // ��������
			Command.wSubCmdID = CVConvt::GetValue_WORD(cbDataBuffer, 6);   // ��������
			//((TCP_Head*)cbDataBuffer)->CommandInfo;

			// �ں����� ������������
			if (Command.wMainCmdID == MDM_KN_COMMAND)
			{
				switch (Command.wSubCmdID)
				{
				case SUB_KN_DETECT_SOCKET:  // ������
					// ��������
					SendData(MDM_KN_COMMAND, SUB_KN_DETECT_SOCKET);
					break;
				default:
					break;
				}
				continue;
			}
			
			// ��������
			bool bSuccess = m_pSocketSink->OnEventTCPSocketRead((int)m_Socket, Command, pDataBuffer, wDataSize);
			if (bSuccess == false)
			{
				log("�������ݰ�����ʧ�� %d-%d", Command.wMainCmdID, Command.wSubCmdID);
				CloseSocket(SHUT_REASON_NORMAL);
			}
		}
	}
	catch(...)
	{
		CloseSocket(SHUT_REASON_EXCEPTION);
		resetAllSocket();
	}

	return true;
}



////////////////////////////////////////////////////////////////////////////////////////
// ѹ������ V
void CSocketDataQueue::push(unsigned int nOwner, int nCmd, char* data, int nDataSize)
{
	if (nOwner >= 0 && g_SocketMap[nOwner] == 0)
	{
		return;
	}

	tagSocketDataItem DataItem;
	memset(&DataItem, 0, sizeof(DataItem));
	DataItem.nOnwer = nOwner;
	DataItem.nCmd = nCmd;
	DataItem.nDataSize = nDataSize;
	if (data != 0)
	{
		DataItem.data = new char[nDataSize];
		if (DataItem.data == 0)
		{
			return;
		}
		memcpy(DataItem.data, data, nDataSize);
	}

	CDataLocker locker(&m_Mutex);
	m_DataQueues.push_back(DataItem);
}
//�������� V
void CSocketDataQueue::post()
{
	// ��ʱ����
	if (!m_DataQueues.empty())
	{
		const tagSocketDataItem &DataItem = m_DataQueues.front(); //���ص�һ��Ԫ������
		CTCPSocket* pSocket = g_SocketMap[DataItem.nOnwer]; //
	}

	CDataLocker locker(&m_Mutex);
	while( !m_DataQueues.empty() )
	{
		const tagSocketDataItem &DataItem = m_DataQueues.front();
		CTCPSocket* pSocket = g_SocketMap[DataItem.nOnwer];
		if (pSocket == nullptr)
		{
			if (DataItem.data)
			{
				delete [] DataItem.data;
				if (m_DataQueues.size() > 0)
				{
					m_DataQueues.pop_front();
				}
				break;
			}
		}

		switch(DataItem.nCmd)
		{
		case CMD_DEALDAT_NORMAL_CLOSE:
			pSocket->CloseSocket(SHUT_REASON_NORMAL);
			break;

		case CMD_DEALDAT_ERROR:
			pSocket->OnSocketNotifyErr(DataItem.nDataSize);
			break;

		case CMD_DEALDAT_OK:
			pSocket->OnSocketNotifyRead(DataItem.data, DataItem.nDataSize);
			break;
		}

		if (DataItem.data)
		{
			delete [] DataItem.data;
			m_DataQueues.pop_front();
		}
	}
	return;
}

void CSocketDataQueue::resetData()
{
	//CDataLocker locker( &m_Mutex );
	while( !m_DataQueues.empty() )
	{
		tagSocketDataItem &DataItem = m_DataQueues.front();

		if (g_SocketMap[DataItem.nOnwer])
		{
			g_SocketMap[DataItem.nOnwer]->CloseSocket();
		}

		if ( DataItem.data )
		{
			delete [] DataItem.data;
		}

		m_DataQueues.pop_front();
	}

	Release();
}