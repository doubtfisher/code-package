#include <iostream>
#include <string>

using namespace std;

////父类(基类)
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//private:
//	string _name = "wenshencai";
//	int _age = 22;
//};
//
////继承之后，父类的成员函数和成员变量会变成子类的一部分,Student复用了Person的成员函数Print和成员变量。
//
////子类(派生类)
//class Student :public Person
//{
//protected:
//	int _id;
//};
//
//int main()
//{
//	Student s;
//	Person p;
//	s.Print();
//	p.Print();
//	system("pause");
//	return 0;
//}


//class Person//父类
//{
//public:
//	string _name;
//	string _sex;
//	int _age;
//};
//class Student :public Person//子类
//{
//public:
//	int _No;
//};
//int main()
//{
//	//派生类->基类
//	Person p;
//	p._name = "文伸才";
//	Student s;
//	s._name = "小明";
//	s._age = 20;
//	s._sex = "男";
//	p = s;//可以把子类给给基类对象，这种行为叫做切片
//
//	Person* ptrp = &s;//把派生类的指针赋给基类的指针
//	Person& rp = s;//把派生类的引用赋给基类的引用
//
//	//基类->派生类
//	//s = (Student)p;//不能转换
//
//	//可以转换
//	Student* ptrs = (Student*)ptrp;//如果指针本身是指向父类的，把它转回子类，会多看空间，是不行的；只有当指针本身指向的是子类，才能赋过去
//	Student& rs = (Student&)rp;//引用也是一样
//
//	system("pause");
//	return 0;
//}

//class Person
//{
//protected:
//	string _name = "小仙女";//名字
//	int _id = 610;//身份证号
//};
//class Student :public Person
//{
//public:
//	void Print()
//	{
//		cout << "姓名:" << _name << endl;
//		cout << "身份证号:" << Person::_id << endl;//如果非要访问基类的id，就需要显示调用
//		cout << "学号:" << _id << endl;//默认访问的是派生类的id
//	}
//protected:
//	int _id = 30;//学号
//};
//int main()
//{
//	Student s1;
//	s1.Print();
//	system("pause");
//	return 0;
//}
////这里，基类的id和派生类的id构成了隐藏，如果不显示调用，默认访问的是派生类的id


//class A
//{
//public:
//	void func()
//	{
//		cout << "func()" << endl;
//	}
//};
//class B :public A
//{
//public:
//	void func(int i)
//	{
//		cout << "func(int i)->" << i << endl;
//	}
//};
//int main()
//{
//	B b;
//	//b.func();//这个调用不行，虽然说派生类继承了基类中的无参func，但是由于构成了隐藏，所以在派生类中，默认调的是带参的func(int i);
//	b.A::func();//如果一定要访问，加个作用域就行
//	b.func(10);
//	system("pause");
//	return 0;
//}
////这里基类的的func和派生类的func构成了隐藏，而不是重载，重载有个条件，必须是在同一作用域中


//class Person
//{
//public:
//	Person(const char* name/* = "peter"*/)
//		:_name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		:_name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person& operator=(const Person& p)" << endl;
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name;//姓名
//};
//class Student :public Person
//{
//public:
//	Student(const char* name,int num)//派生类的构造函数
//		:Person(name)
//		, _num(num)
//	{
//	}
//	Student(const Student& s)//派生类的拷贝构造函数
//		:Person(s)//把派生类对象赋给基类对象，会发生切片行为
//		,_num(s._num)
//	{
//	}
//	Student& operator=(const Student& s)//operator=赋值
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);//把子类传给父类,这里必须显示调用，如果不显示调父类的赋值的话，父类和子类会构成重定义，父类的operator=会被隐藏，是调不到的
//			_num = s._num;
//		}
//	
//		return *this;
//	}
//	~Student()//析构
//	{
//		//~Person();//调不动，子类的析构和父类的析构构成了隐藏，所以调不到，~Person()和~Student()底层调的都是一个叫destructor的函数，函数名相同，构成了隐藏
//		//Person::~Person();//需要显示调用，但是又会有一个问题，析构被调了2次
//		//这里规定，派生类不用显示的去调基类的析构函数
//	}
//protected:
//	}
//	int _num;//学号
//};
//
//int main()
//{
//	Student s("小仙女",20);
//	Student s2("111", 12);
//	s2 = s;
//	system("pause");
//	return 0;
//}

//常见问题：实现一个不能被继承的类

////方法①:c++98中 ，构造函数私有化
//class NonInherit
//{
//private:
//	NonInherit()//构造私有化，在子类中是不可见的
//	{}
//};
////派生类的构造函数必须调基类的构造函数去初始化，一旦把基类的构造函数私有，派生类就定义不出对象了，也就是说基类就不能被继承了
//
////方法②:c++11中，使用final，定义为最终类，也可以保证该类不会被继承
//class NonInherit final
//{
//	NonInherit()
//	{}
//private:
//	
//};
//
//class B :public NonInherit
//{
//};
//
//int main()
//{
//	B b;
//	system("pause");
//	return 0;
//}

//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name;//姓名
//};
//class Student :public Person
//{
//protected:
//	int _num;//学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;//可以访问Person类的name，因为Display是Person的友元，突破了类域的限制
//	cout << s._num << endl;//不能访问，虽然Student继承了Person，但是友元关系不能被继承
//}
//void main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//}


//class Person
//{
//public:
//	Person()
//	{
//		_count++;
//	}
//protected:
//	string _name;
//public:
//	static int _count;
//};
//
//int Person::_count = 0;
//
//class Student :public Person
//{
//protected:
//	int _num;//学号
//};
//
//class Graduate :public Student
//{
//protected:
//	int _grade;//成绩
//};
//
//int main()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " 人数 :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " 人数 :" << Person::_count << endl;
//	system("pause");
//	return 0;x
//
//}


////菱形继承
//class Person
//{
//public:
//	string _name;//姓名
//};
//class Student :public Person
//{
//protected:
//	int _num;//学号
//};
//
//class Student :public Person
//{
//protected:
//	int _id;//职工编号
//};
//class Assistant :public Student, public Teacher
//{
//protected:
//	string _major;//主修课程
//};
//int main()
//{
//	//这样会有二义性，无法明确知道访问的到底是哪一个
//	Assistant a;
//	a._name = "mary";//不能这样访问，因为Assistant同时继承了Student,Teacher，不知道要访问的name到底是哪一个里面的成员变量
//
//	// 如果一定要访问，就需要显示指定，显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决，这就引入了虚继承
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}

//class A
//{
//public:
//	int _a;
//};
//
//class B :virtual public A
//{
//public:
//	int _b;
//};
//
//class C :virtual public A
//{
//public:
//	int _c;
//};
//
//class D :public B, public C
//{
//public:
//	int _d;
//};
//
//int main()
//{
//	D d;
//	d.B::_a = 1;
//	d.C::_a = 2;
//	d._b = 3;
//	d._c = 4;
//	d._d = 5;
//
//	cout << sizeof(d) << endl;
//	system("pause");
//	return 0;
}