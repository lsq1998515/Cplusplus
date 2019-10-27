#include "Date.h"

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
	return _cout;
}

istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year >> d._month >> d._day;
	return _cin;
}

void testDate()
{
	Date d(2018, 10, 27);
	Date d2(2020, 9, 13);
	/*d2 += -687;
	cout << d2 << endl;
	d2 + 30;
	cout << d2 << endl;
	++d2;
	++d2;
	++d2;
	++d2;
	++d2;
	d2++;
	--d2;
	d2--;*/
	cout << d2 - d << endl;
	cout << d - d2 << endl;

}

int main()
{
	testDate();
	return 0;
}
