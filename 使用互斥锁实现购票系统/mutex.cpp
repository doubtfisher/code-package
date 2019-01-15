#include <iostream>
#include <pthread.h>

using namespace std;

int tickets = 1000;
pthread_mutex_t mutex;//����һ��ȫ�ֵ���

void *BuyTicket(void *arg)
{
	for (;;)
	{
		pthread_mutex_lock(&mutex);//����
		if (tickets>0)
		{
			usleep(1000);
			cout << "get ticket success:" << tickets-- << endl;
			pthread_mutex_unlock(&mutex);//����

		}
		else
		{
			pthread_mutex_unlock(&mutex);//����
			break;
		}
	}
	cout << "thread" << pthread_self() << "quit..." << endl;
}

int main()
{
	pthread_t tid[5];
	pthread_mutex_init(&mutex, NULL);//��ʼ����
	int i = 0;
	for (i = 0; i<5; i++)
	{
		pthread_create(tid + i, NULL, BuyTicket, NULL);
	}
	for (i = 0; i<5; i++)
	{
		pthread_join(tid[i], NULL);//���̵߳ȴ����߳̽���
	}
	pthread_mutex_destroy(&mutex);//��������
	return 0;
}
