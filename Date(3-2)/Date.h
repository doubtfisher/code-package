#include <iostream>

using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month);
	Date(int year = 1900, int month = 1, int day = 1);//����
	void Print();
	Date(const Date& d);//��������
	Date& operator=(const Date& d);//��ֵ����
	Date  operator+(int days)const;
	Date& operator+=(int days);
	Date  operator-(int days)const;
	Date& operator-=(int days);
	int operator-(const Date& d)const;
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;
	~Date();//����
	
private:
	int _year;
	int _month;
	int _day;
};