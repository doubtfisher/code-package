#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//vector<char>  //没\0  接口有差异      string ： // 有\0  


//void print_vector(const vector<int> v)
//{
//	vector<int>::const_iterator cit = v.begin();//const迭代器
//	while (cit != v.end())
//	{
//		cout << *cit << " ";
//		cit++;
//	}
//	cout << endl;
//}
//void test1()
//{
//	vector<int> v;
//	v.push_back(1);//push_back(尾插)
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//
//	for (size_t i = 0; i < v.size(); i++)//operator[]
//	{
//		cout << v[i] << " ";
//	}
//	cout << endl;
//	
//	vector<int>::iterator vit = v.begin();//迭代器
//	while (vit != v.end())
//	{
//		cout << *vit << " ";
//		vit++;
//	}
//	cout << endl;
//
//	vector<int>::reverse_iterator rit = v.rbegin();//反向迭代器
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//
//	vector<int>::const_iterator cit = v.cbegin();//const迭代器
//	while (cit != v.cend())
//	{
//		cout << *cit << " ";
//		cit++;
//	}
//	cout << endl;
//
//	for (auto e : v)//语法糖
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//print_vector(v);
//}

//void test2()//测试vector是如何增容的
//{
//	size_t size;
//	vector<int> f;
//	size = f.capacity();
//	cout << "make f grow:" << f.capacity() << endl;
//	for (int i = 0; i < 100; i++)
//	{
//		f.push_back(i);
//		if (size != f.capacity())
//		{
//			size = f.capacity();
//			cout << "capacity changed:" << size << endl;
//		}
//
//	}
//}
//void test3()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);

	//insert是在当前位置之前进行插入

	//v.insert(v.begin(), 0);//头插
	//v.insert(v.end(), 5);//尾插
	/*for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;*/

	//①在某一个值的前面插入一个数
	/*auto it = v.begin();
	while (it != v.end())
	{
		if (*it == 3)
		{
			v.insert(it, 30);
			break;
		}
		it++;
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;*/

	//②在某一个值的前面插入一个数
	//auto it1 = find(v.begin(), v.end(), 30);//find函数是算法里面的
 //   if (it1 != v.end())
	//	v.insert(it1, 30);
	//else
	//	cout << "没有找到" << endl;

	//for (auto e : v)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	/*vector<int>::iterator it = find(v.begin(), v.end(), 3);
	v.insert(it);
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;*/

	//实际上，迭代器it经过insert之后，会变成失效的迭代器
	//迭代器失效是由insert引发的，因为insert可能会增容，虽然insert可能会增容，但是由于不同平台下面的扩容机制不一样，所以一旦insert，就一定不要再访问迭代器了
	//所以建议使用insert之后,就不要再访问迭代器了

//
//}
//c++中迭代器的区间都是左闭右开的区间

//void test4()
//{
//	//要求删除vector中的所有偶数
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	v.insert(v.begin(), 0);//头插
//	v.insert(v.end(), 5);//尾插
//	
//	
//	//erase也会引发迭代器失效
//	vector<int>::iterator it = v.begin();//这段代码也会引发迭代器失效
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			//v.erase(it);这样会出现迭代器失效的风险
//			it=v.erase(it);//erase的返回值会返回下一个位置的迭代器
//		else
//		    it++;
//	}
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl; 
//	//迭代器失效：insert(可能会增容）导致出现野指针
//	//erase(vs下会报错),可能会出现迭代器失效的风险
//	//总之：在vector中，一旦insert或者erase之后，就不要再去访问迭代器了，否则就会出现问题
//}

//void test5()//两个vector如何交换？
//{
//	vector<int> v1(10, 5);//10个5
//	vector<int> v2(5, 10);//5个10
//	//①交换代价太大
//	swap(v1, v2);//涉及一系列的赋值和深拷贝
//	//实现过程：
//	/*swap(v1, v2)
//	{
//		tmp = v1;
//		v1 = v2;
//		v2 = tmp;
//	}*/
//
//	//②交换代价比较小
//	v1.swap(v2);//只交换指向两块空间的指针就可以
//	
//	for (auto e : v1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	for (auto e : v2)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//}

void test6()//如何手动释放vector的空间？
{
	vector<int> v(100, 1);//本来vector的析构函数会自动释放空间，但是要求手动释放这块空间
	cout << v.capacity() << endl;
	v.clear();//clear只清空数据，相当于只把size减下去了，容量没有变，空间并没有释放
	v.resize(0);//只改变它的size

	//方法1
	//{
	//	vector<int> tmp;//tmp是一个空的对象，跟v一交换，v就成空的了，此时tmp出了作用域，会自动调析构函数，会释放掉空间
	//	tmp.swap(v);
	//}

	//方法2(c++11)
	v.shrink_to_fit();//也可以释放空间，但是一般不建议使用这个接口，
	//因为这个接口只是把capacity缩到和size一样的大小，之所以这里会释放成功，是因为我们之前已经把size缩到0了，所以调用这个接口时，空间才会释放成功,
	//如果在调用shrink_to_fit之前，并没有把size缩到0，它也释放不了空间
	cout << v.capacity() << endl;

}

int main()
{
	//test1();
	// test2();
	//test3();
	//test4();
	//test5();
	test6();
	system("pause");
	return 0;
}

//1.vector怎么增容？
//答：一般是2倍2倍的增容，但是不一定是非得增2倍，vs下的capacity是按1.5倍增长的，g++下面的capacity是按2倍增长的。
//顺序表增容不一定都是2倍，具体增长多少是根据具体的需求定义的。vs是PJ版本STL，g++是SGI版本STL。
//2.reserve和resize的区别？
//答：reserve只负责开辟空间，如果确定知道需要用多少空间，reserve可以缓解vector增容的代价缺陷问题。
// 而resize在开空间的同时还会进行初始化，会影响size。
//3.vector中，什么时候会引发迭代器失效？
//答：insert(可能会增容)或erase之后，会引发迭代器失效  解决办法：重置迭代器，让迭代器指向新的有效的空间
//解决erase迭代器失效的办法：迭代器在设置的时候，有一个返回值，它会返回最近删除位置下一个位置的有效迭代器