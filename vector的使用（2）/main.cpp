#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//vector<char>  //û\0  �ӿ��в���      string �� // ��\0  


//void print_vector(const vector<int> v)
//{
//	vector<int>::const_iterator cit = v.begin();//const������
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
//	v.push_back(1);//push_back(β��)
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
//	vector<int>::iterator vit = v.begin();//������
//	while (vit != v.end())
//	{
//		cout << *vit << " ";
//		vit++;
//	}
//	cout << endl;
//
//	vector<int>::reverse_iterator rit = v.rbegin();//���������
//	while (rit != v.rend())
//	{
//		cout << *rit << " ";
//		rit++;
//	}
//	cout << endl;
//
//	vector<int>::const_iterator cit = v.cbegin();//const������
//	while (cit != v.cend())
//	{
//		cout << *cit << " ";
//		cit++;
//	}
//	cout << endl;
//
//	for (auto e : v)//�﷨��
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	//print_vector(v);
//}

//void test2()//����vector��������ݵ�
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

	//insert���ڵ�ǰλ��֮ǰ���в���

	//v.insert(v.begin(), 0);//ͷ��
	//v.insert(v.end(), 5);//β��
	/*for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;*/

	//����ĳһ��ֵ��ǰ�����һ����
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

	//����ĳһ��ֵ��ǰ�����һ����
	//auto it1 = find(v.begin(), v.end(), 30);//find�������㷨�����
 //   if (it1 != v.end())
	//	v.insert(it1, 30);
	//else
	//	cout << "û���ҵ�" << endl;

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

	//ʵ���ϣ�������it����insert֮�󣬻���ʧЧ�ĵ�����
	//������ʧЧ����insert�����ģ���Ϊinsert���ܻ����ݣ���Ȼinsert���ܻ����ݣ��������ڲ�ͬƽ̨��������ݻ��Ʋ�һ��������һ��insert����һ����Ҫ�ٷ��ʵ�������
	//���Խ���ʹ��insert֮��,�Ͳ�Ҫ�ٷ��ʵ�������

//
//}
//c++�е����������䶼������ҿ�������

//void test4()
//{
//	//Ҫ��ɾ��vector�е�����ż��
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//
//	v.insert(v.begin(), 0);//ͷ��
//	v.insert(v.end(), 5);//β��
//	
//	
//	//eraseҲ������������ʧЧ
//	vector<int>::iterator it = v.begin();//��δ���Ҳ������������ʧЧ
//	while (it != v.end())
//	{
//		if (*it % 2 == 0)
//			//v.erase(it);��������ֵ�����ʧЧ�ķ���
//			it=v.erase(it);//erase�ķ���ֵ�᷵����һ��λ�õĵ�����
//		else
//		    it++;
//	}
//	for (auto e : v)
//	{
//		cout << e << " ";
//	}
//	cout << endl; 
//	//������ʧЧ��insert(���ܻ����ݣ����³���Ұָ��
//	//erase(vs�»ᱨ��),���ܻ���ֵ�����ʧЧ�ķ���
//	//��֮����vector�У�һ��insert����erase֮�󣬾Ͳ�Ҫ��ȥ���ʵ������ˣ�����ͻ��������
//}

//void test5()//����vector��ν�����
//{
//	vector<int> v1(10, 5);//10��5
//	vector<int> v2(5, 10);//5��10
//	//�ٽ�������̫��
//	swap(v1, v2);//�漰һϵ�еĸ�ֵ�����
//	//ʵ�ֹ��̣�
//	/*swap(v1, v2)
//	{
//		tmp = v1;
//		v1 = v2;
//		v2 = tmp;
//	}*/
//
//	//�ڽ������۱Ƚ�С
//	v1.swap(v2);//ֻ����ָ������ռ��ָ��Ϳ���
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

void test6()//����ֶ��ͷ�vector�Ŀռ䣿
{
	vector<int> v(100, 1);//����vector�������������Զ��ͷſռ䣬����Ҫ���ֶ��ͷ����ռ�
	cout << v.capacity() << endl;
	v.clear();//clearֻ������ݣ��൱��ֻ��size����ȥ�ˣ�����û�б䣬�ռ䲢û���ͷ�
	v.resize(0);//ֻ�ı�����size

	//����1
	//{
	//	vector<int> tmp;//tmp��һ���յĶ��󣬸�vһ������v�ͳɿյ��ˣ���ʱtmp���������򣬻��Զ����������������ͷŵ��ռ�
	//	tmp.swap(v);
	//}

	//����2(c++11)
	v.shrink_to_fit();//Ҳ�����ͷſռ䣬����һ�㲻����ʹ������ӿڣ�
	//��Ϊ����ӿ�ֻ�ǰ�capacity������sizeһ���Ĵ�С��֮����������ͷųɹ�������Ϊ����֮ǰ�Ѿ���size����0�ˣ����Ե�������ӿ�ʱ���ռ�Ż��ͷųɹ�,
	//����ڵ���shrink_to_fit֮ǰ����û�а�size����0����Ҳ�ͷŲ��˿ռ�
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

//1.vector��ô���ݣ�
//��һ����2��2�������ݣ����ǲ�һ���Ƿǵ���2����vs�µ�capacity�ǰ�1.5�������ģ�g++�����capacity�ǰ�2�������ġ�
//˳������ݲ�һ������2�����������������Ǹ��ݾ����������ġ�vs��PJ�汾STL��g++��SGI�汾STL��
//2.reserve��resize������
//��reserveֻ���𿪱ٿռ䣬���ȷ��֪����Ҫ�ö��ٿռ䣬reserve���Ի���vector���ݵĴ���ȱ�����⡣
// ��resize�ڿ��ռ��ͬʱ������г�ʼ������Ӱ��size��
//3.vector�У�ʲôʱ�������������ʧЧ��
//��insert(���ܻ�����)��erase֮�󣬻�����������ʧЧ  ����취�����õ��������õ�����ָ���µ���Ч�Ŀռ�
//���erase������ʧЧ�İ취�������������õ�ʱ����һ������ֵ�����᷵�����ɾ��λ����һ��λ�õ���Ч������