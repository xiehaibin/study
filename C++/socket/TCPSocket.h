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
#define LHS_EAGAIN        EAGAIN        // 此操作会让线程阻塞， 但socket为不可阻塞的
#define LHS_EWOULDBLOCK   EWOULDBLOCKX  // 暂时不可用 
#endif

#include "SocketDataQueue.h"

#define SOCKET_TIME_OUT 1800

///////////////////////////////////////////////////
//锁
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
	unsigned char           m_cbSocketStatus;          // socket状态
	unsigned char           m_cbEncryptType;

	// 加密数据
private :
	unsigned short          m_wRecvLen;
	unsigned char           m_cbBufRecieve[MAX_TCP_BUF]; // 接受缓冲

	std::mutex              m_Mutex;
	std::thread             *m_pThread;

	SocketDataQueue*        m_pSocketDataQueue;

	//超时
public :
	int m_nSocketTimeOut;
	int SocketTimeOut() const { return m_nSocketTimeOut; }
	void ChangeSocketTimeOut() { m_nSocketTimeOut--; }

public :
	CTCPSocket(void);
	virtual ~CTCPSocket(void);

	/////////////////////////// 网络接口 ///////////////////////////
	// 配置接口
public :
	// 设置接口
	virtual bool SetTCPSocketSink(ITCPSocketSink* pIUnknownEx);

	// 信息接口
public :
	// 网络状态
	virtual unsigned char GetSocketStatus() {return m_cbSocketStatus;}
	bool IsAlive() const;
	int GetSocket() const;
	bool IsBusy();

	//操作接口
public :
	//10-4
	// 关闭连接
	virtual void CloseSocket();
	virtual void CloseSocket(unsigned char cbReason);
	// 连接操作 V
	virtual unsigned char Connect(const char* pszServerIP, unsigned short wPort);
	// 发送函数 V
	virtual unsigned short SendData(ByteBuffer& buffer);
	
public :
	// 
	void onSendThreadStarted(void);
	// 发送线程函数
	void onSendThreadLoop(void);
	// 错误通知 V
	bool OnSocketNotifyErr(int nErrCode);
	// 数据投递 V
	bool OnSocketNotifyRead(void* data, int nDataSize);

	// 辅助函数
protected:
	//随机映射
	unsigned short SeedRandMap(unsigned short wSeed);

	// 接收服务器数据 V
	static int socket_recv(int sSocket, char* data, int nSize);
	// 发送数据到服务器 V
	static int socket_send(int sSocket, const char* data, int nSize);
	// 关闭接口 V
	static void socket_close(int s);
	// 错误信息 V
	static int socket_error();
	// sleep V
	static void socket_sleep(unsigned int nMillions);
	// TickCount
	unsigned int getTickCount();

	// 数据处理
public :
	// 线程数据接收
	static void* RecvData(void* p);
	void recvData();
};

///////////////////////////////////////////////////////
// 数据队列
class CSocketDataQueue
{
protected:
	static CSocketDataQueue* msInstance;

	// 数据子项
	struct tagSocketDataItem
	{
		unsigned    nOnwer;   // 数据拥有者
		int         nCmd;     // 命令
		char        *data;    // 数据
		int         nDataSize;// 数据大小
	};

	std::list<tagSocketDataItem> m_DataQueues;
	std::mutex                   m_Mutex;

	std::list<tagSocketDataItem> m_SendDataQueues;        // 发送队列
	std::mutex                   m_SendMutex;
	std::thread*                 m_SendThreadInstance;    // 发送线程

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
	// 单例
	static CSocketDataQueue* GetInstance()
	{
		if (msInstance == 0)
		{
			msInstance = new CSocketDataQueue();
		}
		return msInstance;
	}

	// 释放
	static void Release()
	{
		if (msInstance)
		{
			delete msInstance;
			msInstance = 0;
		}
	}

public :
	// 添加数据 V
	void push(unsigned int nOwner, int nCmd, char* data, int nDataSize);
	// 投递数据 V
	void post();
	// 释放数据 V
	void resetData();
};
