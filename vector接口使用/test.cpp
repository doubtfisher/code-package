//vector接口的使用

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(const vector<int> v)//const迭代器
{
	vector<int>::const_iterator it = v.cbegin();
	while (it != v.cend())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}
void test_vector1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	//反向迭代器
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	print_vector(v);
}
void test_vector2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	v.insert(v.begin(),0);//在当前位置的前一个进行插入
	v.insert(v.end(), 5);

	//想在某个值的前面插入一个数，这个时候得先找到这个数的位置才能进行插入
	//①
	/*auto it = v.begin();
	while (it != v.end())
	{
		if (*it == 3)
		{
			v.insert(it, 30);
			break;
		}
		else
		{
			it++;
		}
	}*/
	//②
	auto it = find(v.begin(),v.end(), 3);//这个接口的使用需要引<algorithm>头文件
	if (it != v.end())
		v.insert(it, 30);
	else
		cout << "没有找到" << endl;

	//如何删除掉3？
	//如果不加：it = find(v.begin(), v.end(), 3)这一句的话，因为it经历了上面的insert之后，it就成了失效的迭代器
	//怎么理解这儿的迭代器失效呢？
	//迭代器失效是由insert(因为insert时可能会增容)引发的，这时候会出现野指针，也就是迭代器失效
	//所以，在insert之后，就不要再去访问迭代器了，因为insert之后可能会增容，从而导致迭代器失效，为了避免这个问题，我们可以重新找这个迭代器的位置，这样就不会引发迭代器失效问题了
	/*it = find(v.begin(), v.end(), 3);
	v.erase(it);*/

	//要求删除所给数据中所有的偶数：/这种情况下，也会导致迭代器失效
	it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
			v.erase(it);
		it++;
	}

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	/*test_vector1();*/
	test_vector2();
	system("pause");
	return 0;
}

