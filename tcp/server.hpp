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

using namespace std;

class TcpServer
{
private:
	int listen_sockfd;
	string ip;
	int port;
public:
	TcpServer(string _ip, int _port)
		:ip(_ip)
		, port(_port)
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
		sockaddr_in local_addr;
		bzero(&local_addr, sizeof(local_addr));
		local_addr.sin_family = AF_INET;
		local_addr.sin_addr.s_addr = inet_addr(ip.c_str());
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
	}
	void Service(int sockfd)
	{
		while (1)
		{
			char buf[1024];
			ssize_t s = read(sockfd, buf, sizeof(buf)-1);
			if (s>0)
			{
				buf[s] = 0;
				cout << "client# " << buf << endl;
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
			Service(sockfd);
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
