#pragma once
#include<iostream>
using namespace std;

class Date
{
	int day;
	int month;
	int year;
public:
	Date();
	Date(int, int, int);

	void addDays(int);
	void addMonth(int);
	void addYear(int);
	void subtractDays(int);
	void subtractMonth(int);
	void subtractYear(int);
	void displayDate();

	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setDate(int, int, int);

	int getDay();
	int getMonth();
	int getYear();
};

