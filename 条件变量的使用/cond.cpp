#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_mutex_t lock;//����һ����
pthread_cond_t cond;//����һ����������

void *Thread_Run(void *arg)//��߳�
{
	while (1)
	{
		pthread_cond_wait(&cond, &lock);//�̵߳ȴ�
		cout << "active..." << endl;
	}
}
void *Thread_Signal(void *arg)//�����߳�
{
	while (1)
	{
		sleep(1);
		pthread_cond_signal(&cond);//�����߳�
	}
}

int main()
{
	pthread_mutex_init(&lock, NULL);//��ʼ����
	pthread_cond_init(&cond, NULL);//��ʼ����������
	pthread_t tid1;
	pthread_t tid2;
	pthread_create(&tid1, NULL, Thread_Run, NULL);//������߳�
	pthread_create(&tid2, NULL, Thread_Signal, NULL);//���������߳�

	pthread_join(tid1, NULL);//�̵߳ȴ�
	pthread_join(tid2, NULL);//�̵߳ȴ�
	pthread_mutex_destroy(&lock);//��������
	pthread_cond_destroy(&cond);//��������������
}
