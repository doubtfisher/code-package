#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_rwlock_t rw;//定义一个读写锁
int data = 0;

void *reader(void *arg)//读者
{
	while (1)
	{
		pthread_rwlock_rdlock(&rw);
		cout << "reader read done" << data << endl;
		pthread_rwlock_unlock(&rw);
		usleep(2000);
	}
}

void *writer(void *arg)//写者
{
	while (1)
	{
		pthread_rwlock_wrlock(&rw);
		cout << "writer write done" << ++data << endl;
		pthread_rwlock_unlock(&rw);
		usleep(3000);
	}
}

int main()
{
	pthread_rwlock_init(&rw, NULL);//读写锁的初始化
	pthread_t r[5];
	pthread_t w;
	int i;
	for (i = 0; i<5; i++)
	{
		pthread_create(&r[i], NULL, reader, NULL);
	}
	pthread_create(&w, NULL, writer, NULL);

	for (i = 0; i<5; i++)
	{
		pthread_join(r[i], NULL);//线程等待
	}
	pthread_join(w, NULL);
	pthread_rwlock_destroy(&rw);
	return 0;
}
