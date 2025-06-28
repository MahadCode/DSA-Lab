#pragma once
#include<iostream> 
using namespace std;

class Complex
{
	double real;
	double imaginary;

public:
	Complex();
	Complex(double, double);
	void setReal(int);
	void setImg(int);
	double getReal();
	double getImg();
	Complex add(const Complex& c);
	Complex subtract(const Complex& c);
	Complex multiply(const Complex& c);
	Complex divide(const Complex& c);
	Complex conjugate();
	void display();
};

