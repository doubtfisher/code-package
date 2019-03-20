#include <iostream>
#include <list>
#include <time.h>
#include <algorithm>

using namespace std;

//list��һ��˫���ͷѭ��������

void print_list(const list<int>& l)
{
	//list<int>::const_iterator cit = l.cbegin();
	auto cit = l.cbegin();
	while (cit != l.cend())
	{
		cout << *cit << " ";
		cit++;
	}
	cout << endl;
}

void test1()
{
	list<int> l1;
	list<int> l2(5, 3);//��n��Ԫ��ȥ���죬��10��3
	list<int> l3(l2.begin(), l2.end());//��һ�ε���������ȥ����
	list<int> copy(l3);//��������

	list<int>::iterator lit = copy.begin();
	while (lit != copy.end())
	{
		cout << *lit << " ";
		lit++;
	}
	cout << endl;
	print_list(copy);

	l3.push_back(1);
	l3.push_back(2);

	//���ڷ�Χ��for(��Χfor)
	for (const auto& e : l3)
	{
		cout << e << " ";
	}
	cout << endl;
	
	//���ű���
	list<int>::reverse_iterator rit = l3.rbegin();
	while (rit != l3.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

void test2()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.push_front(0);//ͷ�� ʱ�临�Ӷ�ΪO(1)

	l.pop_back();
	l.pop_front();

	l.assign(5, 4);//���丳ֵ�����֮ǰ�����ݸ������

	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;

}

void test3()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	
	l.insert(l.begin(), 0);
	auto pos = find(l.begin(), l.end(), 3);//���û���ҵ�������end()
	if (pos != l.end())//��Ҫ�ж��ҵ������Ƿ����
	{
		l.insert(pos, 10);
		//list��insert��������������ʧЧ
		*pos = 23;//pos����ʧЧ
	}
	l.erase(pos);
	//*pos = 33;//erase֮��pos��ʧЧ����Ϊ���λ���Ѿ���ɾ�ˣ���ȥ���ʻ����Ұָ�������
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test4()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	list<int>::iterator it = l.begin();
	while (it != l.end())
	{
		if (*it % 2 == 0)
		{
			it=l.erase(it);//erase�᷵����һ��λ�õĵ�����,������÷���ֵ���գ�����ֵ�����ʧЧ������
		}
		else
		{
			it++;//itָ���λ���Ѿ���ɾ���ˣ�������÷���ֵ���գ�����ֵ�����ʧЧ������
		}
	}

	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test5()//��������Ľ���
{
	list<int> l1(1000000, 1);
	list<int> l2(1000000, 2);

	size_t begin1 = clock();
	swap(l1, l2);//�ײ������swap����������Ч�ʲ��
	size_t end1 = clock();

	size_t begin2 = clock();
	l1.swap(l2);//�ǳ�Ա�����Ľ��������������Ƽ�ʹ�����swap
	size_t end2 = clock();

	cout << end1 - begin1 << endl;
	cout << end2 - begin2 << endl;

	for (const auto& e : l1)
	{
		cout << e << " ";
	}
	cout << endl;

	for (const auto& e : l2)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test6()
{
	list<int> l;
	l.resize(10);//�ڶ������������Ļ���intĬ����0
	l.resize(20, 4);
	l.resize(5);//����
	l.clear();//����������ݣ����ǲ����ͷ���,clear��������һ��������ʱ�������+���ͷ���
	l.push_back(1);
	l.push_back(2);
	for (const auto& e : l)
	{
		cout << e << " ";//Ĭ�ϴ������10��0
	}
	cout << endl;
}

void test7()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	//splice(�Ӻ�)��һl2�Ľڵ��Ƶ�l�У��������µĽڵ�
	list<int> l2;
	l2.push_back(6);
	l2.push_back(7);
	l2.push_back(8);
	list<int>::iterator it = l.begin();
	l.splice(it, l2);
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;

	l.remove(3);//�о�ɾ��û�оͲ�ɾ
	l2.push_back(2);
	l2.push_back(2);
	l2.push_back(2);
	l2.push_back(2);
	l2.push_back(2);

	l.sort();
	l.unique();//ȥ�أ�������Ѿ��Ź����list,��֮����������Ϊ�����Ч��,���ʹ����ͬ������ֻ��һ��
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test8()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	l.emplace_back(6);//���첢����Ԫ��  //�����÷����棬emplace��push_backûʲô���𣬵�����������ԭ��ȴ��ǧ�����push_back��һ����ͨ�ĺ�������emplace�ĵײ�����ֵ����
	
	/*l.push_back(Date(2018, 11, 1));
	l.emplace_back(Date(2018, 11, 1));
	l.emplace_back(2018, 11, 1);*/
	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	test8();
	system("pause");
	return 0;
}