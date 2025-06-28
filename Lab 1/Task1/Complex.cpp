#include "Complex.h"

Complex::Complex() {
	real = 0;
	imaginary = 0;
}

Complex::Complex(double real, double img) {
	this->real = real;
	imaginary = img;
} 

Complex Complex::add(const Complex& c) {
	Complex temp;
	temp.real = real + c.real;
	temp.imaginary = imaginary + c.imaginary;
	return temp;
}

Complex Complex::subtract(const Complex& c) {
	Complex temp;
	temp.real = real - c.real;
	temp.imaginary = imaginary - c.imaginary;
	return temp;
}

Complex Complex::multiply(const Complex& c) {
	Complex temp;
	temp.real = (real * c.real) - (imaginary * c.imaginary);
	temp.imaginary = (real * c.imaginary) + (c.real * imaginary);
	return temp;
}

Complex Complex::divide(const Complex& c) {
	Complex temp;
	temp.real = ((real * c.real) - (imaginary * c.imaginary)) / ((c.real* c.real) + (c.imaginary * c.imaginary)) ;
	temp.imaginary = ((c.real * imaginary) - (real * c.imaginary)) / ((c.real * c.real) + (c.imaginary * c.imaginary));
	return temp;
}



Complex Complex::conjugate() {
	Complex temp;
	temp.real = real;
	temp.imaginary = -imaginary;
	return temp;
}

void Complex::display() {
	cout << real;
	if (imaginary < 0) {
		cout << " - " << -imaginary << "i" << endl;
	}
	else {
		cout << " + " << imaginary << "i" << endl;
	}
}

void Complex::setReal(int r) {
	real = r;
}
void Complex::setImg(int m) {
	imaginary = m;
}
double Complex::getReal() {
	return real;
}
double Complex::getImg() {
	return imaginary;
}