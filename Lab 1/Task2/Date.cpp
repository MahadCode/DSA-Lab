#include "Date.h"

Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

void Date::addYear(int years) {
	year = year + years;
}

void Date::addMonth(int months) {
	if (months >= 0) {
		int tempMonth = month + months;
		if ((tempMonth % 12) == 0) {
			addYear(((tempMonth - month) / 12));
			month = 12;
		}
		if (tempMonth > 12) {
			addYear(tempMonth / 12);
			month = tempMonth % 12;
		}
		else {
			month = tempMonth;
		}
	}
	else {
		cout << "Months can't be negative" << endl;
	}
}



void Date::addDays(int days) {
	if (days >= 0) {
		int tempday = day + days;
		if ( (tempday % 30) == 0) {
			addMonth(((tempday - day) / 30));
			day = 30;
		}
		else if (tempday > 30) {
			int extra = (tempday) / 30;
			addMonth(extra);
		    day = (tempday % 30);
		}
		else {
			day = tempday;
		}
	}
	else {
		cout << "Days can't be negative" << endl;
	}
}

void Date::subtractYear(int years) {
	year = year - years;
}

void Date::subtractMonth(int months) {
	if (months >= 0) {
		int tempMonth = month - months;
		if (tempMonth < 1) {

			int remaingMonth = months - month;
			int remaingYear = (remaingMonth / 12) + 1;
			subtractYear(remaingYear);
			month = 12 - (remaingMonth % 12);


		}
		else {
			month = tempMonth;
		}
	}
	else {
		cout << "Months can't be negative" << endl;
	}
}



void Date::subtractDays(int days) {
	if (days >= 0) {
		int tempday = day - days;
		if (tempday < 1) {

			int remaingDays = days - day;
			int remaingMonth = (remaingDays / 30) + 1;
			subtractMonth(remaingMonth);
			day = 30 - (remaingDays % 30);


		}
		else {
			day = tempday;
		}
	}
	else {
		cout << "Days can't be negative" << endl;
	}
}



void Date::displayDate() {
	cout << "Date: " << endl;
	if (month == 1) {
		cout << "January ";
	}
	else if(month == 2) {
		cout << "February ";
	}
	else if (month == 3) {
		cout << "March ";
	}
	else if (month == 4) {
		cout << "April ";
	}
	else if (month == 5) {
		cout << "May ";
	}
	else if (month == 6) {
		cout << "June ";
	}
	else if (month == 7) {
		cout << "July ";
	}
	else if (month == 8) {
		cout << "August ";
	}
	else if (month == 9) {
		cout << "September ";
	}
	else if (month == 10) {
		cout << "October ";
	}
	else if (month == 11) {
		cout << "November ";
	}
	else if (month == 12) {
		cout << "December ";
	}
	else {
		cout << "Error" << endl;
	}

	cout << day << ", " << year << endl;
}

void Date::setDay(int d) {
	day = d;
}
void Date::setMonth(int m) {
	month = m;
}
void Date::setYear(int y) {
	year = y;
}
void Date::setDate(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
}

int Date::getDay() {
	return day;
}
int Date::getMonth() {
	return month;
}
int Date::getYear() {
	return year;
}