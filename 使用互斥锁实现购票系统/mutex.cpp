#include <iostream>
#include <pthread.h>

using namespace std;

int tickets = 1000;
pthread_mutex_t mutex;//定义一个全局的锁

void *BuyTicket(void *arg)
{
	for (;;)
	{
		pthread_mutex_lock(&mutex);//加锁
		if (tickets>0)
		{
			usleep(1000);
			cout << "get ticket success:" << tickets-- << endl;
			pthread_mutex_unlock(&mutex);//解锁

		}
		else
		{
			pthread_mutex_unlock(&mutex);//解锁
			break;
		}
	}
	cout << "thread" << pthread_self() << "quit..." << endl;
}

int main()
{
	pthread_t tid[5];
	pthread_mutex_init(&mutex, NULL);//初始化锁
	int i = 0;
	for (i = 0; i<5; i++)
	{
		pthread_create(tid + i, NULL, BuyTicket, NULL);
	}
	for (i = 0; i<5; i++)
	{
		pthread_join(tid[i], NULL);//主线程等待新线程结束
	}
	pthread_mutex_destroy(&mutex);//锁的销毁
	return 0;
}
