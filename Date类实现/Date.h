#include <iostream>
using namespace std;
class Date
{
public:
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);

	Date(int year = 1900, int month = 1, int day = 1)
	//Date(int year, int month, int day)
	{
		//判断日期的正确性
		if (year <= 0 || month <= 0 || month > 12
			|| day <= 0 || day > getDay(year, month))
		{
			this->_year = 1;
			this->_month = 1;
			this->_day = 1;
			cout << "日期非法， 重置为默认值: 1 - 1 - 1" << endl;
		}
		else
		{
			this->_year = year;
			this->_month = month;
			this->_day = day;
		}	
		cout << "Date()" << endl;
	}

	int getDay(int year, int month)
	{
		static int days[] = { 31, 28, 31, 30, 31,
			30, 31, 31, 30, 31, 30, 31 };
		int day = days[month - 1];
		if (month == 2)
		{
			if ((year % 4 == 0 && year % 100 != 0)
				|| (year % 400 == 0))
				++day;
		}
		return day;
	}
	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}
	Date& operator=(const Date& d){
		
		if (this != &d)
		{
			this->_day = d._day;
			this->_month = d._month;
			this->_year = d._year;
		}
		
		return *this;
	}

	// i = 10  i += 2  i ---> 12  
	Date& operator+=(int days)
	{
		if (days < 0)
			return *this -= (-days);
		_day += days;
		while (_day > getDay(_year, _month))
		{
			_day -= getDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				_month = 1;
				++_year;
			}
		}
		return *this;
	}
	Date& operator-=(int days)
	{
		if (days < 0)
			return *this += (-days);
		/**this = *this - days;
		return *this;*/

		_day -= days;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
			_day += getDay(_year, _month);
		}
		return *this;

	}
	Date operator+(int days)
	{
		Date tmp(*this);
		tmp += days;
		return tmp;
	}
	// date - days
	Date operator-(int days)
	{
		Date tmp(*this);
		tmp -= days;
		return tmp;
		/*Date tmp = *this;
		tmp._day = tmp._day - days;
		while (tmp._day <= 0)
		{
			--tmp._month;
			if (tmp._month == 0)
			{
				tmp._month = 12;
				tmp._year--;
			}
			tmp._day += getDay(tmp._year, tmp._month);
			
		}
		
		return tmp;*/
	}
	//++x
	Date& operator++()
	{
		return *this += 1;
	}
	//x++
	Date operator++(int)
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}
	//--x
	Date& operator--()
	{
		return *this -= 1;
	}
	//x--
	Date operator--(int)
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}


	int operator-(const Date& d)
	{
		Date min, max;
		int flag;
		int count = 0;
		if (*this < d)
		{
			min = *this;
			max = d;
			flag = -1;
		}
		else
		{
			min = d;
			max = *this;
			flag = 1;
		}
		while (min < max)
		{
			++min;
			++count;
		}
		return count * flag;
	}

	bool operator>(const Date& d)const
	{
		if (_year > d._year)
			return true;
		if (_year == d._year)
		{
			if (_month > d._month)
				return true;
			else if (_month == d._month)
			{
				if (_day > d._day)
					return true;
			}
		}
		return false;
	}
	bool operator>=(const Date& d)const
	{
		return *this > d || *this == d;
	}
	bool operator<(const Date& d)const
	{
		return !(*this >= d);
	}
	bool operator<=(const Date& d)const
	{
		return !(*this > d);
	}
	bool operator==(const Date& d)const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}

	~Date()
	{
		cout << "~Date()" << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
