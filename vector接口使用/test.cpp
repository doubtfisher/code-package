//vector�ӿڵ�ʹ��

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(const vector<int> v)//const������
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
	//���������
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

	v.insert(v.begin(),0);//�ڵ�ǰλ�õ�ǰһ�����в���
	v.insert(v.end(), 5);

	//����ĳ��ֵ��ǰ�����һ���������ʱ������ҵ��������λ�ò��ܽ��в���
	//��
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
	//��
	auto it = find(v.begin(),v.end(), 3);//����ӿڵ�ʹ����Ҫ��<algorithm>ͷ�ļ�
	if (it != v.end())
		v.insert(it, 30);
	else
		cout << "û���ҵ�" << endl;

	//���ɾ����3��
	//������ӣ�it = find(v.begin(), v.end(), 3)��һ��Ļ�����Ϊit�����������insert֮��it�ͳ���ʧЧ�ĵ�����
	//��ô�������ĵ�����ʧЧ�أ�
	//������ʧЧ����insert(��Ϊinsertʱ���ܻ�����)�����ģ���ʱ������Ұָ�룬Ҳ���ǵ�����ʧЧ
	//���ԣ���insert֮�󣬾Ͳ�Ҫ��ȥ���ʵ������ˣ���Ϊinsert֮����ܻ����ݣ��Ӷ����µ�����ʧЧ��Ϊ�˱���������⣬���ǿ��������������������λ�ã������Ͳ�������������ʧЧ������
	/*it = find(v.begin(), v.end(), 3);
	v.erase(it);*/

	//Ҫ��ɾ���������������е�ż����/��������£�Ҳ�ᵼ�µ�����ʧЧ
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

