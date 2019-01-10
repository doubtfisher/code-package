
//shell的运行原理：
//从命令行拿到输入信息；
//对信息进行分析处理；
//fork创建子进程，让子进程执行程序替换，父进程只用等待就行。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024
#define NUM 32

int main()
{
	char buf[MAX];
	char *myargv[NUM];
    printf("[yhx@localhost wsc]# ");
	fflush(stdout);
	fgets(buf, MAX, stdin);
	buf[strlen(buf) - 1] = 0;
	int i=0;
	//①分析处理字符串
 myargv[i]=strtok(buf," ");//拆分字符串
 i++;
 while(1)
  {
 char *p=strtok(NULL," ");
 if(p==NULL)
     {
          myargv[i]=NULL;
          break;
     }
 myargv[i]=p;
 i++;
 }
 //②执行

 pid_t pid=fork();//创建子进程进行程序替换
 if(pid<0)//创建失败
 {
	 ;
 }
 else if(pid==0)//child
  {
      execvp(myargv[0],myargv);
  }
 else//parent
  {
	 waitpid(pid, NULL, 0);
	 }
 //execvp(myargv[0],myargv);
  //for(i=0;myargv[i]!=NULL;i++)
 //{
	//printf("%d:%s\n",i,myargv[i]);
 //}
 //printf("%s",buf);
	 return 0;

}

