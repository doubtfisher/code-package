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
   mkfifo("fifo",0644);//���������ܵ�
   int infd;//����
  infd=open("file",O_RDONLY);//��file�ļ���ֻ����ʽ��
  if(infd==-1)//��ȡʧ��
   {
    perror("open");
   exit(1);
   }
   int outfd;//д��
   outfd=open("fifo",O_WRONLY);//fifo��ֻд��ʽ��
   if(outfd==-1)
	  {
    perror("open");
     exit(1);
    }
  char buf[MAX];
  int s;
  while (s = (read(infd, buf, MAX))>0) 
	  //���ļ�������infd�е��ֽڶ�ȡ��������buf
	  //read���سɹ���ȡ�����ֽ���
  {
    write(outfd,buf,s);
	// write���أ����ɹ��򷵻�д����ֽ������������򷵻�-1
	//write���Խ�������buf�е��ֽ�д���ļ�������outfd��
   }
  close(infd);//�ر�д��
  close(outfd);//�رն���

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
	  //д��
    int outfd;
    outfd=open("file.txt",O_WRONLY|O_CREAT|O_TRUNC,0644);//��file.txt�ļ���д��ʽ���������Ҵ��ļ����ʼȥд
    if(outfd==-1)//����ʧ��ʱ�����˳�
   {
        perror("open");
        exit(1);
   }
	//����
    int infd;
    infd=open("fifo",O_RDONLY);
    if(infd==-1)
    {
        perror("open");
        exit(1);
    }
   char buf[MAX];
   int s;

   //���ӹܵ��ж�ȡ��������д���ļ�file.txt��
   while ((s = read(infd, buf, MAX))>0) 
   {
     write(outfd,buf,s);
   }

   //�رն�д��
   close(infd);
   close(outfd);

    return 0;
  }



