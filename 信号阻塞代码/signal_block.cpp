#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signo)
{
	printf("AAAAAAA\n", signo);
}

void show(sigset_t *pending)//��ʾpending��
{
	int i = 0;
	for (i = 0; i <= 31; i++)
	{
		if (sigismember(pending, i))//�ж�i�Ƿ����źż��У�����ǣ�֤�����ź��ѱ�pending
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");
}


int main()
{
	sigset_t set, oset;
	sigemptyset(&set);//��ʼ��set
	sigemptyset(&oset);//��ʼ��oset
	sigaddset(&set, 2);//��2���ź���ӵ��źż���
	sigprocmask(SIG_SETMASK, &set, &oset);//��ȡ�źż��е��ź�
	signal(2, handler);//��׽2���ź�
	sigset_t pending;//����pending��
	int i = 10;
	while (1)//���ϻ�ȡpending��
	{
		sigpending(&pending);//��õ�ǰ���̵�pending�źż�
		show(&pending);//��ʾpending��
		sleep(1);
		if ((i--) == 0)//ÿ��һ����ʾһ��pending��
		{
			sigprocmask(SIG_SETMASK, &oset, NULL);//��2���źŴ������źż���ȥ��
		}
	}

	return 0;
}
