#include "tcp_server.hpp"

using namespace std;

void Usage(string proc)
{
  cout<<"Usage: "<<proc<<" port"<<endl;
}

int main(int argc,char *argv[])
{
  if(argc!=2)
  {
    Usage(argv[0]);
	exit(1);
  }
  //string ip=argv[1];
  int port=atoi(argv[1]);
  TcpServer ts(port); 
  ts.InitServer();
  ts.StartServer();
  return 0;
}
