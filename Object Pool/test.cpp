//�ڴ��
//�ػ��������̳߳ء����̳ء����ӳ�(�������ݿ�����)���ڴ�أ����ǵĹ������������Ч��,�����˴����̺߳������̵߳Ĵ��ۣ��ػ����������ڻ����������
//�ػ�������������ڴ���Ƭ(����Ƭ)������
//����Ƭ�����⣺���벻��������ڴ�
//����Ƭ�����⣺�˷����ڴ�

//Ϊʲô�ռ��������ײ��ָ����������8�ֽ�Ϊ����أ���������4����16Ϊ�����

//��һ������£�������string֮��ģ�����5�ֽڻ���6�ֽڣ�ʣ�µ����ݽṹ���ѳ�����1,3,5�����Ķ���������һ����һ���ڵ���߽ṹ�壬�ṹ��Ļ�����Ҫ�ڴ����ģ������ָ����������һ����4����8�ı�����
//�ڵ�һ��������8����Ϊ���������ָ��Ҫ�洢��һ��λ�õ�ָ�룬�����������Ĵ�С��4�Ļ�����64λϵͳ�£�ָ����8���ֽڣ�Ҫ������һ��λ�õĻ������Ӳ��ϣ����������8�Ļ���������32λƽ̨����64λƽ̨�£�������£����Ե�һ��λ�õļ��������8��
//�۵�����������Ҳ����̫�����̫������Ƭ������ͻ�����

//�ڴ�صĽ�����

//�ٽ̿����ϵ�
//�ڶ����ڴ��(����أ�
//�ۿռ�������(��ϣӳ������������)
//��malloc

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