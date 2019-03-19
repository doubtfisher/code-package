#include "vector.h"


void test1()
{

	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	for (size_t i = 0; i < v.Size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	v.PopBack();
	Vector<int>::iterator it = v.begin();//迭代器
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (const auto& e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test2()
{
	Vector<string> vs;
	vs.PushBack("aaaa");
	vs.PushBack("bbbb");
	vs.PushBack("cccc");
	vs.PushBack("dddd");

	for (const auto& e : vs)
	{
		cout << e << " ";
	}
	cout << endl;

	vs.PopBack();
	vs.PopBack();

	for (const auto& e : vs)
	{
		cout << e << " ";
	}
	cout << endl;
}
void test3()//vector也有深浅拷贝问题，会导致两个指针指向同一块空间
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(3);
	v.PushBack(5);
	v.PushBack(7);
	Vector<int> copy(v);
	for (const auto& e : copy)
	{
		cout << e << " ";
	}
	cout << endl;

	Vector<string> vs;
	vs.PushBack("aa");
	vs.PushBack("bb");
	vs.PushBack("cc");
	vs.PushBack("dd");
	Vector<string> copy2(vs);
	for (const auto& s : copy2)
	{
		cout << s<< " ";
	}
	cout << endl;

	Vector<int> copy3 = v;
	for (const auto& s : copy3)
	{
		cout << s << " ";
	}
	cout << endl;

}

void test4(const Vector<int>& v)
{
	Vector<int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(3);
	v.PushBack(5);
	v.PushBack(7);
	test4(v);
	system("pause");
	return 0;
}