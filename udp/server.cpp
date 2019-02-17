#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

using namespace std;

class UdpServer
{
private:
	int sockfd;//套接字
	string ip;//IP地址
	int port;//端口号
public:
	UdpServer(string _ip, int _port)
		:ip(_ip)
		,port(_port)
	{
	}
	void InitServer()
	{
		sockfd = socket(AF_INET, SOCK_DGRAM, 0);//1.创建套接字
		if (sockfd<0)
		{
			cerr << "socket error" << endl;
			exit(2);
		}
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = inet_addr(ip.c_str());
		addr.sin_port = htons(port);
		int ret = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));//2.绑定端口号
		if (ret<0)
		{
			cerr << "bind error" << endl;
			exit(3);
		}
	}
	void RecvData(string &out, struct sockaddr_in &addr, socklen_t &len)
	{
		char buf[1024] = { 0 };
		ssize_t s = recvfrom(sockfd, buf, sizeof(buf)-1, 0, (struct sockaddr*)&addr, &len);//3.接收来自客户端的数据
		if (s>0)
		{
			buf[s] = 0;
			out = buf;
		}
		else
		{
			cerr << "recvfrom error" << endl;
			exit(4);
		}
	}
	void SendData(string &in, struct sockaddr_in &addr, socklen_t len)
	{
		ssize_t ret = sendto(sockfd, (char*)in.c_str(), in.size(), 0, (struct sockaddr*)&addr, len);//4.向客户端发送数据
		if (ret<0)
		{
			cerr << "sendto error" << endl;
			// cout<<strerror(errno)<<endl;
			exit(5);
		}
	}
	void StartServer()
	{
		string str;
		struct sockaddr_in addr;
		socklen_t len = 0;
		while (1)
		{
			len = sizeof(addr);
			RecvData(str, addr, len);
			str += " + UdpServer";
			cout << "client# " << str << endl;
			SendData(str, addr, len);
		}
	}
	~UdpServer()
	{
		close(sockfd);//5.关闭套接字描述符
	}
};
void Usage(string proc)
{
	cout << "Usage: " << proc << "ip port" << endl;
}
int main(int argc, char* argv[])//从命令行参数进行参数传递
{
	if (argc != 3)
	{
		Usage(argv[0]);
		exit(1);
	}
	string ip = argv[1];
	int port = atoi(argv[2]);
	UdpServer us(ip, port);//创建一个套接字的对象
	us.InitServer();//初始化服务器
	//daemon(0,0);
	us.StartServer();//启动服务器
	return 0;
}
