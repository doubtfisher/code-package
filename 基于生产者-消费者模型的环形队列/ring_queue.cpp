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
	sem_t data_sem;//数据的个数
	sem_t blank_sem;//空格的个数
	int consume_step;//消费者下标
	int product_step;//生产者下标
private:
	void P(sem_t *sem)//信号量的减操作
	{
		sem_wait(sem);//等待信号量，会将信号量的值减1
	}
	void V(sem_t *sem)//信号量的加操作
	{
		sem_post(sem);//发布信号量，表示资源使用完毕，可以归还资源了，将信号量加1
	}
public:
	RingQueue()//构造函数
		:product_step(0)
		, consume_step(0)
	{
		sem_init(&data_sem, 0, 0);//对数据进行初始化
		sem_init(&blank_sem, 0, NUM);//对格子进行初始化
	}
	void PushData(const int &data)//生产数据
	{
		P(&blank_sem);
		ring[product_step] = data;
		product_step++;
		product_step %= NUM;
		V(&data_sem);

	}
	void PopData(int &data)//消费数据
	{
		P(&data_sem);
		data = ring[consume_step];
		consume_step++;
		consume_step %= NUM;
		V(&blank_sem);
	}
	~RingQueue()//析构函数
	{
		sem_destroy(&data_sem);
		sem_destroy(&blank_sem);
	}
};

void *consumer(void *arg)//消费者消费数据
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

void *producter(void *arg)//生产者生产数据
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
	pthread_create(&c, NULL, consumer, (void*)&rq);//创建消费者线程
	pthread_create(&p, NULL, producter, (void*)&rq);//创建生产者线程

	pthread_join(c, NULL);//等待消费者线程
	pthread_join(p, NULL);//等待生产者线程
	return 0;
}


