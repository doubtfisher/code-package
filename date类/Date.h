#include <iostream>
using namespace std;

class Date
{
public:
	friend ostream& operator<<(ostream& out, Date& d);//��Ԫ����
	friend istream& operator>>(istream& in, Date& d);//��Ԫ����

	Date(int year = 2018, int month = 11, int day = 13);//���캯��
	Date(const Date& d);//�������캯��
	void Print();
	Date& operator=(const Date& d);//��ֵ����
	~Date();//��������
	Date operator+(int days);
	Date operator-(int days);
	Date operator+=(int days);
	Date operator-=(int days);
	int operator-(const Date& d);//���ڼ�ȥ����
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



