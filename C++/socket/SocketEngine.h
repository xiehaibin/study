#pragma once

#include "cocos2d.h"
USING_NS_CC;

#include "ISocket.h"

typedef std::vector<ITCPSocket*>TCPSocketVector;
class MSocketEngine
{
protected :
	static MSocketEngine* ms_pInstance;

private :
	TCPSocketVector     m_TCPSocketActive;   //
	TCPSocketVector     m_TCPSocketStorage;  //

public:
	MSocketEngine(void);
	~MSocketEngine(void);

public :
	static MSocketEngine *GetInstance();
	void HeartBeat(float dt);
	bool releaseTCPSocket(ITCPSocket* pCPSocket);
	void Release();

public :
	// ´´½¨TCPSocket
	ITCPSocket* CreateTCPSocket();
};

