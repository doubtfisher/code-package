#include <iostream>
#include <list>
#include <time.h>
#include <algorithm>

using namespace std;

//list是一个双向带头循环的链表

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
	list<int> l2(5, 3);//拿n个元素去构造，即10个3
	list<int> l3(l2.begin(), l2.end());//拿一段迭代器区间去构造
	list<int> copy(l3);//拷贝构造

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

	//基于范围的for(范围for)
	for (const auto& e : l3)
	{
		cout << e << " ";
	}
	cout << endl;
	
	//倒着遍历
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
	l.push_front(0);//头插 时间复杂度为O(1)

	l.pop_back();
	l.pop_front();

	l.assign(5, 4);//分配赋值，会把之前的数据给清除掉

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
	auto pos = find(l.begin(), l.end(), 3);//如果没有找到，返回end()
	if (pos != l.end())//需要判断找的数字是否存在
	{
		l.insert(pos, 10);
		//list的insert不会引发迭代器失效
		*pos = 23;//pos不会失效
	}
	l.erase(pos);
	//*pos = 33;//erase之后，pos会失效，因为这个位置已经被删了，再去访问会出现野指针的问题
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
			it=l.erase(it);//erase会返回下一个位置的迭代器,如果不用返回值接收，会出现迭代器失效的问题
		}
		else
		{
			it++;//it指向的位置已经被删除了，如果不用返回值接收，会出现迭代器失效的问题
		}
	}

	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test5()//两个链表的交换
{
	list<int> l1(1000000, 1);
	list<int> l2(1000000, 2);

	size_t begin1 = clock();
	swap(l1, l2);//底层调的是swap，所以两个效率差不多
	size_t end1 = clock();

	size_t begin2 = clock();
	l1.swap(l2);//是成员变量的交换，不过优先推荐使用这个swap
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
	l.resize(10);//第二个参数不给的话，int默认是0
	l.resize(20, 4);
	l.resize(5);//缩容
	l.clear();//清楚所有数据，但是不清除头结点,clear和析构不一样，析构时清除数据+清掉头结点
	l.push_back(1);
	l.push_back(2);
	for (const auto& e : l)
	{
		cout << e << " ";//默认打出来是10个0
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

	//splice(接合)把一l2的节点移到l中，不创建新的节点
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

	l.remove(3);//有就删，没有就不删
	l2.push_back(2);
	l2.push_back(2);
	l2.push_back(2);
	l2.push_back(2);
	l2.push_back(2);

	l.sort();
	l.unique();//去重，是针对已经排过序的list,而之所以排序，是为了提高效率,最后，使得相同的数字只有一个
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
	l.emplace_back(6);//构造并插入元素  //单是用法方面，emplace和push_back没什么区别，但是他们两的原型却是千差万别，push_back是一个普通的函数，而emplace的底层是右值引用
	
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