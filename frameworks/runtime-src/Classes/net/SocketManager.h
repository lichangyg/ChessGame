#ifndef NET_SOCKET_MANAGER_H_
#define NET_SOCKET_MANAGER_H_
#include <iostream>
#include <vector>

struct SocketAction
{
	int m_protoCol;
	std::string m_data;
};

class SocketManager
{
public:
	SocketManager();
	virtual ~SocketManager(void);
	static SocketManager *getInstance();

	void pushMessage(const SocketAction &action);

	void destory();

	// 主线程定时执行
	void update(float dt);

protected:
	std::vector<SocketAction> m_SocketDatas;

private:
	static SocketManager *m_instance;
};

#define gSocketMgr SocketManager::getInstance()
#endif //NET_WORK_H_