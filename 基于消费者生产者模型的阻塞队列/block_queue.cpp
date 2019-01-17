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
	void LockQueue()//�����м���
	{
		//water_line=false;
		pthread_mutex_lock(&lock);
	}
	void UnlockQueue()//�������ͷ���
	{
		pthread_mutex_unlock(&lock);
	}
	bool IsEmpty()//�ж϶����Ƿ�Ϊ��
	{
		return q.size() == 0 ? true : false;
	}
	void ThreadWait()//�̵߳ȴ�
	{
		pthread_cond_wait(&cond, &lock);
	}
	void WakeupOneThread()//����һ���߳�
	{
		pthread_cond_signal(&cond);
	}
	//void UpdateWaterLine()
	//{

	//}
public:
	BlockQueue()//�������еĳ�ʼ��
	{
		pthread_mutex_init(&lock, NULL);
		pthread_cond_init(&cond, NULL);
	}
	void PushData(const int& data)//�������������������
	{
		LockQueue();//�ȸ����м���
		q.push(data);//��������
		UnlockQueue();//������Ϻ��ͷ���
		cout << "producter run done,data push success:" << data << " wake up thread done..." << endl;
		WakeupOneThread();//����һ���߳̽�������
	}
	void PopData(int& data)//������������������
	{
		LockQueue();//�ȸ����м���
		while (IsEmpty())//�ж϶����Ƿ�Ϊ��
		{
			ThreadWait();//���еȴ�
		}
		//�ߵ��⣬˵�����в�Ϊ��
		data = q.front();//ȡ�����еĵ�һ��Ԫ��
		q.pop();//
		UnlockQueue();//�ͷż��ڶ����ϵ���
		cout << "consumer run done,data pop success:" << data << endl;
	}
	~BlockQueue()//�������е�����
	{
		pthread_mutex_destroy(&lock);
		pthread_cond_destroy(&cond);
	}
};

void *consumer(void *arg)//�������߳�
{
	BlockQueue *bq = (BlockQueue*)arg;
	int data;
	while (1)
	{
		bq->PopData(data);
		cout << "consume data done:" << data << endl;
	}
}

void *producter(void *arg)//�������߳�
{
	BlockQueue *bq = (BlockQueue*)arg;
	srand((unsigned int)time(NULL));//�������������
	while (1)
	{
		int data = rand() % 100 + 1;//�����ɵ�������ŵ�data��
		bq->PushData(data);//��data���뵽������
		cout << "product data done" << data << endl;
		sleep(1);
	}
}

int main()
{
	BlockQueue bq;//��������
	pthread_t c;//�����������߳�
	pthread_t p;//�����������߳�
	pthread_create(&c, NULL, consumer, (void*)&bq);//�����������߳�
	pthread_create(&p, NULL, producter, (void*)&bq);//�����������߳�

	pthread_join(c, NULL);//���̵߳ȴ��������߳�
	pthread_join(p, NULL);//���̵߳ȴ��������߳�
	return 0;
}
