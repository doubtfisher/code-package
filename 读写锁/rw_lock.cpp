#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;

pthread_rwlock_t rw;//����һ����д��
int data = 0;

void *reader(void *arg)//����
{
	while (1)
	{
		pthread_rwlock_rdlock(&rw);
		cout << "reader read done" << data << endl;
		pthread_rwlock_unlock(&rw);
		usleep(2000);
	}
}

void *writer(void *arg)//д��
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
	pthread_rwlock_init(&rw, NULL);//��д���ĳ�ʼ��
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
		pthread_join(r[i], NULL);//�̵߳ȴ�
	}
	pthread_join(w, NULL);
	pthread_rwlock_destroy(&rw);
	return 0;
}
