#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <queue>
#include <time.h>
#include <stdlib.h>

using namespace std;

int calculate(int x, int y, int op);//����һ��������
typedef int(*HandlerTask_t)(int x, int y, int op);

class Task//������
{
private:
	int x;
	int y;
	int op;//0(+);1(-);2(*);3(/)
	HandlerTask_t handler;
public:
	Task(int _x = -1, int _y = -1, int _op = -1)//���캯��
		:x(_x), y(_y), op(_op)
	{
	}
	void Register(HandlerTask_t _handler)//ע��һ������������
	{
		handler = _handler;
	}
	void Run()//
	{
		int ret = handler(x, y, op);
		const char *_op = "+-*/";
		cout << "thread[" << pthread_self() << "] handler result:" << x << _op[op] << y << "=" << ret << endl;

	}
	~Task()
	{
	}
};

class ThreadPool//�߳̿����
{
private:
	int thread_nums;//���̵߳���Ŀ
	int wait_nums;//�̵߳ȴ�����Ŀ
	queue<Task> task_queue;//�������
	pthread_mutex_t lock;//����һ��������
	pthread_cond_t cond;//����һ����������
private:
	void LockQueue()//�����м���
	{
		pthread_mutex_lock(&lock);
	}
	void UnlockQueue()//�������ͷ���
	{
		pthread_mutex_unlock(&lock);
	}
	bool QueueIsEmpty()//�ж϶����Ƿ�Ϊ��
	{
		return task_queue.size() == 0 ? true : false;
	}
	void ThreadWait()//�̵߳ȴ�
	{
		wait_nums++;
		pthread_cond_wait(&cond, &lock);
		wait_nums--;
	}
	void WakeupThread()//�̻߳���
	{
		pthread_cond_signal(&cond);
	}
	void PopTask(Task &t)//�Ӷ������ó�����
	{
		t = task_queue.front();
		task_queue.pop();
	}

public:
	ThreadPool(int _num = 5)//�̳߳صĳ�ʼ��
		:wait_nums(0)
		, thread_nums(_num)
	{
		pthread_mutex_init(&lock, NULL);
		pthread_cond_init(&cond, NULL);
	}
	static void *ThreadRoutine(void *arg)//�̵߳��ճ�����
	{
		pthread_detach(pthread_self());//�̷߳���
		ThreadPool *tp = (ThreadPool*)arg;
		while (1)
		{
			tp->LockQueue();
			while (tp->QueueIsEmpty())
			{
				tp->ThreadWait();
			}
			Task t;
			tp->PopTask(t);
			tp->UnlockQueue();
			t.Run();
		}
	}
	void InitThreadPool()//�̳߳صĳ�ʼ��
	{
		pthread_t t;
		int i;
		for (i = 0; i<thread_nums; i++)
		{
			pthread_create(&t, NULL, ThreadRoutine, this);
		}
	}
	void PushTask(const Task &t)//��������������
	{
		LockQueue();
		task_queue.push(t);
		WakeupThread();
		UnlockQueue();
	}
	~ThreadPool()
	{
		pthread_mutex_destroy(&lock);
		pthread_cond_destroy(&cond);
	}

};

int calculate(int x, int y, int op)//ʵ��һ������������
{
	int ret = 0;
	switch (op)
	{
	case 0:
		ret = x + y;
		break;
	case 1:
		ret = x - y;
		break;
	case 2:
		ret = x*y;
		break;
	case 3:
		ret = x / y;
		break;
	default:
		cout << "calculate error" << endl;
		break;
	}
	return ret;
}

int main()
{
	ThreadPool tp;
	tp.InitThreadPool();
	srand((unsigned long)time(NULL));//����������ĺ���
	while (1)
	{
		sleep(1);
		int x = rand() % 100 + 1;
		int y = rand() % 100 + 1;
		int op = rand() % 4;
		Task t(x, y, op);
		t.Register(calculate);//ע��һ������������
		tp.PushTask(t);//�Ѹ÷����������
	}
	return 0;
}
