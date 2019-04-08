#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

class TcpClient
{
	private:
		int sockfd;
		string ip;
		int port;
	public:
		TcpClient(string _ip,int _port)
		:ip(_ip)
		,port(_port)
		{
		}
		void InitClient()
		{
		  //1.socket
          sockfd=socket(AF_INET,SOCK_STREAM,0);
		  if(sockfd<0)
		  {
		    cerr<<"socket error"<<endl;
			exit(2);
		  }
		  //2.bind(not)
		  //3.listen(not)
		}
		void StartClient()
		{
		  //4.connect
		   sockaddr_in addr;
		   bzero(&addr,sizeof(addr));
           addr.sin_family=AF_INET;
		   addr.sin_addr.s_addr=inet_addr(ip.c_str());
		   addr.sin_port=htons(port);
		   socklen_t len=sizeof(addr);
           int ret=connect(sockfd,(struct sockaddr*)&addr,len);
           if(ret<0)
		   {
		     cerr<<"connect error"<<endl;
			 exit(3);
		   }
		   string in;
		   while(1)
		   {
			 cout<<"Please Enter# ";
			 cin>>in;
			 write(sockfd,in.c_str(),in.size());
			 char buf[1024];
			 ssize_t s=read(sockfd,buf,sizeof(buf)-1);
             if(s>0)
			 {
			   buf[s]=0;
			   cout<<"Server Echo# "<<buf<<endl;
			 }
			 else
			 {
			   cerr<<"read error"<<endl;
			   exit(4);
			 }
		   }
        }
	    ~TcpClient()
		{
		   close(sockfd);
		}

};
