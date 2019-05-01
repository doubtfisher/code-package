#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

//template<class K,class V>//ģ������
//struct pair
//{
//	K first;
//	V second;
//
//	//���캯��
//};
//
//template<class K,class V>//����ģ�壬�Ѳ��������������ݳ�����
//inline pair<K, V> make_pair(const K& key,const V& v)
//{
//	return pair<K, V>(key, v);
//}

void test_map()
{
	//map��(key,value)���͵ģ�ͨ���ؼ���key������ӳ�������Ϣvalue
	//map��insert��������value_type��һ��: pair<counst key_type,mapped_type>
	//mapped_type  �ڶ���ģ�����(T)Ҳ���Ǵ�ͳ��value������

	std::map<std::string, std::string> dict;

	dict.insert(std::pair<std::string, std::string>("sort", "����"));
	dict.insert(std::pair<std::string, std::string>("string", "�ַ���"));
	dict.insert(std::pair<std::string, std::string>("left", "���"));//pair<string, string>��һ��ģ�����ͣ�Ҫ�����캯�����г�ʼ��
	dict.insert(std::pair<std::string, std::string>("left", "ʣ��"));
	dict["pair"];
	dict["key"] = "�ؼ���";
	dict["left"] = "ʣ��";//ʹ��operator[]���key��Ӧ��value�޸�

	//dict.insert(std::make_pair("left", "���"));//make_pair��һ������ģ��

	//����������
	//std::map<std::string, std::string>::iterator dit = dict.begin();
	auto dit = dict.begin();
	while (dit != dict.end())
	{
		//cout << (*dit).first << ":" << (*dit).second << endl;
		cout << dit->first << dit->second << endl;//�ȼ���cout << dit->pair->first << dit->pair->second << endl;
		dit++;
	}
	//ͳ��ˮ�����ֵĴ���
	//����1��
	//std::string strs[] = { "ƻ��", "ƻ��", "ƻ��", "ƻ��", "��", "�ƹ�", "��", "�㽶", "ƻ��" };
	//std::map<std::string, int> countmap;
	//for (const auto& str : strs)
	//{
	//	auto it = countmap.find(str);
	//	if (it != countmap.end())
	//	{
	//		//(*it).second++;
	//		it->second++;//it->pair->second(ʡ��������һ��->)
	//	}
	//	else
	//	{
	//		countmap.insert(make_pair(str, 1));
	//	}
	//}

	//map��operator��ģ��ʵ��
	/*mapped_type& operator[](const key_type& k)
	{
		return (*((this->insert(make_pair(k, mapped_type()))).first)).second;
	}*/

	//����2:ͳ�ƴ���
	/*std::string strs[] = { "ƻ��", "ƻ��", "ƻ��", "ƻ��", "��", "�ƹ�", "��", "�㽶", "ƻ��" };
	std::map<std::string, int> countmap;
	for (const auto& str : strs)
	{
		countmap[str]++;
	}*/

	//ʹ��insert���ˮ��ͳ�ƵĴ���
	//std::string strs[] = { "ƻ��", "ƻ��", "ƻ��", "ƻ��", "��", "�ƹ�", "��", "�㽶", "ƻ��" };
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

//map��multimap���������ڣ�
//map��insertʱ������ؼ���key�Ѵ��ڣ��ٴζ�����в����ʱ�򣬻����ʧ��;
//multimap��insertʱ������ؼ���key�Ѵ��ڣ��Ծ��ܲ���ɹ�.����insert�ķ���ֵ��iterator��
//multimapû��operator[]�Ľӿ�
//multimap����key���࣬map������key����
//�ڽӿ�����multimapû��operator[],��map��

void test_set()
{
	//set������:
	//1.set��һ��key��ģ�ͣ����ҹؼ����ڲ���
	//2.����+ȥ��
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

	it = s.find(3);//ʱ�临�Ӷ���O(logN)
	//it = find(s.begin(), s.end(), 3);//ʱ�临�Ӷ���O(N)
	if (it != s.end())
	{
		cout << "�ҵ���" << endl;
		s.erase(it);//��������(���Ҫ�ҵ����ֲ����ڣ��ͻᱨ��)
	}
	
	s.erase(3);//��ֵ(ȥ��3���о�ɾ��û�оͲ�ɾ�����ᱨ��)
	for (auto e : s)
	{
		cout << e<< " ";
	}
	cout << endl;

	//set��֧���޸ģ�ԭ����set�ĵײ��Ƕ���������������޸��ˣ��Ͳ��ܱ�֤�����������ˣ������������Ͳ��ܱ�֤���ҵ�Ч��
}

void test_multiset()
{
	 //multiset�����ã�
	 //1.multisetҲ��һ��key��ģ�ͣ��������ҹؼ����ڲ���
     //2.����
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

	std::multiset<int>::iterator mit = ms.find(4);//multiset�ҵ���3,��������ĵ�һ��3
	if (mit != ms.end())
	{
		cout << "�ҵ���" << endl;
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