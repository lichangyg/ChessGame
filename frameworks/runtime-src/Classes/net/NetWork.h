#ifndef NET_WORK_H_
#define NET_WORK_H_


#if CC_PLATFORM_WIN32 == CC_TARGET_PLATFORM
#include <WinSock2.h>
#else
#endif
#include <stdio.h>
#include <iostream>
#include <string>

#define MAX_RECV_BUF_COUNT	1024*1024

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
	void close();
private:
	// 初始化网络配置
	bool initSocket();

	bool connectSocket();

	void destory();
private:
#if CC_PLATFORM_WIN32 == CC_TARGET_PLATFORM
	SOCKET	_socket; 
#else
#endif

	// 通用的网络设置数据
	std::string m_ip;
	int			m_port;

	static NetWork *m_instance;
};


#define gNetWork NetWork::getInstance()


#endif //NET_WORK_H_