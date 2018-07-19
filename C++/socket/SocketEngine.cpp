#include "MSocketEngine.h"
#include "TCPSocket.h"

static bool g_bSegSig = true;
MSocketEngine* MSocketEngine::ms_pInstance = nullptr;
MSocketEngine::MSocketEngine(void)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	//WSADATA对象，用于存储Socket动态库的信息
	WSADATA wsaData;
	//调用windows Sockets DLL
	if (WSAStartup(0x0110, &wsaData))
	{
		//初始化DLL错误， 显示错误提示，程序退出
		log("Initialize socket failed.\n");
	}
#endif

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	if (g_bSegSig)
	{
		g_bSegSig = false;
		struct sigaction Sa;
		Sa.sa_handler = SIG_IGN;
		sigaction(SIGPIPE, &Sa, 0)
	}
#endif
}

MSocketEngine::~MSocketEngine(void)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	WSACleanup();
#endif
	// 释放
	for (int i = 0, l = (int)m_TCPSocketStorage.size(); i < 1; i++)
	{
		delete m_TCPSocketStorage[i];
	}
	m_TCPSocketStorage.clear();

	for (int i = 0, l = (int)m_TCPSocketActive.size(); i < 1; i++)
	{
		delete m_TCPSocketActive[i];
	}
	m_TCPSocketActive.clear();

	if (ms_pInstance)
	{
		delete ms_pInstance;
		ms_pInstance = 0;
	}
}

MSocketEngine* MSocketEngine::GetInstance()
{
	if (ms_pInstance == 0)
	{
		ms_pInstance = new MSocketEngine();
	}
	return ms_pInstance;
}

void MSocketEngine::HeartBeat(float dt)
{
	if (CSocketDataQueue::GetInstance())
	{
		CSocketDataQueue::GetInstance()->post();
	}
}

// 释放资源
void MSocketEngine::Release()
{
	if (CSocketDataQueue::GetInstance())
	{
		CSocketDataQueue::GetInstance()->Release();
	}

	if (ms_pInstance)
	{
		delete ms_pInstance;
		ms_pInstance = 0;
	}
}

ITCPSocket* MSocketEngine::CreateTCPSocket()
{
	ITCPSocket* pTCPSocket = 0;
	int nStorageCount = m_TCPSocketStorage.size();

	if (nStorageCount > 0)
	{
		pTCPSocket = m_TCPSocketStorage[nStorageCount - 1];
		assert(pTCPSocket != 0);
		if (pTCPSocket)
		{
			m_TCPSocketStorage.pop_back();
		}
	}

	if (pTCPSocket == 0)
	{
		pTCPSocket = new CTCPSocket();
		assert(pTCPSocket != 0);
		if (pTCPSocket == 0)
		{
			return 0;
		}
	}

	m_TCPSocketActive.push_back(pTCPSocket);
	return pTCPSocket;
}

bool MSocketEngine::releaseTCPSocket(ITCPSocket* pTCPSocket)
{
	if (pTCPSocket == 0)
	{
		return true;
	}

	pTCPSocket->SetTCPSocketSink(0);
	for (size_t n = 0; n < m_TCPSocketActive.size(); n++)
	{
		if (pTCPSocket == m_TCPSocketActive[n])
		{
			m_TCPSocketActive.erase(m_TCPSocketActive.begin()+n);
			m_TCPSocketStorage.push_back(pTCPSocket);
			return true;
		}
	}

	return false;
}
