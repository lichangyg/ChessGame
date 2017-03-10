#include <iostream>
#include "NetWork.h"
using namespace std;

int main()
{
	gNetWork->connection("192.168.1.101", 9001);
	gNetWork->sendData("ddddd");
	getchar();
	return 1;
}