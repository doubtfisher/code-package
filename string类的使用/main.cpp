#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

void test1()
{
	string s1("hello");//����
	cout << s1 << endl;

	string s2(s1);//��������
	cout << s2 << endl;

	string s3 = ("world");
     s3 = s2;//��ֵ
	 cout << s3 << endl;

	string file("file.cpp");
	string suffix(file, 4, 4);//���캯��
	cout << suffix << endl;

	string path("c:\\user",4);//���캯��
	cout << path << endl;

	string s5(file.begin(), file.end());//���캯��
	cout << s5 << endl;

	
}
//1.�����ַ���(���±����ʽ����)
int str2int1(string str)
{
	int value = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		value *= 10;
		value += str[i] - '0';//���±����ʽ����
		cout << str[i] <<" ";
	}
	cout << endl;
	return value;
	
}

//2.�����ַ���(�Ե�������ʽ����)//��������ָ�ڲ��ƻ���װ�������ȥ��������
int str2int2(string str)
{
	int value = 0;
	
	string::iterator it = str.begin();//���������
	while (it != str.end())
	{
		value *= 10;
		value += (*it - '0');
		it++;
	}

	vector<int> v;//vector�ĵ�����
	v.push_back(1);
	v.push_back(2);
	vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
		cout << *vit << " ";
		vit++;
	}
	cout << endl;

	list<int> lt;//list�ĵ�����
	lt.push_back(10);
	lt.push_back(20);
	list<int>::iterator lit = lt.begin();
	while (lit != lt.end())
	{
		cout << *lit << " ";
		lit++;
	}
	cout << endl;

	return value;
}

