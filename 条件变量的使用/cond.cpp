#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_mutex_t lock;//定义一个锁
pthread_cond_t cond;//定义一个条件变量

void *Thread_Run(void *arg)//活动线程
{
	while (1)
	{
		pthread_cond_wait(&cond, &lock);//线程等待
		cout << "active..." << endl;
	}
}
void *Thread_Signal(void *arg)//唤醒线程
{
	while (1)
	{
		sleep(1);
		pthread_cond_signal(&cond);//唤醒线程
	}
}

int main()
{
	pthread_mutex_init(&lock, NULL);//初始化锁
	pthread_cond_init(&cond, NULL);//初始化条件变量
	pthread_t tid1;
	pthread_t tid2;
	pthread_create(&tid1, NULL, Thread_Run, NULL);//创建活动线程
	pthread_create(&tid2, NULL, Thread_Signal, NULL);//创建唤醒线程

	pthread_join(tid1, NULL);//线程等待
	pthread_join(tid2, NULL);//线程等待
	pthread_mutex_destroy(&lock);//锁的销毁
	pthread_cond_destroy(&cond);//条件变量的销毁
}
