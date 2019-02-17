#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

class UdpClient
{
private:
	int sockfd;
	string server_ip;
	int server_port;
public:
	UdpClient(string _ip, int _port)
		:server_ip(_ip)
		, server_port(_port)
	{
	}
	void InitClient()
	{
		sockfd = socket(AF_INET, SOCK_DGRAM, 0);//1.创建套接字
		if (sockfd<0)
		{
			cerr << "socket error" << endl;
			exit(2);
		}
	}
	void RecvData(string &out)
	{
		struct sockaddr_in addr;
		char buf[1024] = { 0 };
		socklen_t len = sizeof(addr);
		//cout <<"recv_1: "<< ntohs(addr.sin_port) << endl;
		ssize_t s = recvfrom(sockfd, buf, sizeof(buf)-1, 0, (struct sockaddr*)&addr, &len);//2.接收数据
		//cout <<"recv_2: "<< ntohs(addr.sin_port) << endl;
		// addr.sin_port=htons(server_port);
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
	void SendData(string &in)
	{
		struct sockaddr_in addr;
		addr.sin_family = AF_INET;
		addr.sin_addr.s_addr = inet_addr(server_ip.c_str());
		addr.sin_port = htons(server_port);

		//cout <<"send_1: "<< ntohs(addr.sin_port) << endl;
		int ret = sendto(sockfd, in.c_str(), in.size(), 0, (struct sockaddr*)&addr, sizeof(addr));//3.发送数据
		//cout <<"send_2: "<< ntohs(addr.sin_port) << endl;
		// cout << ntohs(addr.sin_port) << endl;
		if (ret<0)
		{
			cerr << "sendto error" << endl;
			exit(5);
		}
	}
	void StartClient()
	{
		string str;
		string out;
		while (1)
		{
			cout << "Please Enter# ";
			cin >> str;
			SendData(str);
			RecvData(out);

			cout << "server echo# " << out << endl;
		}
	}
	~UdpClient()
	{
		close(sockfd);//4.关闭套接字描述符
	}
};
void Usage(string proc)
{
	cout << "Usage: " << proc << "server_ip server_port" << endl;
}
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		Usage(argv[0]);
		exit(1);
	}
	string ip = argv[1];
	int port = atoi(argv[2]);
	UdpClient uc(ip, port);
	// cout << ntohs(addr.sin_port) << endl;
	uc.InitClient();
	//cout << ntohs(addr.sin_port) << endl;
	uc.StartClient();
	return 0;
}
