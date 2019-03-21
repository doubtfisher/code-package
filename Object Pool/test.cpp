//内存池
//池化技术：线程池、进程池、连接池(用于数据库连接)、内存池，他们的共性是用来提高效率,减少了创建线程和销毁线程的代价，池化技术类似于缓冲这个概念
//池化技术还解决了内存碎片(外碎片)的问题
//外碎片的问题：申请不出更大的内存
//内碎片的问题：浪费了内存

//为什么空间配置器底层的指针数组是以8字节为间隔呢？而不是以4或者16为间隔？

//答：一般情况下，除了像string之类的，会有5字节或者6字节，剩下的数据结构很难出现像1,3,5这样的东西，他们一般是一个节点或者结构体，结构体的话，是要内存对齐的，如果不指定对齐数，一般是4或者8的倍数；
//②第一个必须是8，因为自由链表的指针要存储下一个位置的指针，如果整个对象的大小是4的话，在64位系统下，指针是8个字节，要链接下一个位置的话，链接不上，但是如果是8的话，不管是32位平台还是64位平台下，都存的下，所以第一个位置的间隔必须是8，
//③但是这个间隔比也不宜太大，如果太大，内碎片的问题就会严重

//内存池的进化：

//①教科书上的
//②定长内存池(对象池）
//③空间配置器(哈希映射的自由链表池)
//④malloc

#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using std::cout;
using std::endl;

#include "Object Pool.h"
//void test()
//{
//	ObjectPool<std::string> pool;
//	std::string* p1 = pool.New("11111");
//	std::string* p2 = pool.New("22222");
//	pool.Delete(p1);
//	pool.Delete(p2);
//
//	std::string* p3 = pool.New("33333");
//	std::string* p4 = pool.New("44444");
//	//std::string* p5 = pool.New("55555");
//	/*pool.Delete(p3);
//	pool.Delete(p4);
//*/
//}

//void BenchMark()
//{
//	size_t n = 10000;
//	size_t begin1 = clock();
//	std::vector<std::string*> v1;
//	v1.resize(n);
//	for (size_t i = 0; i < n; i++)
//	{
//		v1.push_back(new std::string);
//	}
//	for (size_t i = 0; i < n; i++)
//	{
//		delete(v1[i]);
//	}
//	size_t end1 = clock();
//	v1.clear();
//
//	size_t begin2 = clock();
//	std::vector<std::string*>v2;
//	v2.resize(n);
//	ObjectPool<std::string> pool;
//
//	for (size_t i = 0; i < n; i++)
//	{
//		v2.push_back(pool.New(""));
//	}
//	for (size_t i = 0; i < n; i++)
//	{
//		pool.Delete(v2[i]);
//	}
//	v2.clear();
//	size_t end2 = clock();
//
//	cout << end1 - begin1 << endl;
//	cout << end2 - begin2 << endl;
//}

int main()
{
	//test();
	TestObjectPool();
	system("pause");
	return 0;
}