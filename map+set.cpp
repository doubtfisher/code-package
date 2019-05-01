#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

//template<class K,class V>//模板类型
//struct pair
//{
//	K first;
//	V second;
//
//	//构造函数
//};
//
//template<class K,class V>//函数模板，把参数传过来，推演出类型
//inline pair<K, V> make_pair(const K& key,const V& v)
//{
//	return pair<K, V>(key, v);
//}

void test_map()
{
	//map是(key,value)类型的，通过关键字key，查找映射关联信息value
	//map的insert的类型是value_type是一个: pair<counst key_type,mapped_type>
	//mapped_type  第二个模板参数(T)也就是传统的value的类型

	std::map<std::string, std::string> dict;

	dict.insert(std::pair<std::string, std::string>("sort", "排序"));
	dict.insert(std::pair<std::string, std::string>("string", "字符串"));
	dict.insert(std::pair<std::string, std::string>("left", "左边"));//pair<string, string>是一个模板类型，要调构造函数进行初始化
	dict.insert(std::pair<std::string, std::string>("left", "剩余"));
	dict["pair"];
	dict["key"] = "关键字";
	dict["left"] = "剩余";//使用operator[]会把key对应的value修改

	//dict.insert(std::make_pair("left", "左边"));//make_pair是一个函数模板

	//迭代器遍历
	//std::map<std::string, std::string>::iterator dit = dict.begin();
	auto dit = dict.begin();
	while (dit != dict.end())
	{
		//cout << (*dit).first << ":" << (*dit).second << endl;
		cout << dit->first << dit->second << endl;//等价于cout << dit->pair->first << dit->pair->second << endl;
		dit++;
	}
	//统计水果出现的次数
	//方法1：
	//std::string strs[] = { "苹果", "苹果", "苹果", "苹果", "梨", "黄瓜", "梨", "香蕉", "苹果" };
	//std::map<std::string, int> countmap;
	//for (const auto& str : strs)
	//{
	//	auto it = countmap.find(str);
	//	if (it != countmap.end())
	//	{
	//		//(*it).second++;
	//		it->second++;//it->pair->second(省略了其中一个->)
	//	}
	//	else
	//	{
	//		countmap.insert(make_pair(str, 1));
	//	}
	//}

	//map中operator的模拟实现
	/*mapped_type& operator[](const key_type& k)
	{
		return (*((this->insert(make_pair(k, mapped_type()))).first)).second;
	}*/

	//方法2:统计次数
	/*std::string strs[] = { "苹果", "苹果", "苹果", "苹果", "梨", "黄瓜", "梨", "香蕉", "苹果" };
	std::map<std::string, int> countmap;
	for (const auto& str : strs)
	{
		countmap[str]++;
	}*/

	//使用insert完成水果统计的次数
	//std::string strs[] = { "苹果", "苹果", "苹果", "苹果", "梨", "黄瓜", "梨", "香蕉", "苹果" };
	//typedef std::map<std::string, int> CountMap;
	//typedef std::map<std::string, int>::iterator CountMapIter;

	//std::map<std::string, int> countmap;
	//for (const auto& str : strs)
	//{
	//	//std::pair<std::map<std::string, int>::iterator, bool> ret = countmap.insert(make_pair(str, 1));
	//	//std::pair<CountMapIter, bool> ret = countmap.insert(make_pair(str,1));
	//	auto ret = countmap.insert(make_pair(str, 1));
	//	if (ret.second == false)
	//	{
	//		ret.first->second++;
	//	}
	//}

	//std::map<std::string, int>::iterator cit = countmap.begin();
	/*while (cit != countmap.end())
	{
		cout << cit->first << ":" << cit->second << endl;
		cit++;
	}*/
	/*for (const auto& kv : countmap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}

	cout << endl;*/
}

//map与multimap的区别在于：
//map在insert时，如果关键字key已存在，再次对其进行插入的时候，会插入失败;
//multimap在insert时，如果关键字key已存在，仍旧能插入成功.它的insert的返回值是iterator，
//multimap没有operator[]的接口
//multimap允许key冗余，map不允许key冗余
//在接口上面multimap没有operator[],而map有

void test_set()
{
	//set的作用:
	//1.set是一个key的模型，查找关键字在不在
	//2.排序+去重
	std::set<int> s;
	s.insert(4);
	s.insert(2);
	//s.insert(3);
	s.insert(1);
	s.insert(5);
	s.insert(5);
	s.insert(5);
	s.insert(5);

	std::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	it = s.find(3);//时间复杂度是O(logN)
	//it = find(s.begin(), s.end(), 3);//时间复杂度是O(N)
	if (it != s.end())
	{
		cout << "找到了" << endl;
		s.erase(it);//传迭代器(如果要找的数字不存在，就会报错)
	}
	
	s.erase(3);//传值(去找3，有就删，没有就不删，不会报错)
	for (auto e : s)
	{
		cout << e<< " ";
	}
	cout << endl;

	//set不支持修改，原因是set的底层是二叉搜索树，如果修改了，就不能保证它是搜索树了，不是搜索树就不能保证查找的效率
}

void test_multiset()
{
	 //multiset的作用：
	 //1.multiset也是一个key的模型，用来查找关键字在不在
     //2.排序
	std::multiset<int> ms;
	ms.insert(2);
	ms.insert(1);
	ms.insert(4);
	ms.insert(3);
	ms.insert(4);
	ms.insert(4);
	ms.insert(5);

	for (auto e : ms)
	{
		std::cout << e << " ";
	}
	cout << endl;

	std::multiset<int>::iterator mit = ms.find(4);//multiset找到的3,是它中序的第一个3
	if (mit != ms.end())
	{
		cout << "找到了" << endl;
		while (*mit == 4)
		{
			cout << *mit << endl;
			mit++;
		}

	}

	for (auto e : ms)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	//test_set();
	//test_multiset();
	test_map();
	system("pause");
	return 0;
}