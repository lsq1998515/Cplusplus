#define _CRT_SECURE_NO_WARNINGS 1
#include<assert.h>
#include<iostream>
using namespace std;
class DATE //定义一个日期类
{
private:
	int _year;
	int _month;
	int _day;
public:
	DATE(int year = 2017, int month = 3, int day = 15)

		: _year(year)
		, _month(month)
		, _day(day)
	{
		assert(Isinvalid());//判断日期是否合法
		cout << " DATE(int year = 1995, int month = 4, int day =28)" << endl;
	}
	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	int GetMonthday(int year, int month)//定义一个每个月份天数的函数
	{
		char Month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//初始化月份天数数组
		if (month != 2)//判断二月份天数
		{
			return Month[month];
		}
		else
		{
			if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))//平年返回28天，闰年返回29天
			{
				return 29;
			}
			else
			{
				return 28;
			}
		}
	}
	bool Isinvalid()//判断日期的年月日是否合法
	{
		if ((_month > 0) && (_month<13) && (_day>0) && (_day <= GetMonthday(_year, _month)) && (_year > 0))
			return true;
		else
			return false;
	}
	DATE(const DATE& d)//构造拷贝函数
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	DATE operator+(int day)//运算符重载+号，判断初始化的日期加上需要加的天数
	{
		if (day < 0)
		{
			return *this - (-day);
		}
		DATE tmp = *this;
		tmp._day += day;
		while (tmp.Isinvalid() == false)
		{
			tmp._day -= GetMonthday(tmp._year, tmp._month);
			if (tmp._month == 12)//当月份等于12时，年份需要进一，月份置为一月
			{
				tmp._year++;
			}
			else
			{
				tmp._month++;
			}
			//mp._day -= GetMonthday(tmp._year, tmp._month);
		}
		return tmp;
	}


	DATE& operator++()// 直接引用,节省内存开销
	{
		return *this = *this + 1;
	}
	DATE operator++(int day)
	{
		DATE tmp = *this;
		*this = *this + 1;
		return tmp;
	}
	DATE operator-(int day)
	{
		if (day < 0)
			return *this + (-day);
		DATE tmp = *this;
		tmp._day -= day;
		while (tmp.Isinvalid() == false)
		{

			if (tmp._month == 1)
			{
				tmp._year--;
				tmp._month = 12;
			}
			else
			{
				tmp._month--;
			}
			tmp._day += GetMonthday(_year, _month);
		}

		return tmp;
	}


	DATE& operator--()
	{
		return *this = *this - 1;
	}
	DATE operator--(int day)
	{
		DATE tmp = *this;
		*this = *this - 1;
		return tmp;
	}
	bool operator>(const DATE& d)
	{
		if ((_year > d._year) || ((_year == d._year) && (_month > d._month)) || ((_year == d._year) && (_month == d._month) && (_day > d._day)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator==(const DATE&d)
	{
		if ((_year == d._year) && (_month == d._month) && (_day == d._day))
			return true;
		else
			return false;
	}
	bool operator>=(const DATE&d)
	{
		if ((*this > d) || (*this == d))
			return true;
		else
			return false;
	}

	bool operator<(const DATE&d)
	{

		return !(*this >= d);
	}
	bool operator!=(const DATE&d)
	{

		return !(*this == d);
	}
	bool operator<=(const DATE&d)
	{

		return !(*this > d);
	}
};
int main()
{
	DATE d1(2017, 2, 29);
	d1.Display();
	DATE d2;
	d2 = d1 - 100;
	d2.Display();
	d2 = d1 + 100;
	d2.Display();
	system("pause");


}
