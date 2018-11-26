#include "Date.h"

int GetMonthDay(int year, int month)//求每个月的天数
{
	static int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && year % 4 == 0 && year % 100 != 0
		|| year % 400 == 0)
	{
		return 29;
	}
	return monthArray[month];
}

Date::Date(int year, int month, int day)//构造函数
{
	//判断日期是否合法
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
Date::Date(const Date& d)//拷贝构造函数
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

ostream& operator<<(ostream& out, Date& d)//输出重载
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)//输入重载
{
	in >>d._year>>d._month >>d._day;
	return in;
}

Date& Date::operator=(const Date& d)//赋值重载
{
	//自己不能给自己赋值
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
Date::~Date()//析构函数
{
	;
}

Date Date::operator+(int days)
{
	//Date ret(*this);//拷贝构造一个d给ret
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
	//Date ret(*this);//拷贝构造一个d给ret
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
	//复用
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

int Date::operator-(const Date& d)//日期减去日期
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
Date& Date::operator++()//++d(前置++)
{
	*this += 1;

	return *this;
}
Date Date::operator++(int)//d++(后置++)
{
	Date tmp(*this);
	*this+= 1;
	return tmp;
}
Date& Date::operator--()//--d(前置--)
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)//d--(后置--)
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
	return *this > d || *this == d;//复用
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

