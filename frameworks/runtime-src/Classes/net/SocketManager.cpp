#include "SocketManager.h"
#include "util/LuaUtil.h"

SocketManager* SocketManager::m_instance = nullptr;
SocketManager::SocketManager()
{

}
SocketManager::~SocketManager(void)
{
	destory();
}
SocketManager *SocketManager::getInstance()
{
	if (!m_instance)
	{
		m_instance = new SocketManager();
	}
	return m_instance;
}

void SocketManager::destory()
{
	if (m_instance)
	{
		delete m_instance;
		m_instance = nullptr;
	}

	m_SocketDatas.clear();
}

void SocketManager::pushMessage(const SocketAction &action)
{
	m_SocketDatas.push_back(action);
}


void SocketManager::update(float dt)
{
	if (m_SocketDatas.empty())
	{
		return ;
	}

	auto data = *m_SocketDatas.begin();
	// 分发到LUA代码执行
	LuaUtil::getLuaBool("net/socketHandler","socketMsgHandler","is",data.m_protoCol,data.m_data);

	m_SocketDatas.erase(m_SocketDatas.begin());
}