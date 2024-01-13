#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

bool isLeapYear(int year);
int getCentury(int year);
int getYear(int year);
int getMonth(int month, int year);

int main()
{	
	int d, m, y, total;
	
	cout << "Enter the day, month number, and year seperated with a space: ";
	cin >> d >> m >> y;

	total = (d + (getMonth(m, y)) + (getYear(y)) + (getCentury(y)))%7;

	cout << "The date " << d << "/" << m << "/" << y << " is a ";

	if (total == 0)
		cout << "Sunday";

	if (total == 1)
		cout << "Monday";

	if (total == 2)
		cout << "Tuesday";

	if (total == 3)
		cout << "Wednesday";

	if (total == 4)
		cout << "Thursday";

	if (total == 5)
		cout << "Friday";

	if (total == 6)
		cout << "Saturday";
}

bool isLeapYear(int year)
{
	if (( year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		return true;
	else return false;
}

int getCentury(int year)
{
	year /=  100;
	year %= 4;
	int century, remainder, value;

	century = year / 100;
	remainder = century % 4;
	value = 3 - remainder;
	return (value * 2);
}

int getYear(int year)
{
	int lastDigits, number;

	lastDigits = year % 100;
	number = lastDigits / 4;
	return (lastDigits + number);
}

int getMonth(int month, int year)
{

	if (month == 1)
	{
		if (isLeapYear(year))
			return 6;
		else return 0;
	}

	if (month == 2)
	{
		if (isLeapYear(year))
			return 2;
		else return 3;
	}

	if (month == 3)
		return 3;

	if (month == 4)
		return 6;

	if (month == 5)
		return 1;

	if (month == 6)
		return 4;

	if (month == 7)
		return 6;

	if (month == 8)
		return 2;

	if (month == 9)
		return 5;

	if (month == 10)
		return 0;

	if (month == 11)
		return 3;

	if (month == 12)
		return 5;
}