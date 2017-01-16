#ifndef NET_IOSOCKETDATA_H_
#define NET_IOSOCKETDATA_H_
#include <vector>

class IOSocketData
{
public:
	IOSocketData();
	virtual ~IOSocketData(void);
public:
	void pushMessage(const char *data);

	// 是否已经接收整包完成
	bool IsRecvEnd()const;

	// 处理接收的数据
	void onData(const char *data, size_t count);

	// 设置当前的包的数据长度
	void setCurPackageLenght(const size_t lenght){m_curPacketageLenght += lenght;}

private:
	void clear();
protected:
	std::vector<std::string> m_data;

	// 包协议长度
	size_t m_lenght;

	// 包的协议号
	int m_protoCol;

	// 是否接收整包完成
	bool m_IsRecvEnd;

	// 当前接收到的包数据长度
	size_t m_curPacketageLenght;

	// 分包的数量
	size_t m_count;
};


#endif //NET_WORK_H_