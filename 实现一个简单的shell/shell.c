
//shell������ԭ��
//���������õ�������Ϣ��
//����Ϣ���з�������
//fork�����ӽ��̣����ӽ���ִ�г����滻��������ֻ�õȴ����С�
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
	//�ٷ��������ַ���
 myargv[i]=strtok(buf," ");//����ַ���
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
 //��ִ��

 pid_t pid=fork();//�����ӽ��̽��г����滻
 if(pid<0)//����ʧ��
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

