

//server.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PN "."
#define PJ 0x4545

int main()
{
	//ʹ��ftok��������kֵ
	key_t k = ftok(PN, PJ);
	if (k<0)
	{
		printf("ftok error!\n");
		return 1;
	}
	//���������ڴ�
	int shmid = shmget(k, 4098, IPC_CREAT | IPC_EXCL | 0666);
	if (shmid<0)
	{
		perror("shmget");
		return 2;
	}
	printf("%d\n", shmid);
	sleep(5);
	//�����ҽ�(ӳ��)
	char *str = (char*)shmat(shmid, NULL, 0);
	//��ӡ�ͻ��˷��͹���������
	int i = 0;
	while (i++<26)
	{
		printf("client# %s\n", str);
		sleep(1);
	}
	//ȥ�������������ڴ��뵱ǰ��������
	shmdt(str);
	sleep(5);
   //ɾ�������ڴ�
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
	//ʹ��ftok��������kֵ
	key_t k = ftok(PN, PJ);
	if (k<0)
	{
		printf("ftok error!\n");
		return 1;
	}
	//���������ڴ�
	int shmid = shmget(k, 4098, IPC_CREAT);
	if (shmid<0)
	{
		perror("shmget");
		return 2;
	}
	printf("%d\n", shmid);
	//�����ҽ�(ӳ��)
	char *str = (char*)shmat(shmid, NULL, 0);
	sleep(1);
	//д������
	int i = 0;
	while (i<26)
	{
		str[i] = 'A' + i;
		i++;
		str[i] = 0;
		sleep(1);
	}
	//ȥ����
	shmdt(str);
	sleep(5);
	//ɾ�������ڴ�
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



