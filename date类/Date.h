#include <iostream>
using namespace std;

class Date
{
public:
	friend ostream& operator<<(ostream& out, Date& d);//友元函数
	friend istream& operator>>(istream& in, Date& d);//友元函数

	Date(int year = 2018, int month = 11, int day = 13);//构造函数
	Date(const Date& d);//拷贝构造函数
	void Print();
	Date& operator=(const Date& d);//赋值重载
	~Date();//析构函数
	Date operator+(int days);
	Date operator-(int days);
	Date operator+=(int days);
	Date operator-=(int days);
	int operator-(const Date& d);//日期减去日期
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
private:
	int _year;
	int _month;
	int _day;
};



