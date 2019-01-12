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
    if(mkfifo("./fifo",0644)<0)//���������ܵ������ж��Ƿ񴴽��ɹ�
     {
        perror("mkfifo error!\n");
        return 1;
    }
     int fd=open("./fifo",O_RDONLY);//��./fifo��ֻ����ʽ��
    if(fd<0)
    {
      perror("read error!\n");
       return 2;
     }
  char buf[MAX];
     while(1)
    {
        ssize_t s=read(fd,buf,sizeof(buf)-1);//�ӹܵ��ж�ȡ����
       if(s>0)//��ȡ�ɹ�
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
     close(fd);//�رն���
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
    int fd=open("./fifo",O_WRONLY);//��./fifo�ļ���ֻд��ʽ��
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
     write(fd,buf,strlen(buf));//���ܵ�����д������
   }

   close(fd);//�ر�д��
    return 0;
  }


