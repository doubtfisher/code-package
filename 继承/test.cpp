#include <iostream>
#include <string>

using namespace std;

////����(����)
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
////�̳�֮�󣬸���ĳ�Ա�����ͳ�Ա�������������һ����,Student������Person�ĳ�Ա����Print�ͳ�Ա������
//
////����(������)
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


//class Person//����
//{
//public:
//	string _name;
//	string _sex;
//	int _age;
//};
//class Student :public Person//����
//{
//public:
//	int _No;
//};
//int main()
//{
//	//������->����
//	Person p;
//	p._name = "�����";
//	Student s;
//	s._name = "С��";
//	s._age = 20;
//	s._sex = "��";
//	p = s;//���԰���������������������Ϊ������Ƭ
//
//	Person* ptrp = &s;//���������ָ�븳�������ָ��
//	Person& rp = s;//������������ø������������
//
//	//����->������
//	//s = (Student)p;//����ת��
//
//	//����ת��
//	Student* ptrs = (Student*)ptrp;//���ָ�뱾����ָ����ģ�����ת�����࣬��࿴�ռ䣬�ǲ��еģ�ֻ�е�ָ�뱾��ָ��������࣬���ܸ���ȥ
//	Student& rs = (Student&)rp;//����Ҳ��һ��
//
//	system("pause");
//	return 0;
//}

//class Person
//{
//protected:
//	string _name = "С��Ů";//����
//	int _id = 610;//���֤��
//};
//class Student :public Person
//{
//public:
//	void Print()
//	{
//		cout << "����:" << _name << endl;
//		cout << "���֤��:" << Person::_id << endl;//�����Ҫ���ʻ����id������Ҫ��ʾ����
//		cout << "ѧ��:" << _id << endl;//Ĭ�Ϸ��ʵ����������id
//	}
//protected:
//	int _id = 30;//ѧ��
//};
//int main()
//{
//	Student s1;
//	s1.Print();
//	system("pause");
//	return 0;
//}
////��������id���������id���������أ��������ʾ���ã�Ĭ�Ϸ��ʵ����������id


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
//	//b.func();//������ò��У���Ȼ˵������̳��˻����е��޲�func���������ڹ��������أ��������������У�Ĭ�ϵ����Ǵ��ε�func(int i);
//	b.A::func();//���һ��Ҫ���ʣ��Ӹ����������
//	b.func(10);
//	system("pause");
//	return 0;
//}
////�������ĵ�func���������func���������أ����������أ������и���������������ͬһ��������


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
//	string _name;//����
//};
//class Student :public Person
//{
//public:
//	Student(const char* name,int num)//������Ĺ��캯��
//		:Person(name)
//		, _num(num)
//	{
//	}
//	Student(const Student& s)//������Ŀ������캯��
//		:Person(s)//����������󸳸�������󣬻ᷢ����Ƭ��Ϊ
//		,_num(s._num)
//	{
//	}
//	Student& operator=(const Student& s)//operator=��ֵ
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);//�����ഫ������,���������ʾ���ã��������ʾ������ĸ�ֵ�Ļ������������ṹ���ض��壬�����operator=�ᱻ���أ��ǵ�������
//			_num = s._num;
//		}
//	
//		return *this;
//	}
//	~Student()//����
//	{
//		//~Person();//������������������͸�����������������أ����Ե�������~Person()��~Student()�ײ���Ķ���һ����destructor�ĺ�������������ͬ������������
//		//Person::~Person();//��Ҫ��ʾ���ã������ֻ���һ�����⣬����������2��
//		//����涨�������಻����ʾ��ȥ���������������
//	}
//protected:
//	}
//	int _num;//ѧ��
//};
//
//int main()
//{
//	Student s("С��Ů",20);
//	Student s2("111", 12);
//	s2 = s;
//	system("pause");
//	return 0;
//}

//�������⣺ʵ��һ�����ܱ��̳е���

////������:c++98�� �����캯��˽�л�
//class NonInherit
//{
//private:
//	NonInherit()//����˽�л������������ǲ��ɼ���
//	{}
//};
////������Ĺ��캯�����������Ĺ��캯��ȥ��ʼ����һ���ѻ���Ĺ��캯��˽�У�������Ͷ��岻�������ˣ�Ҳ����˵����Ͳ��ܱ��̳���
//
////������:c++11�У�ʹ��final������Ϊ�����࣬Ҳ���Ա�֤���಻�ᱻ�̳�
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
//	string _name;//����
//};
//class Student :public Person
//{
//protected:
//	int _num;//ѧ��
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;//���Է���Person���name����ΪDisplay��Person����Ԫ��ͻ�������������
//	cout << s._num << endl;//���ܷ��ʣ���ȻStudent�̳���Person��������Ԫ��ϵ���ܱ��̳�
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
//	int _num;//ѧ��
//};
//
//class Graduate :public Student
//{
//protected:
//	int _grade;//�ɼ�
//};
//
//int main()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " ���� :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " ���� :" << Person::_count << endl;
//	system("pause");
//	return 0;x
//
//}


////���μ̳�
//class Person
//{
//public:
//	string _name;//����
//};
//class Student :public Person
//{
//protected:
//	int _num;//ѧ��
//};
//
//class Student :public Person
//{
//protected:
//	int _id;//ְ�����
//};
//class Assistant :public Student, public Teacher
//{
//protected:
//	string _major;//���޿γ�
//};
//int main()
//{
//	//�������ж����ԣ��޷���ȷ֪�����ʵĵ�������һ��
//	Assistant a;
//	a._name = "mary";//�����������ʣ���ΪAssistantͬʱ�̳���Student,Teacher����֪��Ҫ���ʵ�name��������һ������ĳ�Ա����
//
//	// ���һ��Ҫ���ʣ�����Ҫ��ʾָ������ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷�����������������̳�
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