#include "Date.h"

int GetMonthDay(int year, int month)//��ÿ���µ�����
{
	static int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && year % 4 == 0 && year % 100 != 0
		|| year % 400 == 0)
	{
		return 29;
	}
	return monthArray[month];
}

Date::Date(int year, int month, int day)//���캯��
{
	//�ж������Ƿ�Ϸ�
	if (year >= 0 && month>0 && month<13
		&& day>0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "Date Invaild" << endl;
	}
}
void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}
Date::Date(const Date& d)//�������캯��
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

ostream& operator<<(ostream& out, Date& d)//�������
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)//��������
{
	in >>d._year>>d._month >>d._day;
	return in;
}

Date& Date::operator=(const Date& d)//��ֵ����
{
	//�Լ����ܸ��Լ���ֵ
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
Date::~Date()//��������
{
	;
}

Date Date::operator+(int days)
{
	//Date ret(*this);//��������һ��d��ret
	//ret._day += days;
	//while (ret._day > GetMonthDay(ret._year, ret._month))
	//{
	//	ret._day -= GetMonthDay(ret._year, ret._month);
	//	if (ret._month == 12)
	//	{
	//		ret._year++;
	//		ret._month = 1;
	//	}
	//	else
	//	{
	//		ret._month++;
	//	}
	//}
	//return ret;
	Date ret(*this);
	ret += days;
	return ret;
}
Date Date::operator-(int days)
{
	//Date ret(*this);//��������һ��d��ret
	//ret._day += days;
	//while (ret._day <= 0)
	//{
	//	ret._day += GetMonthDay(ret._year, ret._month);
	//	if (ret._month == 1)
	//	{
	//		ret._year--;
	//		ret._month = 12;
	//	}
	//	else
	//	{
	//		ret._month--;
	//	}
	//}
	//return ret;
	//����
	Date ret(*this);
	ret -= days;
	return ret;
}
Date Date::operator+=(int days)
{
	if (days<0)
	{
		return *this -= -days;
	}
	_day += days;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		if (_month == 12)
		{
			_year++;
			_month = 1;
		}
		else
		{
			_month++;
		}
	}
	return *this;
}

Date Date::operator-=(int days)
{
	if (days < 0)
	{
		return *this += -days;
	}
	_day -= days;
	while (_day <= 0)
	{
		_day += GetMonthDay(_year, _month);
		if (_month == 1)
		{
			_year--;
			_month = 12;
		}
		else
		{
			_month--;
		}
	 }
	return *this;
}

int Date::operator-(const Date& d)//���ڼ�ȥ����
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int count = 0;
	while (min != max)
	{
		min++;
		count++;
	}

	return flag*count;

}
Date& Date::operator++()//++d(ǰ��++)
{
	*this += 1;

	return *this;
}
Date Date::operator++(int)//d++(����++)
{
	Date tmp(*this);
	*this+= 1;
	return tmp;
}
Date& Date::operator--()//--d(ǰ��--)
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)//d--(����--)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
bool Date::operator>(const Date& d)
{
	return  _year > d._year
		|| (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day);
}
bool Date::operator==(const Date& d)
{
	return _year == d._year&&
		_month == d._month&&
		_day == d._day;
}
bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;//����
}
bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}
bool Date::operator<=(const Date& d)
{
	return !(*this>d);
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

