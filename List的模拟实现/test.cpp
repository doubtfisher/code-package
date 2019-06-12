#include "List.h"

void TestList1()
{
	List<int> l;
	l.PushBack(2);
	l.PushBack(1);
	l.PushBack(3);
	l.PushBack(4); 
	l.PushBack(5);

	List<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : l)
	{
		cout << e << " ";
	}
	cout << endl;
}

void PrintList(const List<int>& lt)
{
	List<int>::const_iterator it = lt.begin();
	while (it != lt.end())
	{
		//*it = 10;
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void TestList2()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushFront(0);
	l.PushFront(-1);
	l.PopBack();
	l.PopFront();
	l.PushBack(5);

	//PrintList(l);
	List<int>::iterator it = l.begin();
	while (it != l.end())
	{
		//*it = 10;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	List<int> copy(l);
	PrintList(copy);

	List<int> l2;
	List<int> l3;
	l2.PushBack(1);
	l2.PushBack(3);
	l2.PushBack(5);
	l2.PushBack(7);

	 l3= l2;
	PrintList(l3);
	cout << l3.Size() << endl;
	
}
void TestList3()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	auto it = l.begin();
	while (it != l.end())
	{
		if (*it % 2 == 0)
		{
			it = l.Erase(it);
		}
		it++;
	}
	for (const auto& e : l)
	{
		cout << e << " ";
	}
	cout << endl;
	

}

int main()
{
	//TestList1();
	//TestList2();
	TestList3();
	system("pause");
	return 0;
}