void test2()//���������
{
	string s6("12345");
	string::reverse_iterator rit = s6.rbegin();
	while (rit != s6.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}


//3.�����ַ���(��ʽforѭ��)
int str2int3(string str)
{
	int value = 0;

	for (auto ch : str)//c++11
	{
		value *= 10;
		value += (ch - '0');
	}
	return value;
}

int str2int4(const string& str)//const������
{
	int value = 0;
	//string::const_iterator it = str.begin();
	//string::const_reverse_iterator rit = str.rbegin();

	auto it = str.crbegin();//c++11��֧��cbegin��cend
	while (it != str.crend())
	{
		value *= 10;
		value += (*it - '0');
		it++;
	}

	return value;
}

void test3()
{
	string s1("hello");
	s1.push_back(' ');//����һ���ַ�
	s1.push_back('w');
	s1.push_back('o');
	s1.push_back('r');
	s1.push_back('l');
	s1.push_back('d');
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
	cout << s1.max_size() << endl;

	string s;
	//size_t sz = s.capacity();
	//size_t sz = 0;
	s.resize(100);//�ᷢ�����ݣ���ı��ַ����Ĵ�С
	s.reserve(100);//reserve��������ݣ�����һ���԰ѿռ俪�ã�֮�󶼲����ٷ������ݣ��������Ч��
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
}

void test4()
{
	string s("hello world");
	cout << s.size() << endl;//11
	cout << s.capacity() << endl;//15
	//s.resize(5);
	//s.resize(14,'a');//��ǰλ�ñ�size����Ҫ��������䣬������ˣ���������Ǹ��������û������Ĭ����'\0'
	//s.resize(14);
	//s.resize(20);
	cout << s << endl;
	//reserve:ֻ����������ȥ����������string����������(ֻ����)
	//resize:
	//�ȵ�ǰsizeСʱ�����ݼ�����ǰsize��
	//����ڵ�ǰsize������֮�䣬ֱ�Ӱ����ݸ�������ȥ���м�����������ַ���
	//����������󣬻������ݣ�Ȼ���������ڵ�size,(����+��ʼ��)
}


void test5()//���ݷ��ʽӿڵ�ʹ��
{
	string s1("hello,world");
	s1[5] = '%';//�����޸�����
	//cout << s1 << endl;

	for (size_t i = 0; i < s1.size(); i++)
	{
		if (s1[i] == ' ,')
		{
			s1[i] = '%';
		}
	}
	cout << s1 << endl;

	for (auto& ch : s1)
	{
		if (ch == '%')
		{
			ch = ',';
		}
	}
	cout << s1 << endl;


	size_t pos = s1.find(',');
	s1[pos] = '%';
	cout << s1 << endl;

	//at�ȼ���operator[]
	s1.at(pos) = ',';
	cout << s1 << endl;
}

void test6()//���ýӿ�
{
	string s1("hello");
	s1.push_back(' ');//β�ϲ���һ���ַ�
	s1.append("world");//׷��һ���ַ���
	s1 += "!!!";//+�ַ������ײ������append
	s1 += 'q';//+�ַ�,�ڵײ������push_back

	string protocol = "https://";
	string domain = "www.baidu.com";
	string url = protocol + domain;//����+����(������ʹ�ã�����̫��)
	url += domain;//+����
	cout << url << endl;

	s1.assign(" hei");//�൱��operator��ֵ
	cout << s1 << endl;
}

void test7()//insert��erase�ӿ�
{
	//����ĳ��λ�ò���һ���ַ�
	string s1("ello");
	s1.insert(0,1, 'h');//��0���λ�ò���1���ַ���h��
	s1.insert(s1.begin(), 'h');//ʹ�õ���������ͷ�壬һ�㲻ʹ�ã�Ч��̫��
	s1.insert(0, "hello ");//�����ַ���
	cout << s1 << endl;

	s1.erase(7, 1);//���±�Ϊ7�Ŀ�ʼɾ����ɾ��һ��
	s1.erase(4);//��4��ʼ��������ַ�ȫ��ɾ��
	cout << s1 << endl;
}
void test8()//����string��ν���
{
	string s1("hello");
	string s2("world");
	s1.swap(s2);//��Ա�����Ľ���������С
	cout << s1 << "--" << s2 << endl;
	swap(s1, s2);//��������+��θ�ֵ�����漰����ǳ����������,���ۺܴ󣬲������ã�Ч��̫��
	cout << s1 << "--" <<s2<< endl;
}
void test9()//�滻
{
	string url = "http://www.cplusplus.com/reference/string/string/clear/";
	url.replace(0, 4, "https");//��ǰ�ĸ��ַ��滻Ϊ��https��
	cout << url << endl;
}

void test10()//C��ʽ���ַ���(����'\0'�ͽ���)
{
	string url = "http://www.cplusplus.com/reference/string/string/clear/";
	cout << url.c_str() << endl;
	url[5] = '\0';
	printf("%s\n", url.c_str());
	cout << url << endl;
	cout << url.c_str() << endl;
}
void test11()//findϵ��
{
	//find  �ɹ����ض�Ӧ�ַ���λ�ã�ʧ�ܷ���npos
	string str("file.cpp");
	string suffix(str, 4, 4);//̫����Ӳ�����ʺ��ձ��
	cout << suffix << endl;

	size_t pos = str.find('.');
	if (pos != string::npos)
	{
		string suffix(str, pos, str.size() - pos);//ʹ�ù���ȡ��׺
		cout << suffix<< endl;
	}

}

string getfilesuffix(const string& file)//��ȡstring���Ӵ�
{
	//size_t pos = file.find('.');
	//string suffix;
	//if (pos != string::npos)
	//{
	//	//suffix = file.substr(pos);
	//	//suffix = file.substr(pos, file.size() - pos);//��posλ��ȥ�ң��Ҵ�СΪlen���ַ�
	//}

	size_t pos = file.rfind('.');
	string suffix;
	if (pos != string::npos)
	{
		suffix = file.substr(pos, file.size() - pos);//��posλ��ȥ�ң��Ҵ�СΪlen���ַ�
	}

	return suffix;
	
} 

void test12()
{
	//cout << getfilesuffix("file.hpp") << endl;
	cout << getfilesuffix("test.tar.zip") << endl;

}

void test13()//�����Һ�׺
{
	/*const string file("test.cpp.tar.zip");
	size_t pos = file.rfind('.');
	string suffix;
	if (pos != string::npos)
	{
		suffix = file.substr(pos, file.size() - pos);
	}
	cout << suffix << endl;
	size_t prevpos = file.rfind('.', pos - 1);
	if (prevpos != string::npos)
	{
		suffix = file.substr(prevpos, pos - prevpos);
	}
	cout << suffix << endl*/;

   string url("http://cplusplus.com/reference/string/string/string/clear/");
   size_t pos = url.find("://");
   pos += 3;
   size_t finish = url.find('/', pos);
   string domain = url.substr(pos,finish-pos);
   cout << domain << endl;
}

int main()
{

	//test1();
	/*cout << str2int1("1234") << endl;
	cout << str2int2("1234") << endl;*/
	//test2();
	/*string s("1234");
	cout << str2int4(s) << endl;*/
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	//test10();
	//test11();
	//test12();
	test13();
	system("pause");
	return 0;
}

//string�����õ����Ľӿ��У����졢resize��reserve��operator[]��operator+=��insert��erase��swap��c_str��find��substr��