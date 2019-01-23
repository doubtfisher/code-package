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
		int sockfd;//�׽���������
		string ip;//IP��ַ
		int port;//�˿ں�
	public:
		UdpServer(string _ip,int _port)//���캯��
		:ip(_ip)
		,port(_port)
    	{
		}
       void InitServer()//��������ʼ��
	   {
         sockfd=socket(AF_INET,SOCK_DGRAM,0);//1.�����׽���
		 if(sockfd<0)
		 {
		   cerr<<"socket error"<<endl;
		   exit(2);
		 }
                                //2.�󶨶˿ں�
		 struct sockaddr_in addr;
		 addr.sin_family=AF_INET;
		 addr.sin_addr.s_addr=inet_addr(ip.c_str());
		 addr.sin_port=htons(port);
		 int ret=bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
		 if(ret<0)
		 {
		   cerr<<"bind error"<<endl;
		   exit(3);
		 }
	   }
	   void RecvData(string &out,struct sockaddr_in &addr,socklen_t &len)//�������Կͻ��˵�����
	   {
		 char buf[1024]={0};
                                  //3.��������
		 ssize_t s=recvfrom(sockfd,buf,sizeof(buf)-1,0,(struct sockaddr*)&addr,&len);;
		 if(s>0)
		 {
		  buf[s]=0;
		  out=buf;
		 }
		 else
		 {
		 cerr<<"recvfrom error"<<endl;
		 exit(4);
		 }
	   }
      void SendData(string &in,struct sockaddr_in &addr, socklen_t len)
	  {
                  //4.��������
	   ssize_t ret=sendto(sockfd,(char*)in.c_str(),in.size(),0,(struct sockaddr*)&addr,len);
	   if(ret<0)
	   {
	     cerr<<"sendto error"<<endl;
		// cout<<strerror(errno)<<endl;
		 exit(5);
	   }
	  }
      void StartServer()
	  {
	    string str;
	    struct sockaddr_in addr;
		socklen_t len = 0;
		while(1)
		{
		  len=sizeof(addr);
		  RecvData(str,addr,len);
		  str+="UdpServer";
		  cout<<"client# "<<str<<endl;
		  SendData(str,addr,len);
		}
	  }
	  ~UdpServer()
      {
       //5.�ر��׽���������
        close(sockfd);
	  }
};
void Usage(string proc)
{
  cout<<"Usage: "<<proc<<"ip port"<<endl;
}
int main(int argc,char* argv[])
{
  if(argc!=3)
  {
    Usage(argv[0]);
	exit(1);
  }
  UdpServer us(argv[1],atoi(argv[2]));//�������󲢳�ʼ��
  us.InitServer();
  us.StartServer();
  return 0;
}
