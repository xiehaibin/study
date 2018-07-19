#pragma once
#pragma pack(1)

#include "ByteBuffer.h"

#define MAX_TCP_BUF              16384

//关闭原因
#define SHUT_REASON_NORMAL       0
#define SHUT_REASON_INSIDE       1
#define SHUT_REASON_REMOTE       2
#define SHUT_REASON_TIME_OUT     3
#define SHUT_REASON_EXCEPTION    4

// 链接状态
#define SOCKET_STATUS_IDLE       0
#define SOCKET_STATUS_WAIT       1
#define SOCKET_STATUS_CONNECT    2

#define CONNECT_SUCCESS          0
#define CONNECT_FAILURE          1
#define CONNECT_EXCEPTION        2
//

/////////////////////////////////////////////////////
//网络命令
struct TCP_Command
{
	unsigned short           wMainCmdID;           //主命令码
	unsigned short           wSubCmdID;            //子命令码
};

//网络内核
struct TCP_Info
{
	unsigned char            cbDataKind;           //版本标识
	unsigned char            cbCheckCode;          //校验字段 没用
	unsigned char            wPacketSize;          //数据大小
};

//网络包头
struct TCP_Head
{
	TCP_Info                 TCPInfo;             //基础结构
	TCP_Command              CommandInfo;         //命令信息
};


struct ITCPSocketSink
{
	//网络事件
public:
	//连接事件
	virtual bool OnEventTCPSocketLink(unsigned short vSocketID, int nErrorCode) = 0;
	//关闭事件
	virtual bool OnEventTCPSocketShut(unsigned short vSocketID, unsigned char cbShutReason) = 0;
	//读取事件
	virtual bool OnEventTCPSocketRead(unsigned short vSocketID, TCP_Command Command, void* pData, unsigned short vDataSize) = 0;
};

//网络接口
class ITCPSocket
{
	//配置接口
public :
	// 设置接口
	virtual bool SetTCPSocketSink(ITCPSocketSink* pIUnknownEx) = 0;

	//信息接口
public :
	//网络状态
	virtual unsigned char GetSocketStatus() = 0;

	//操作接口
public :
	//关闭连接
	virtual void CloseSocket() = 0;
	virtual void CloseSocket(unsigned char cbReason) = 0;
	//连接操作
	virtual unsigned char Connect(const char* pszServerIP, unsigned short wPort) = 0;
	//发送函数
	virtual unsigned short SendData(ByteBuffer& buffer) = 0;
};
#pragma pack()


