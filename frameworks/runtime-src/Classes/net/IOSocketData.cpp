#include "IOSocketData.h"

#if CC_PLATFORM_WIN32 == CC_TARGET_PLATFORM
#include <WinSock2.h>
#else
#endif

IOSocketData::IOSocketData()
{
	clear();
}
IOSocketData::~IOSocketData(void)
{

}




void IOSocketData::pushMessage(const char *data)
{
	m_data.push_back(data);

	if (m_IsRecvEnd)
	{
		onData(data,0);
	}
	else
	{
		++m_count;
		onData(NULL,m_count);
	}
}

// 是否已经接收整包完成
bool IOSocketData::IsRecvEnd()const
{
	return m_IsRecvEnd;
}

// 处理接收的数据
void IOSocketData::onData(const char *data, size_t count)
{
	if (count == 0)
	{
		// 消息长度
		memcpy(&m_lenght, data, 4);
		// 大小端字节序转换
		m_lenght = htonl(m_lenght);
		// 协议号
		memcpy(&m_protoCol, data + 4, 4);
		// 大小端字节序转换
		m_protoCol = htonl(m_protoCol);
	}


	// 处理接收到的只是分包的情况
	if (m_curPacketageLenght < m_lenght)
	{
		m_IsRecvEnd = false;
		return ;
	}

	// 处理接收完整的包的情况
	std::string actionData(*m_data.begin());
	// 取真实的数据
	actionData.substr(8);
	for (int i = 1; i <= count; ++i)
	{
		// 从第一个包中的数据情况取出数据
		actionData.append(m_data[i]);
	}

	// 分发网络数据到主线程进行处理

	// 处理完数据
	clear();
}

void IOSocketData::clear()
{
	m_lenght = 0;
	m_curPacketageLenght = 0;
	m_IsRecvEnd = true;
	m_count = 0;
	m_protoCol = 0;
}