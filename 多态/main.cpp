
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
//	virtual void BuyTicket()//虚函数
//	{
//		cout << "全价" << endl;
//	}
//};
//class Student :public Person
//{
//	virtual void BuyTicket()
//	{
//		cout << "半价" << endl;
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
//	delete p;//析构分为两步：①p去调desturctor()(因为是一个普通调用，跟类型有关，p的类型是Person，所以会去调Person的析构函数，但是实际上我们需要调的是派生类的析构函数，所以我们就应该做到让p指向person调Person，指向Student调Student);②再去free指针p
//}

//class Car
//{
//public:
//	virtual void Drive() =0;//纯虚函数
//};
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Benz-舒适" << endl;
//	}
//};
//
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "BMW-好操控" << endl;
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

//对象模型
//

class Person {
public:
	virtual void BuyTicket() 
	{
		cout << "买票-全价" << endl;
	}
public:
	int _p;
};

class Student : public Person 
{
public:
	virtual void BuyTicket() 
	{ 
		cout << "买票-半价" << endl; 
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