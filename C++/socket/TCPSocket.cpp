#include "TCPSocket.h"

using namespace std;

#define _TCP_RESET_DATA_

////////////////////////////////////////////////////////////////////////
#define safeDel(pData) { try { if (pData){delete pData; pData = 0;}} catch(...){ } pData = 0; }
////////////////////////////////////////////////////////////////////////

// 数据处理命令
#define CMD_DEALDAT_NORMAL_CLOSE          0                   // 非提示关闭
#define CMD_DEALDAT_ERROR                 1                   // 错误处理
#define CMD_DEALDAT_OK                    2                   // 数据正确
/////////////////////////////////////////////////////////////////////////

// 数据类型
#define DK_MAPPED                        0x01                // 映射类型
#define DK_ENCRYPT                       0x02                // 加密类型 
#define DK_COMPRESS                      0x04                // 压缩类型 

// 内核命令
#define MDM_KN_COMMAND                   0                   // 内核命令
#define SUB_KN_DETECT_SOCKET             1                   // 检测命令
#define SUB_KN_VALIDATE_SOCKET           2                   // 验证命令 


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

// 设置接口
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

// 连接服务 V
unsigned char CTCPSocket::Connect(const char* url, unsigned short wPort)
{
	hostent* hp = gethostbyname(url);

	// 通知失败
	if (hp == 0)
	{
		log("get host failed\n");
		return CONNECT_FAILURE;
	}

	sockaddr_in local;
	memset(&local, 0, sizeof(local));
	// 连接的服务器IP地址
	memcpy((char*)&local.sin_addr, hp->h_addr, hp->h_length);

	// 连接的协议类型
	local.sin_family = hp->h_addrtype;
	// 连接的服务器端口
	local.sin_port = htons(wPort);

	log("socket connect...！！！ ip=%s port=%d\n", url, wPort);

	// 链接服务器
	try
	{
		// 创建socket
		int nRet = SOCKET_ERROR;

		// 确保链接成功
		for (int n = 0; n < 100; n++)
		{
			m_Socket = socket(AF_INET, SOCK_STREAM, 0);

			// 通知失败
			if (m_Socket == INVALID_SOCKET)
			{
				//创建套接字失败!
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

	// 创建线程
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

// 状态获取
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
	// WSAGetLastError是指该函数返回上次发生的网络错误.
	log("IsBusy %w", WSAGetLastError());
	return WSAGetLastError() == WSAEWOULDBLOCK;
#else
	int err = errno;
	return err == EAGAIN || err == EINPROGRESS;
#endif
}

// 获取Socket
int CTCPSocket::GetSocket() const
{
	return (int)m_Socket;
}
// 接收数据 V
int CTCPSocket::socket_recv(int sSocket, char* data, int nSize)
{
	unsigned int nFlage = 0;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	nFlage = MSG_NOSIGNAL;
#endif
	return recv(sSocket, data, nSize, nFlage);
}
//发送数据
int CTCPSocket::socket_send(int sSocket, const char* data, int nSize)
{
	unsigned int nFlags = 0;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	nFlags = MSG_NOSIGNAL;
#endif
	return send(sSocket, data, nSize, nFlags);
}
// 关闭
void CTCPSocket::socket_close(int s)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	shutdown(s, SD_BOTH);
	closesocket(s);
#else
	close(s);
#endif
}
// socket 错误
int CTCPSocket::socket_error()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	/*返回上次发生的网络错误.当一特定的Windows Sockets API函数指出一个错误已经发生,该函数就应调用来获得对应的错误代码.*/
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

// 数据发送
unsigned short CTCPSocket::SendData(ByteBuffer& buffer)
{
	if (!IsAlive())
	{
		return false;
	}
	/*
	// 构造数据
	unsigned char cbDataBuf[MAX_TCP_BUF] = {0};
	memset(cbDataBuf, 0, sizeof(cbDataBuf));
	
	// 设置包信息
	int nPackSize = sizeof(TCP_Head) + nDataSize;
	// 数据包大小
	CVConvt::SetValue_VORD(cbDataBuf, 2, nPackSize); //0：版本标识 1：校验字段  2：数据大小
	// 主命令
	CVConvt::SetValue_VORD(cbDataBuf, 4, wMainCmdID);
	// 子命令
	CVConvt::SetValue_VORD(cbDataBuf, 6, wSubCmdID);
	// 赋值
	if (nDataSize > 0)
	{
		memcpy(&cbDataBuf[sizeof(TCP_Head)], data, nDataSize);
	}
	
	// 加密数据
	nPackSize = EncryptBuffer(cbDataBuf, nPackSize, sizeof(cbDataBuf));
	*/
	// 发送数据
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

// 发送线程函数
void CTCPSocket::onSendThreadLoop(void)
{

}

// 数据接收 V
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
			//打印错误信息
			log("recv err!%d\n", nErrCode);
			// 申请网络
			if (nErrCode == 10004L) //WSAEINTR
			{
				break;
			}
			// 超时操作
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

// 数据接收 V
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
			//打印错误信息
			log("recv err:%d\n", nErrCode);
			// 中断网络
			if (nErrCode == 10004L)
			{
				break;
			}
			// 超时操作
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
// 错误
bool CTCPSocket::OnSocketNotifyErr(int nErrCode)
{
	log("shut down Code %d", nErrCode);
	// CloseSocket(SHUT_REASON_EXCEPTION)
	return true;
}
// 数据投递 V
bool CTCPSocket::OnSocketNotifyRead(void* data, int nDataSize)
{
	if (m_pSocketSink == NULL)
	{
		return false;
	}

	// 解析数据
	memcpy(&m_cbBufRecieve[m_wRecvLen], data, nDataSize);
	// 接收攻度增加
	m_wRecvLen += nDataSize;
	m_nSocketTimeOut = SOCKET_TIME_OUT;

	// 变量定义
	unsigned short wPacketSize = 0;
	unsigned char  cbDataBuffer[MAX_TCP_BUF] = {};
	unsigned short wUnpackIndex = 0;
	try
	{
		while((m_wRecvLen - wUnpackIndex) >= sizeof(TCP_Head)) // 大于包头
		{
			wPacketSize = CVConvt::GetValue_WORD(m_cbBufRecieve, 2); //数据长度（包括包头的）
			unsigned char cbDataKind = m_cbBufRecieve[0]; // 版本标识
			assert(cbDataKind == m_cbEncryptType); //加密类型 
			assert(wPacketSize <= MAX_TCP_BUF);
			if (cbDataKind != m_cbEncryptType)
			{
				log("只支持映射加密");
				throw("只支持映射加密");
			}

			if (wPacketSize > MAX_TCP_BUF)
			{
				log("数据包太大 %d", wPacketSize);
				throw("数据包太大");
			}

			if (m_wRecvLen < wPacketSize)
			{
				return false;
			}

			/**
			* recv返回的长度>=一个包长度，所以读完一个移到下一个包位置memmove
			*/
			// 拷贝数据
			memcpy(cbDataBuffer, m_cbBufRecieve, wPacketSize);
			m_wRecvLen -= wPacketSize; //
			memmove(m_cbBufRecieve, m_cbBufRecieve + wPacketSize, m_wRecvLen); //m_cbBufRecieve是除包头以外的数据

			//解密数据
			unsigned short wRealySize = CrevasseBuffer(cbDataBuffer, wPacketSize);
			// assert(wPealySize >= sizeof(TCP_Head));

			if (wRealySize < sizeof(TCP_Head))
			{
				CloseSocket(SHUT_REASON_NORMAL);

				// 关闭所有的socket
				resetAllSocket();
				break;
			}

			// 解释数据
			unsigned short wDataSize = wRealySize - sizeof(TCP_Head);  //数据长度
			void* pDataBuffer = cbDataBuffer + sizeof(TCP_Head);       //指针移到数据起始位置

			TCP_Command Command;
			Command.wMainCmdID = CVConvt::GetValue_WORD(cbDataBuffer, 4);  // 主命令码
			Command.wSubCmdID = CVConvt::GetValue_WORD(cbDataBuffer, 6);   // 子命令码
			//((TCP_Head*)cbDataBuffer)->CommandInfo;

			// 内核命令 心跳包的样子
			if (Command.wMainCmdID == MDM_KN_COMMAND)
			{
				switch (Command.wSubCmdID)
				{
				case SUB_KN_DETECT_SOCKET:  // 网络检测
					// 发送数据
					SendData(MDM_KN_COMMAND, SUB_KN_DETECT_SOCKET);
					break;
				default:
					break;
				}
				continue;
			}
			
			// 处理数据
			bool bSuccess = m_pSocketSink->OnEventTCPSocketRead((int)m_Socket, Command, pDataBuffer, wDataSize);
			if (bSuccess == false)
			{
				log("网络数据包处理失败 %d-%d", Command.wMainCmdID, Command.wSubCmdID);
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
// 压缩数据 V
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
//处理数据 V
void CSocketDataQueue::post()
{
	// 超时处理
	if (!m_DataQueues.empty())
	{
		const tagSocketDataItem &DataItem = m_DataQueues.front(); //返回第一个元素引用
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