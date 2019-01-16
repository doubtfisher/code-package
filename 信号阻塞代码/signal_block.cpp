#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signo)
{
	printf("AAAAAAA\n", signo);
}

void show(sigset_t *pending)//显示pending表
{
	int i = 0;
	for (i = 0; i <= 31; i++)
	{
		if (sigismember(pending, i))//判断i是否在信号集中，如果是，证明该信号已被pending
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
	sigemptyset(&set);//初始化set
	sigemptyset(&oset);//初始化oset
	sigaddset(&set, 2);//把2号信号添加到信号集中
	sigprocmask(SIG_SETMASK, &set, &oset);//读取信号集中的信号
	signal(2, handler);//捕捉2号信号
	sigset_t pending;//定义pending表
	int i = 10;
	while (1)//不断获取pending表
	{
		sigpending(&pending);//获得当前进程的pending信号集
		show(&pending);//显示pending表
		sleep(1);
		if ((i--) == 0)//每隔一秒显示一次pending表
		{
			sigprocmask(SIG_SETMASK, &oset, NULL);//把2号信号从阻塞信号集中去掉
		}
	}

	return 0;
}
