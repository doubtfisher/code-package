#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <queue>
#include <time.h>
#include <stdlib.h>

using namespace std;

int calculate(int x, int y, int op);//声明一个计算器
typedef int(*HandlerTask_t)(int x, int y, int op);

class Task//任务类
{
private:
	int x;
	int y;
	int op;//0(+);1(-);2(*);3(/)
	HandlerTask_t handler;
public:
	Task(int _x = -1, int _y = -1, int _op = -1)//构造函数
		:x(_x), y(_y), op(_op)
	{
	}
	void Register(HandlerTask_t _handler)//注册一个计算器方法
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

class ThreadPool//线程库的类
{
private:
	int thread_nums;//总线程的数目
	int wait_nums;//线程等待的数目
	queue<Task> task_queue;//任务队列
	pthread_mutex_t lock;//定义一个互斥锁
	pthread_cond_t cond;//定义一个条件变量
private:
	void LockQueue()//给队列加锁
	{
		pthread_mutex_lock(&lock);
	}
	void UnlockQueue()//给队列释放锁
	{
		pthread_mutex_unlock(&lock);
	}
	bool QueueIsEmpty()//判断队列是否为空
	{
		return task_queue.size() == 0 ? true : false;
	}
	void ThreadWait()//线程等待
	{
		wait_nums++;
		pthread_cond_wait(&cond, &lock);
		wait_nums--;
	}
	void WakeupThread()//线程唤醒
	{
		pthread_cond_signal(&cond);
	}
	void PopTask(Task &t)//从队列里拿出任务
	{
		t = task_queue.front();
		task_queue.pop();
	}

public:
	ThreadPool(int _num = 5)//线程池的初始化
		:wait_nums(0)
		, thread_nums(_num)
	{
		pthread_mutex_init(&lock, NULL);
		pthread_cond_init(&cond, NULL);
	}
	static void *ThreadRoutine(void *arg)//线程的日常事务
	{
		pthread_detach(pthread_self());//线程分离
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
	void InitThreadPool()//线程池的初始化
	{
		pthread_t t;
		int i;
		for (i = 0; i<thread_nums; i++)
		{
			pthread_create(&t, NULL, ThreadRoutine, this);
		}
	}
	void PushTask(const Task &t)//把任务放入队列中
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

int calculate(int x, int y, int op)//实现一个计算器方法
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
	srand((unsigned long)time(NULL));//产生随机数的函数
	while (1)
	{
		sleep(1);
		int x = rand() % 100 + 1;
		int y = rand() % 100 + 1;
		int op = rand() % 4;
		Task t(x, y, op);
		t.Register(calculate);//注册一个计算器方法
		tp.PushTask(t);//把该方法放入队列
	}
	return 0;
}
