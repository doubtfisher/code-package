#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <unistd.h>

using namespace std;

class BlockQueue
{
private:
	queue<int> q;
	bool water_line;
	pthread_mutex_t lock;
	pthread_cond_t cond;
private:
	void LockQueue()//给队列加锁
	{
		//water_line=false;
		pthread_mutex_lock(&lock);
	}
	void UnlockQueue()//给队列释放锁
	{
		pthread_mutex_unlock(&lock);
	}
	bool IsEmpty()//判断队列是否为空
	{
		return q.size() == 0 ? true : false;
	}
	void ThreadWait()//线程等待
	{
		pthread_cond_wait(&cond, &lock);
	}
	void WakeupOneThread()//唤醒一个线程
	{
		pthread_cond_signal(&cond);
	}
	//void UpdateWaterLine()
	//{

	//}
public:
	BlockQueue()//阻塞队列的初始化
	{
		pthread_mutex_init(&lock, NULL);
		pthread_cond_init(&cond, NULL);
	}
	void PushData(const int& data)//向阻塞队列里插入数据
	{
		LockQueue();//先给队列加锁
		q.push(data);//插入数据
		UnlockQueue();//插入完毕后，释放锁
		cout << "producter run done,data push success:" << data << " wake up thread done..." << endl;
		WakeupOneThread();//唤醒一个线程进行消费
	}
	void PopData(int& data)//从阻塞队列里拿数据
	{
		LockQueue();//先给队列加锁
		while (IsEmpty())//判断队列是否为空
		{
			ThreadWait();//进行等待
		}
		//走到这，说明队列不为空
		data = q.front();//取出队列的第一个元素
		q.pop();//
		UnlockQueue();//释放加在队列上的锁
		cout << "consumer run done,data pop success:" << data << endl;
	}
	~BlockQueue()//阻塞队列的析构
	{
		pthread_mutex_destroy(&lock);
		pthread_cond_destroy(&cond);
	}
};

void *consumer(void *arg)//消费者线程
{
	BlockQueue *bq = (BlockQueue*)arg;
	int data;
	while (1)
	{
		bq->PopData(data);
		cout << "consume data done:" << data << endl;
	}
}

void *producter(void *arg)//生产者线程
{
	BlockQueue *bq = (BlockQueue*)arg;
	srand((unsigned int)time(NULL));//生成随机数函数
	while (1)
	{
		int data = rand() % 100 + 1;//把生成的随机数放到data中
		bq->PushData(data);//把data插入到队列中
		cout << "product data done" << data << endl;
		sleep(1);
	}
}

int main()
{
	BlockQueue bq;//创建对象
	pthread_t c;//定义消费者线程
	pthread_t p;//定义生产者线程
	pthread_create(&c, NULL, consumer, (void*)&bq);//创建消费者线程
	pthread_create(&p, NULL, producter, (void*)&bq);//创建生产者线程

	pthread_join(c, NULL);//主线程等待消费者线程
	pthread_join(p, NULL);//主线程等待生产者线程
	return 0;
}
