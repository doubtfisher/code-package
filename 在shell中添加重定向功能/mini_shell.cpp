 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
 #include <fcntl.h>
  
  #define MAX_CMD 1024
  char command[MAX_CMD];//全局数组
 
 int do_face()//提供一系列的命令行，让其有能输入的过程
{
    memset(command,0x00,MAX_CMD);
    printf("mini_shell$ ");//输出自己的提示符
    fflush(stdout);//刷新到显示器上
    if(scanf("%[^\n]%*c",command)==0)//输入
    { 
       getchar();
       return -1;
    }
   return 0;
 }

char **do_parse(char *buf)//使用argv自己提取字符串中的命令
{
	//把空格替换为\0
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
 
 int do_redirect(char *buff)//重定向
 {
    char *ptr=buff,*file=NULL;//file的作用是提取重定向符号后面的文件名
    int type=0,fd,redirect_type=-1;
    while(*ptr!='\0')
  {
     if(*ptr=='>')//判断输出重定向
    {
        *ptr++='\0';
        redirect_type++;
        if(*ptr=='>')//走到这儿，判断是否是追加重定向
         {
             *ptr++;
             redirect_type++;
         }
       while(isspace(*ptr))//重定向后跟的是文件名，往后跟文件名，可能会跟若干个空格，这句代码是想过滤掉多余的空格，直接找到重定向后面有效的文件名的首地址，即文件名称
       {
           ptr++;
       }
       file=ptr;
       while((!isspace(*ptr))&& *ptr!='\0')//让指针继续往后走
       {
          ptr++;
       }
     *ptr='\0';//最后保证*ptr为\0,即保证带路径的文件名最后以‘\0'结尾
     if(redirect_type==0)//如果等于0，就是输出重定向
     {
         fd=open(file,O_CREAT|O_TRUNC|O_WRONLY,0664);//O_TRUNC是指从文件的最开头去写
      }
     else//如果等于1，就是追加重定向
      {
         fd=open(file,O_CREAT|O_APPEND|O_WRONLY,0664);//O_APPEND是追加
      }
     dup2(fd,1);
  }
   ptr++;
 }
  return 0;
}
 
int do_exec(char *buff)//根据传进来的command命令，执行程序替换
 {
   char **argv={NULL};
   int pid=fork();//创建子进程
   if(pid==0)
   {
       do_redirect(buff);//重定向
       argv=do_parse(buff);//解析字符串
      if(argv[0]==NULL)
      {
        exit(-1);
      }
      execvp(argv[0],argv);//程序替换
    }
  else
   {
      waitpid(pid,NULL,0);//等待子进程
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
