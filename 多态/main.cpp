
#include <iostream>
#include <stdio.h>
using namespace std;

//class Base1 {
//public:
//	int _b1;
//};
//class Base2 {
//public:
//	int _b2;
//};
//class Derive : public Base1, public Base2 {
//public:
//	int _d;
//};
//int main()
//{
//
//	Derive d;
//	Base1* p1 = &d;
//	Base2* p2 = &d;
//	Derive* p3 = &d;
//	cout << p1 << endl;
//	cout << p2 << endl;
//	cout << p3 << endl;
//	system("pause");
//	return 0;
//}

//class Person
//{
//public:
//	virtual void BuyTicket()//�麯��
//	{
//		cout << "ȫ��" << endl;
//	}
//};
//class Student :public Person
//{
//	virtual void BuyTicket()
//	{
//		cout << "���" << endl;
//	}
//};
//void Func(Person& people)
//{
//	people.BuyTicket();
//}
//int main()
//{
//	Person Wen;
//	Func(Wen);
//
//	Student Yan;
//	Func(Yan);
//	system("pause");
//	return 0;
//}

//class A
//{};
//
//class B :public A
//{};
//
//class Person
//{
//public:
//	virtual A* f()
//	{
//		return new A;
//	}
//};
//class Student :public Person
//{
//public:
//	virtual B* f()
//	{
//		return new B;
//	}
//};
//int main()
//{
//	Person a;
//	Student b;
//
//	system("pause");
//	return 0;
//}
//
//class Person
//{
//public:
//	virtual  ~Person()
//	{
//		 cout << "~Person()" << endl;
//	}
//};
//class Student :public Person
//{
//public:
//
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//int main()
//{
//	Person* p = new Student;
//	delete p;//������Ϊ��������pȥ��desturctor()(��Ϊ��һ����ͨ���ã��������йأ�p��������Person�����Ի�ȥ��Person����������������ʵ����������Ҫ������������������������������Ǿ�Ӧ��������pָ��person��Person��ָ��Student��Student);����ȥfreeָ��p
//}

//class Car
//{
//public:
//	virtual void Drive() =0;//���麯��
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-����" << endl;
//	}
//};
//
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-�òٿ�" << endl;
//	}
//};
//
//int main()
//{
//	Car* pBenz = new Benz;
//	pBenz->Drive();
//
//	Car* pBMW = new BMW;
//	pBMW->Drive();
//
//	system("pause");
//	return 0;
//}

//����ģ��
//

class Person {
public:
	virtual void BuyTicket() 
	{
		cout << "��Ʊ-ȫ��" << endl;
	}
public:
	int _p;
};

class Student : public Person 
{
public:
	virtual void BuyTicket() 
	{ 
		cout << "��Ʊ-���" << endl; 
	}
public:
	int _s;
};

void Func(Person& p)
{
	p.BuyTicket();
}

int main()
{
	Person Wen;
	Func(Wen);

	Student Yan;
	Func(Yan);
	system("pause");
	return 0;
}