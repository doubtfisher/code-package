

//server.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PN "."
#define PJ 0x4545

int main()
{
	//使用ftok函数创建k值
	key_t k = ftok(PN, PJ);
	if (k<0)
	{
		printf("ftok error!\n");
		return 1;
	}
	//创建共享内存
	int shmid = shmget(k, 4098, IPC_CREAT | IPC_EXCL | 0666);
	if (shmid<0)
	{
		perror("shmget");
		return 2;
	}
	printf("%d\n", shmid);
	sleep(5);
	//建立挂接(映射)
	char *str = (char*)shmat(shmid, NULL, 0);
	//打印客户端发送过来的数据
	int i = 0;
	while (i++<26)
	{
		printf("client# %s\n", str);
		sleep(1);
	}
	//去关联即将共享内存与当前进程脱离
	shmdt(str);
	sleep(5);
   //删除共享内存
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}

//client.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PN "."
#define PJ 0x4545

int main()
{
	//使用ftok函数创建k值
	key_t k = ftok(PN, PJ);
	if (k<0)
	{
		printf("ftok error!\n");
		return 1;
	}
	//创建共享内存
	int shmid = shmget(k, 4098, IPC_CREAT);
	if (shmid<0)
	{
		perror("shmget");
		return 2;
	}
	printf("%d\n", shmid);
	//建立挂接(映射)
	char *str = (char*)shmat(shmid, NULL, 0);
	sleep(1);
	//写入数据
	int i = 0;
	while (i<26)
	{
		str[i] = 'A' + i;
		i++;
		str[i] = 0;
		sleep(1);
	}
	//去关联
	shmdt(str);
	sleep(5);
	//删除共享内存
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}

//makefile
.PHONY:all
all : server clientIpc
  server : server.c
		   gcc - o $@ $^
	   clientIpc:clientIpc.c
				 gcc - o $@ $^
				 .PHONY:clean
			 clean :
rm - f server clientIpc



