//makefile
.PHONY:all
all : server client
  server : server.c
	gcc - o $@ $ ^

client:client.c
	gcc - o $@ $ ^

.PHONY:clean
clean :
	rm - f server client

//server.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
   
  #define MAX 1024
  
  
  int main()
  {
    if(mkfifo("./fifo",0644)<0)//创建命名管道，并判断是否创建成功
     {
        perror("mkfifo error!\n");
        return 1;
    }
     int fd=open("./fifo",O_RDONLY);//让./fifo以只读方式打开
    if(fd<0)
    {
      perror("read error!\n");
       return 2;
     }
  char buf[MAX];
     while(1)
    {
        ssize_t s=read(fd,buf,sizeof(buf)-1);//从管道中读取数据
       if(s>0)//读取成功
       {
          buf[s]=0;
           printf("client# %s\n",buf);
        }
        else if(s==0)
        {
         printf("client quit,server quit too!\n");
         break;
       }
       else
       {
        perror("read");
       }
    }
     close(fd);//关闭读端
     return 0;
  }

//client.c
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
   
#define MAX 1024
   
   int main()
  {
    int fd=open("./fifo",O_WRONLY);//把./fifo文件以只写方式打开
    if(fd<0)
    {
     perror("read");
      return 1;
    }
    char buf[MAX];
    while(1)
   {
     printf("Please Enter:> ");
      scanf("%s",buf);
     write(fd,buf,strlen(buf));//往管道里面写入数据
   }

   close(fd);//关闭写端
    return 0;
  }


