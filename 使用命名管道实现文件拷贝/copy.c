#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
 
#define MAX 1024
 
int main()
{
   mkfifo("fifo",0644);//创建命名管道
   int infd;//读端
  infd=open("file",O_RDONLY);//把file文件以只读方式打开
  if(infd==-1)//读取失败
   {
    perror("open");
   exit(1);
   }
   int outfd;//写端
   outfd=open("fifo",O_WRONLY);//fifo以只写方式打开
   if(outfd==-1)
	  {
    perror("open");
     exit(1);
    }
  char buf[MAX];
  int s;
  while (s = (read(infd, buf, MAX))>0) 
	  //将文件描述符infd中的字节读取到缓冲区buf
	  //read返回成功读取到的字节数
  {
    write(outfd,buf,s);
	// write返回：若成功则返回写入的字节数，若出错则返回-1
	//write尝试将缓冲区buf中的字节写到文件描述符outfd中
   }
  close(infd);//关闭写端
  close(outfd);//关闭读端

   return 0;
 }


  #include <stdio.h>
  #include <stdlib.h>
  #include <unistd.h>
  #include <string.h>
  #include <sys/types.h>
  #include <sys/stat.h>
  #include <fcntl.h>
   
   #define MAX 1024
  
  int main()
  {
	  //写端
    int outfd;
    outfd=open("file.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);//让file.txt文件以写方式创建，并且从文件的最开始去写
    if(outfd==-1)//创建失败时，则退出
   {
        perror("open");
        exit(1);
   }
	//读端
    int infd;
    infd=open("fifo",O_RDONLY);
    if(infd==-1)
    {
        perror("open");
        exit(1);
    }
   char buf[MAX];
   int s;

   //将从管道中读取到的数据写入文件file.txt中
   while ((s = read(infd, buf, MAX))>0) 
   {
     write(outfd,buf,s);
   }

   //关闭读写端
   close(infd);
   close(outfd);

    return 0;
  }



