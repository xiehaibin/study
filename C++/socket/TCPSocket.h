#pragma once

#include "cocos2d.h"
USING_NS_CC;

#include "ISocket.h"
#include <iostream>

#ifdef WIN32
#include <winsock2.h>
#pragma comment(lib,"WS2_32.lib")
#define LHS_EAGAIN        WSAEWOULDBLOCK
#define LHS_EWGULDBLOCK   WSAEWOULDBLOCK
#define INVABBR_NGNE      INADDR_NONE
#else
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/times.h>

typedef int				  SOCKET;
#define INVALID_SOCKET	  (SOCKET)(~0)
#define INVALID_NONE	  0xffffffff
#define SOCKET_ERROR	  (-1)
#define LHS_EAGAIN        EAGAIN        // �˲��������߳������� ��socketΪ����������
#define LHS_EWOULDBLOCK   EWOULDBLOCKX  // ��ʱ������ 
#endif

#include "SocketDataQueue.h"

#define SOCKET_TIME_OUT 1800

///////////////////////////////////////////////////
//��
class CDataLocker
{
	std::mutex *_pMutex;
public :
	CDataLocker(std::mutex* aMutex) : _pMutex(aMutex)
	{
		if (_pMutex)
		{
			_pMutex->lock();
		}
	}
	~CDataLocker()
	{
		if (_pMutex)
		{
			_pMutex->unlock();
		}
	}
};

/////////////////////////////////////////////////////////////////////////////
// SocketItem
class CTCPSocket : public ITCPSocket
{
protected :
	ITCPSocketSink         *m_pSocketSink;
	int                     m_nSocketIdx;

	SOCKET                  m_Socket;

	unsigned char           m_cbShutReason;
	unsigned char           m_cbSocketStatus;          // socket״̬
	unsigned char           m_cbEncryptType;

	// ��������
private :
	unsigned short          m_wRecvLen;
	unsigned char           m_cbBufRecieve[MAX_TCP_BUF]; // ���ܻ���

	std::mutex              m_Mutex;
	std::thread             *m_pThread;

	SocketDataQueue*        m_pSocketDataQueue;

	//��ʱ
public :
	int m_nSocketTimeOut;
	int SocketTimeOut() const { return m_nSocketTimeOut; }
	void ChangeSocketTimeOut() { m_nSocketTimeOut--; }

public :
	CTCPSocket(void);
	virtual ~CTCPSocket(void);

	/////////////////////////// ����ӿ� ///////////////////////////
	// ���ýӿ�
public :
	// ���ýӿ�
	virtual bool SetTCPSocketSink(ITCPSocketSink* pIUnknownEx);

	// ��Ϣ�ӿ�
public :
	// ����״̬
	virtual unsigned char GetSocketStatus() {return m_cbSocketStatus;}
	bool IsAlive() const;
	int GetSocket() const;
	bool IsBusy();

	//�����ӿ�
public :
	//10-4
	// �ر�����
	virtual void CloseSocket();
	virtual void CloseSocket(unsigned char cbReason);
	// ���Ӳ��� V
	virtual unsigned char Connect(const char* pszServerIP, unsigned short wPort);
	// ���ͺ��� V
	virtual unsigned short SendData(ByteBuffer& buffer);
	
public :
	// 
	void onSendThreadStarted(void);
	// �����̺߳���
	void onSendThreadLoop(void);
	// ����֪ͨ V
	bool OnSocketNotifyErr(int nErrCode);
	// ����Ͷ�� V
	bool OnSocketNotifyRead(void* data, int nDataSize);

	// ��������
protected:
	//���ӳ��
	unsigned short SeedRandMap(unsigned short wSeed);

	// ���շ��������� V
	static int socket_recv(int sSocket, char* data, int nSize);
	// �������ݵ������� V
	static int socket_send(int sSocket, const char* data, int nSize);
	// �رսӿ� V
	static void socket_close(int s);
	// ������Ϣ V
	static int socket_error();
	// sleep V
	static void socket_sleep(unsigned int nMillions);
	// TickCount
	unsigned int getTickCount();

	// ���ݴ���
public :
	// �߳����ݽ���
	static void* RecvData(void* p);
	void recvData();
};

///////////////////////////////////////////////////////
// ���ݶ���
class CSocketDataQueue
{
protected:
	static CSocketDataQueue* msInstance;

	// ��������
	struct tagSocketDataItem
	{
		unsigned    nOnwer;   // ����ӵ����
		int         nCmd;     // ����
		char        *data;    // ����
		int         nDataSize;// ���ݴ�С
	};

	std::list<tagSocketDataItem> m_DataQueues;
	std::mutex                   m_Mutex;

	std::list<tagSocketDataItem> m_SendDataQueues;        // ���Ͷ���
	std::mutex                   m_SendMutex;
	std::thread*                 m_SendThreadInstance;    // �����߳�

private :
	CSocketDataQueue()
	{
		msInstance = 0;
	}

	~CSocketDataQueue()
	{
		CDataLocker locler(& m_Mutex);

		while(!m_DataQueues.empty())
		{
			tagSocketDataItem &DataItem = m_DataQueues.front();
			if (DataItem.data)
			{
				delete [] DataItem.data;
			}
			m_DataQueues.pop_front();
		}
	}

public :
	// ����
	static CSocketDataQueue* GetInstance()
	{
		if (msInstance == 0)
		{
			msInstance = new CSocketDataQueue();
		}
		return msInstance;
	}

	// �ͷ�
	static void Release()
	{
		if (msInstance)
		{
			delete msInstance;
			msInstance = 0;
		}
	}

public :
	// ������� V
	void push(unsigned int nOwner, int nCmd, char* data, int nDataSize);
	// Ͷ������ V
	void post();
	// �ͷ����� V
	void resetData();
};
