#pragma once
#include <iostream>
#include <string>
#include <strings.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

using namespace std;

class TcpServer
{
private:
	int listen_sockfd;
	//string ip;
	int port;
public:
	TcpServer(int _port)
		:port(_port)
		, listen_sockfd(-1)
	{

	}
	void InitServer()
	{
		//1.socket
		listen_sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if (listen_sockfd<0)
		{
			cerr << "socket error" << endl;
			exit(2);
		}
		//2.bind
		int opt = 1;
		setsockopt(listen_sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
		sockaddr_in local_addr;
		bzero(&local_addr, sizeof(local_addr));
		local_addr.sin_family = AF_INET;
		//local_addr.sin_addr.s_addr=inet_addr(ip.c_str());
		local_addr.sin_addr.s_addr = htonl(INADDR_ANY);//动态绑定ip地址
		local_addr.sin_port = htons(port);
		int ret = bind(listen_sockfd, (struct sockaddr*)&local_addr, sizeof(local_addr));
		if (ret<0)
		{
			cerr << "bind error" << endl;
			exit(3);
		}
		//3.listen
		int li = listen(listen_sockfd, 5);
		if (li<0)
		{
			cerr << "listen error" << endl;
			exit(4);
		}

		signal(listen_sockfd, SIG_IGN);//发送信号给父进程
	}
	void Service(int sockfd, string _ip, int _port)
	{
		while (1)
		{
			char buf[1024];
			ssize_t s = read(sockfd, buf, sizeof(buf)-1);
			if (s>0)
			{
				buf[s] = 0;
				cout << "[ " << _ip << ": " << _port << "]# " << buf << endl;
				write(sockfd, buf, strlen(buf));
			}
			else if (s == 0)
			{
				cout << "client quit" << endl;
				break;
			}
			else
			{
				cerr << "read error" << endl;
			}
		}
		close(sockfd);
	}

	void StartServer()
	{
		struct sockaddr_in addr;
		socklen_t len = 0;
		while (1)
		{
			//4.accept link
			int sockfd = accept(listen_sockfd, (struct sockaddr*)&addr, &len);
			if (sockfd<0)
			{
				cerr << "accept error" << endl;
				continue;
			}
			cout << "Get a new client:" << sockfd << endl;

			int _port = ntohs(addr.sin_port);
			string _ip = inet_ntoa(addr.sin_addr);

			pid_t pid = fork();
			if (pid<0)
			{
				cerr << "fork error" << endl;
				close(sockfd);//没有能力处理，所以关闭
				continue;//重新创建进程
			}
			else if (pid == 0)//child
			{
				close(listen_sockfd);//child close listen socket
				Service(sockfd, _ip, _port);
				exit(0);
			}
			else//father
			{
				close(sockfd);
			}
		}

	}
	~TcpServer()
	{
		if (listen_sockfd>0)
		{
			close(listen_sockfd);
		}
	}
};
