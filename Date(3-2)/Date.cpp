#include "Date.h"

int Date::GetMonthDay(int year, int month)
{
	int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && (year % 4 == 0 && year % 100 != 0)
		|| year % 400 == 0)
	{
		return 29;
	}
	return monthArray[month];
}
Date::Date(int year , int month, int day)//构造
{
	//1.判断日期是否合法
	if (year >= 0 &&
		month > 0 && month<13&& 
		day>0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "Date Invalid" << endl;
	}
}
void Date::Print()
{
	cout << _year << "-" << _month << "-" <<_day<<endl;
}

Date::Date(const Date& d)//拷贝构造
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date Date::operator+(int days)const
{
	/*Date ret(*this);
	ret._day += days;
	while (ret._day > GetMonthDay(ret._year, ret._month))
	{
		if (ret._month == 12)
		{
			ret._year++;
			ret._month = 1;
		}
		ret._day -= GetMonthDay(ret._year, ret._month);
		ret._month++;
	}

	return ret;*/

	Date ret(*this);
	ret += days;

	return ret;
}
Date& Date::operator+=(int days)
{
	if (days<0)
	{
		return *this -= -days;
	}
	_day += days;
	while (_day > GetMonthDay(_year, _month))
	{
		if (_month == 12)
		{
			_year++;
			_month = 1;
		}
		_day -= GetMonthDay(_year, _month);
		_month++;
	}

	return *this;
}
Date Date::operator-(int days)const
{
	/*Date ret(*this);
	ret._day -= days;
	while (ret._day <= 0)
	{
		if (ret._month == 1)
		{
			ret._year--;
			ret._month = 12;
		}
		ret._month--;
		ret._day += GetMonthDay(ret._year, ret._month);
	}

	return ret;*/
	Date ret(*this);
	ret -= days;

	return ret;
}
Date& Date::operator-=(int days)
{
	if (days < 0)
	{
		return *this += -days;
	}
	_day -= days;
	while (_day <= 0)
	{
		if (_month == 1)
		{
			_year--;
			_month = 12;
		}
		_month--;
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
int Date::operator-(const Date& d)const//日期-日期
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
	int n = 0;
	while (min != max)
	{
		n++;
		min++;
	}

	return flag*n;
}
Date& Date::operator++()//前置++
{
	*this += 1;
	return *this;
}
Date Date::operator++(int)//后置++
{
	Date tmp(*this);
	*this += 1;
    return tmp;
}
Date& Date::operator--()//前置--
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)//后置--
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}
Date& Date::operator=(const Date& d)//赋值重载
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}
bool Date::operator>(const Date& d)const
{
	return _year > d._year
		|| _year == d._year&&_month > d._month
		|| _year == d._year&&_month == d._month&&_day > d._day;
}
bool Date::operator>=(const Date& d)const
{
	return *this > d || *this == d;
}
bool Date::operator<(const Date& d)const
{
	return !(*this >= d);
}
bool Date::operator<=(const Date& d)const
{
	return !(*this>d);
}
bool Date::operator==(const Date& d)const
{
	return _year == d._year
		 &&_month == d._month
		 &&_day == d._day;
}
bool Date::operator!=(const Date& d)const
{
	return !(*this == d);
}

Date::~Date()//析构
{
	//cout << "~Date()" << endl;
}

int main()
{
	/*Date d1(2019,3,2);
	d1.Print();
	Date d2 = d1 + 100;
	d2.Print();*/
	//cout << (d1 == d2) << endl;
	//cout << (d1 > d2) << endl;
	//cout << (d1 != d2) << endl;
	//cout << (d1 < d2) << endl;
	 
	 //d1.Print();
	//(d2 - 100).Print();
	/*(++d1).Print();
	(d1++).Print();

	(--d1).Print();
	(d1--).Print();*/
	Date d1(2019, 3, 2);
	Date d2(2019, 6, 10);
	d1.Print();
	cout<<d2-d1<<endl;
	

	system("pause");
	return 0;
}

