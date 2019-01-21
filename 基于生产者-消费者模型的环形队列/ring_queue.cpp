#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM 16

using namespace std;

class RingQueue
{
private:
	int ring[NUM];
	sem_t data_sem;//���ݵĸ���
	sem_t blank_sem;//�ո�ĸ���
	int consume_step;//�������±�
	int product_step;//�������±�
private:
	void P(sem_t *sem)//�ź����ļ�����
	{
		sem_wait(sem);//�ȴ��ź������Ὣ�ź�����ֵ��1
	}
	void V(sem_t *sem)//�ź����ļӲ���
	{
		sem_post(sem);//�����ź�������ʾ��Դʹ����ϣ����Թ黹��Դ�ˣ����ź�����1
	}
public:
	RingQueue()//���캯��
		:product_step(0)
		, consume_step(0)
	{
		sem_init(&data_sem, 0, 0);//�����ݽ��г�ʼ��
		sem_init(&blank_sem, 0, NUM);//�Ը��ӽ��г�ʼ��
	}
	void PushData(const int &data)//��������
	{
		P(&blank_sem);
		ring[product_step] = data;
		product_step++;
		product_step %= NUM;
		V(&data_sem);

	}
	void PopData(int &data)//��������
	{
		P(&data_sem);
		data = ring[consume_step];
		consume_step++;
		consume_step %= NUM;
		V(&blank_sem);
	}
	~RingQueue()//��������
	{
		sem_destroy(&data_sem);
		sem_destroy(&blank_sem);
	}
};

void *consumer(void *arg)//��������������
{
	RingQueue *rq = (RingQueue*)arg;
	while (1)
	{
		int data;
		rq->PopData(data);
		cout << "consume done:" << data << endl;
		//sleep(1);
	}
}

void *producter(void *arg)//��������������
{
	RingQueue *rq = (RingQueue*)arg;
	srand((unsigned long)time(NULL));
	while (1)
	{
		int data = rand() % 100 + 1;
		rq->PushData(data);
		cout << "product done:" << data << endl;
		sleep(1);
	}
}

int main()
{
	RingQueue rq;
	pthread_t c;
	pthread_t p;
	pthread_create(&c, NULL, consumer, (void*)&rq);//�����������߳�
	pthread_create(&p, NULL, producter, (void*)&rq);//�����������߳�

	pthread_join(c, NULL);//�ȴ��������߳�
	pthread_join(p, NULL);//�ȴ��������߳�
	return 0;
}


