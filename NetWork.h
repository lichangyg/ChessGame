#ifndef NET_WORK_H_
#define NET_WORK_H_
#define CC_PLATFORM_WIN32 1
#define CC_TARGET_PLATFORM 1
#if CC_PLATFORM_WIN32 == CC_TARGET_PLATFORM
// --win32
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

#else
// --linux
#include <stdlib.h> 
#include <errno.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> //inet_ntoa()函数的头文件
#define INVALID_SOCKET	-1

#endif
#include <stdio.h>
#include <iostream>
#include <string>

#define MAX_RECV_BUF_COUNT	1024*1024

class IOSocketData;

class NetWork
{
public:
	NetWork();
	virtual ~NetWork(void);
	static NetWork *getInstance();

	// 初始化网络
	void connection(const char *Ip,const int port);

	bool sendData(const char *sendData);

	void recvData();

	// 主动关闭网络
	void DisConenect();
private:
	void init();

	// 初始化网络配置
	bool initSocket();

	bool connectSocket();

	void destory();
private:
#if CC_PLATFORM_WIN32 == CC_TARGET_PLATFORM
	SOCKET	_socket; 
#else
	int		_socket;
#endif

	// 通用的网络设置数据
	std::string m_ip;
	int			m_port;

	// 是否连通状态


	static NetWork *m_instance;

};
#define gNetWork NetWork::getInstance()
#endif

