#include "NetWork.h"
#include "IOSocketData.h"

NetWork* NetWork::m_instance = nullptr;
NetWork::NetWork():
_socket(INVALID_SOCKET),
m_data(NULL)
{
	// 初始化socket
	initSocket();

	init();
}

void NetWork::init()
{
	m_data = new IOSocketData();
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
#else
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
}

bool NetWork::connectSocket()
{
	if (INVALID_SOCKET != _socket)
	{
		return false;
	}
	_socket = socket(AF_INET,SOCK_STREAM,0);
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

	connect(_socket,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	return true;
}

bool NetWork::sendData(const char *sendData)
{
	if (_socket == INVALID_SOCKET)
	{
		connectSocket();
		return false;
	}
	auto errCode = send(_socket,sendData,(int)strlen(sendData)+1,0); 
	if (SOCKET_ERROR == errCode)
	{
		std::cout << "NetWork::sendData error!!!!" << std::endl;
		return	false;
	}

	return true;
}

void NetWork::recvData()
{
	char recvBuf[MAX_RECV_BUF_COUNT];
	auto errCode = recv(_socket,recvBuf,MAX_RECV_BUF_COUNT,0); 
	if (errCode == SOCKET_ERROR)
	{
		std::cout << "NetWork::recvData error!!!!" << std::endl;
		return ;
	}

	m_data->setCurPackageLenght(errCode);
	m_data->pushMessage(recvBuf);
}

// 销毁
void NetWork::close()
{
#if CC_PLATFORM_WIN32 == CC_TARGET_PLATFORM
	closesocket(_socket);  
	WSACleanup();  
	_socket = INVALID_SOCKET;
#else
#endif

}

void NetWork::destory()
{
	if (m_instance)
	{
		delete m_instance;
		m_instance = nullptr;
	}

	if (m_data)
	{
		delete m_data;
		m_data = nullptr;
	}
}