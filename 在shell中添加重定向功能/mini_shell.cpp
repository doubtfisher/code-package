 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
 #include <fcntl.h>
  
  #define MAX_CMD 1024
  char command[MAX_CMD];//ȫ������
 
 int do_face()//�ṩһϵ�е������У�������������Ĺ���
{
    memset(command,0x00,MAX_CMD);
    printf("mini_shell$ ");//����Լ�����ʾ��
    fflush(stdout);//ˢ�µ���ʾ����
    if(scanf("%[^\n]%*c",command)==0)//����
    { 
       getchar();
       return -1;
    }
   return 0;
 }

char **do_parse(char *buf)//ʹ��argv�Լ���ȡ�ַ����е�����
{
	//�ѿո��滻Ϊ\0
    int argc=0;
    static char *argv[32];
    char *ptr=buf;

   while(*ptr!='\0')
   {
       if(!isspace(*ptr))
     {
         argv[argc++]=ptr;
         while((!isspace(*ptr))&& (*ptr)!='\0')
         {
            ptr++;
         }
     }
     else
     {
       while(isspace(*ptr))
        {
           *ptr='\0';
           ptr++;
        }
     }
  }
   argv[argc]=NULL;
   return argv;
  }
 
 int do_redirect(char *buff)//�ض���
 {
    char *ptr=buff,*file=NULL;//file����������ȡ�ض�����ź�����ļ���
    int type=0,fd,redirect_type=-1;
    while(*ptr!='\0')
  {
     if(*ptr=='>')//�ж�����ض���
    {
        *ptr++='\0';
        redirect_type++;
        if(*ptr=='>')//�ߵ�������ж��Ƿ���׷���ض���
         {
             *ptr++;
             redirect_type++;
         }
       while(isspace(*ptr))//�ض����������ļ�����������ļ��������ܻ�����ɸ��ո�������������˵�����Ŀո�ֱ���ҵ��ض��������Ч���ļ������׵�ַ�����ļ�����
       {
           ptr++;
       }
       file=ptr;
       while((!isspace(*ptr))&& *ptr!='\0')//��ָ�����������
       {
          ptr++;
       }
     *ptr='\0';//���֤*ptrΪ\0,����֤��·�����ļ�������ԡ�\0'��β
     if(redirect_type==0)//�������0����������ض���
     {
         fd=open(file,O_CREAT|O_TRUNC|O_WRONLY,0664);//O_TRUNC��ָ���ļ����ͷȥд
      }
     else//�������1������׷���ض���
      {
         fd=open(file,O_CREAT|O_APPEND|O_WRONLY,0664);//O_APPEND��׷��
      }
     dup2(fd,1);
  }
   ptr++;
 }
  return 0;
}
 
int do_exec(char *buff)//���ݴ�������command���ִ�г����滻
 {
   char **argv={NULL};
   int pid=fork();//�����ӽ���
   if(pid==0)
   {
       do_redirect(buff);//�ض���
       argv=do_parse(buff);//�����ַ���
      if(argv[0]==NULL)
      {
        exit(-1);
      }
      execvp(argv[0],argv);//�����滻
    }
  else
   {
      waitpid(pid,NULL,0);//�ȴ��ӽ���
   }
 return 1;
  }

 int main()
 {
   while(1)
   {
      if(do_face()<0)
        continue;
      do_exec(command);
  }
  return 0;
 }
