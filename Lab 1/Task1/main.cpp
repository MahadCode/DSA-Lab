#include"Complex.h"

int main() {
	Complex c1(10, -5);
	Complex c2(-13, 2);
	c1.display();
	c2.display();
	(c1.add(c2)).display();
	(c1.multiply(c2)).display();
	(c1.divide(c2)).display();
	(c1.conjugate()).display();
	(c2.conjugate()).display();
}