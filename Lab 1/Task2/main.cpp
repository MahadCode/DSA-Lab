#include"Date.h"

int main() {
	Date d1(26,11,2024);
	d1.displayDate();

	d1.addDays(4);
	d1.displayDate();

	d1.addDays(19);
	d1.displayDate();

	d1.subtractDays(19);
	d1.displayDate();

	d1.addDays(30600);
	d1.displayDate();
	
	d1.addDays(42781);
	d1.displayDate();

	Date obj11(1, 1, 2025);
	obj11.addDays(100000);  
	obj11.displayDate();

	Date obj2(1, 1, 2020);
	obj2.subtractDays(1);
	obj2.displayDate();

	Date obj1(15, 10, 2025);
	obj1.subtractDays(100000); 


}