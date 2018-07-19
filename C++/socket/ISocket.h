#pragma once
#pragma pack(1)

#include "ByteBuffer.h"

#define MAX_TCP_BUF              16384

//�ر�ԭ��
#define SHUT_REASON_NORMAL       0
#define SHUT_REASON_INSIDE       1
#define SHUT_REASON_REMOTE       2
#define SHUT_REASON_TIME_OUT     3
#define SHUT_REASON_EXCEPTION    4

// ����״̬
#define SOCKET_STATUS_IDLE       0
#define SOCKET_STATUS_WAIT       1
#define SOCKET_STATUS_CONNECT    2

#define CONNECT_SUCCESS          0
#define CONNECT_FAILURE          1
#define CONNECT_EXCEPTION        2
//

/////////////////////////////////////////////////////
//��������
struct TCP_Command
{
	unsigned short           wMainCmdID;           //��������
	unsigned short           wSubCmdID;            //��������
};

//�����ں�
struct TCP_Info
{
	unsigned char            cbDataKind;           //�汾��ʶ
	unsigned char            cbCheckCode;          //У���ֶ� û��
	unsigned char            wPacketSize;          //���ݴ�С
};

//�����ͷ
struct TCP_Head
{
	TCP_Info                 TCPInfo;             //�����ṹ
	TCP_Command              CommandInfo;         //������Ϣ
};


struct ITCPSocketSink
{
	//�����¼�
public:
	//�����¼�
	virtual bool OnEventTCPSocketLink(unsigned short vSocketID, int nErrorCode) = 0;
	//�ر��¼�
	virtual bool OnEventTCPSocketShut(unsigned short vSocketID, unsigned char cbShutReason) = 0;
	//��ȡ�¼�
	virtual bool OnEventTCPSocketRead(unsigned short vSocketID, TCP_Command Command, void* pData, unsigned short vDataSize) = 0;
};

//����ӿ�
class ITCPSocket
{
	//���ýӿ�
public :
	// ���ýӿ�
	virtual bool SetTCPSocketSink(ITCPSocketSink* pIUnknownEx) = 0;

	//��Ϣ�ӿ�
public :
	//����״̬
	virtual unsigned char GetSocketStatus() = 0;

	//�����ӿ�
public :
	//�ر�����
	virtual void CloseSocket() = 0;
	virtual void CloseSocket(unsigned char cbReason) = 0;
	//���Ӳ���
	virtual unsigned char Connect(const char* pszServerIP, unsigned short wPort) = 0;
	//���ͺ���
	virtual unsigned short SendData(ByteBuffer& buffer) = 0;
};
#pragma pack()


