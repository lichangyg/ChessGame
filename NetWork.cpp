#include "NetWork.h"
#include "IOSocketData.h"

NetWork* NetWork::m_instance = nullptr;
NetWork::NetWork():
_socket(INVALID_SOCKET)
{
	// 初始化socket
	initSocket();

	init();
}

void NetWork::init()
{
}


NetWork::~NetWork(void)
{
	destory();
}

bool NetWork::initSocket()
{
#if CC_PLATFORM_WIN32 == CC_TARGET_PLATFORM
	// 加载Win Socket  
	WORD wVersionRequested;  
	WSADATA wsaData;  
	int err;  

	wVersionRequested = MAKEWORD(1, 1);  

	err = WSAStartup(wVersionRequested, &wsaData);  
	if (err != 0)  
	{  
		/* Tell the user that we could not find a usable */  
		/* WinSock DLL.                                  */  
		return false;  
	}  

	/* Confirm that the WinSock DLL supports 2.2.*/  
	/* Note that if the DLL supports versions greater    */  
	/* than 2.2 in addition to 2.2, it will still return */  
	/* 2.2 in wVersion since that is the version we      */  
	/* requested.                                        */  

	if ( LOBYTE( wsaData.wVersion ) != 1 ||  
		HIBYTE( wsaData.wVersion ) != 1 )  
	{  
		/* Tell the user that we could not find a usable */  
		/* WinSock DLL.                                  */  
		WSACleanup();  
		return false;   
	} 
#endif
	return true;
}

NetWork* NetWork::getInstance()
{
	if (!m_instance)
	{
		m_instance = new NetWork();
	}
	return m_instance;
}

void NetWork::connection(const char *Ip,const int port)
{
#if CC_PLATFORM_WIN32 == CC_TARGET_PLATFORM
	if (Ip == m_ip.c_str() && port == m_port)
	{
		if (!_socket)
		{
			connectSocket();
		}
	}
	else
	{
		m_ip = Ip;
		m_port = port;

		closesocket(_socket);  

		_socket = INVALID_SOCKET;
		connectSocket();
	}
#else
	if (Ip == m_ip.c_str() && port == m_port)
	{
		if (!_socket)
		{
			connectSocket();
		}
	}
	else
	{
		m_ip = Ip;
		m_port = port;
		_socket = INVALID_SOCKET;
		connectSocket();
	}
#endif
}

bool NetWork::connectSocket()
{
#if CC_PLATFORM_WIN32 == CC_TARGET_PLATFORM
	if (INVALID_SOCKET != _socket)
	{
		return false;
	}
	_socket = socket(AF_INET,SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == _socket)
	{
		WSACleanup();  
		return false; 
	}

	// 连接服务器  
	SOCKADDR_IN addrSrv;  
	addrSrv.sin_addr.S_un.S_addr = inet_addr(m_ip.c_str());  
	addrSrv.sin_family = AF_INET;  
	addrSrv.sin_port = htons(m_port);  

	auto ret = connect(_socket,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	if (ret == INVALID_SOCKET)
	{
		DisConenect();
		return false;
	}
#else
	if (INVALID_SOCKET != _socket)
	{
		return false;
	}
	_socket = socket(AF_INET,SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == _socket)
	{ 
		return false; 
	}

	// 连接服务器  
	struct sockaddr_in server_addr;
	bzero(&server_addr,sizeof(server_addr)); // 初始化,置0 
	server_addr.sin_addr = *((struct in_addr *)m_ip.c_str());
	server_addr.sin_family = AF_INET;  
	server_addr.sin_port = htons(m_port);  

	auto ret = connect(_socket,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr));
	if (ret == INVALID_SOCKET)
	{
		DisConenect();
		return false;
	}
#endif
	return true;
}

bool NetWork::sendData(const char *sendData)
{
#if CC_PLATFORM_WIN32 == CC_TARGET_PLATFORM
	if (_socket == INVALID_SOCKET)
	{
		connectSocket();
		return false;
	}
	auto errCode = send(_socket,sendData,(int)strlen(sendData)+1,0); 
	if (SOCKET_ERROR == errCode)
	{
		return	false;
	}
#else
	if (_socket == INVALID_SOCKET)
	{
		connectSocket();
		return false;
	}
	auto errCode = send(_socket,sendData,(int)strlen(sendData)+1,0); 
	if (-1 == errCode)
	{
		CCLOG("NetWork::sendData error!!!!");
		return	false;
	}
#endif
	return true;
}

void NetWork::recvData()
{
#if CC_PLATFORM_WIN32 == CC_TARGET_PLATFORM
	char recvBuf[MAX_RECV_BUF_COUNT];
	auto errCode = recv(_socket,recvBuf,MAX_RECV_BUF_COUNT,0); 
	if (errCode == SOCKET_ERROR)
	{
		return ;
	}

#else
	char recvBuf[MAX_RECV_BUF_COUNT];
	auto errCode = recv(_socket,recvBuf,MAX_RECV_BUF_COUNT,0); 
	if (errCode == -1)
	{
		return ;
	}
	
#endif

}

// 销毁
void NetWork::DisConenect()
{
#if CC_PLATFORM_WIN32 == CC_TARGET_PLATFORM
	if (_socket != INVALID_SOCKET)
	{
		closesocket(_socket);
	}

#else
	// close(_socket)
#endif
	_socket = INVALID_SOCKET;
	m_ip = "";
	m_port = 0;
}

void NetWork::destory()
{
	DisConenect();
	if (m_instance)
	{
		delete m_instance;
		m_instance = nullptr;
	}

#if CC_PLATFORM_WIN32 == CC_TARGET_PLATFORM
	WSACleanup();
#else
#endif

}