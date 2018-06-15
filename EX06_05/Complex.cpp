#include "Complex.h"
#include <string>
#include <cmath>
#include <sstream>

Complex::Complex(double num1, double num2)
{
	cmplxNum1 = num1;
	cmplxNum2 = num2;
}

Complex::Complex(double num1)
{
	cmplxNum1 = num1;
	cmplxNum2 = 0;
}

Complex::Complex()
{
	cmplxNum1 = 0;
	cmplxNum2 = 0;
}

double Complex::getNum1() const
{
	return cmplxNum1;
}

double Complex::getNum2() const
{
	return cmplxNum2;
}

Complex Complex::add(const Complex& Complex2) const
{
	double a = cmplxNum1 + Complex2.getNum1();
	double b = cmplxNum2 + Complex2.getNum2();
	return Complex(a, b);
}

Complex Complex::subtract(const Complex& Complex2) const
{
	double a = cmplxNum1 - Complex2.getNum1();
	double b = cmplxNum2 - Complex2.getNum2();
	return Complex(a, b);
}

Complex Complex::multiply(const Complex& Complex2) const
{
	double a = (cmplxNum1 * Complex2.getNum2()) - (cmplxNum2 * Complex2.getNum1());
	double b = (cmplxNum1 * Complex2.getNum1()) + (cmplxNum2 * Complex2.getNum2());
	return Complex(a, b);
}

Complex Complex::divide(const Complex& Complex2) const
{
	double a = ((cmplxNum1 * Complex2.getNum2()) + (cmplxNum2 * Complex2.getNum1())) /
		((Complex2.getNum2() * Complex2.getNum2()) + (Complex2.getNum1() * Complex2.getNum1()));
	double b = ((cmplxNum1 * Complex2.getNum1()) - (cmplxNum2 * Complex2.getNum2())) /
		((Complex2.getNum2() * Complex2.getNum2()) + (Complex2.getNum1() * Complex2.getNum1()));
	return Complex(a, b);
}

double Complex::abs() const
{
	double a = sqrt(pow(cmplxNum1, 2) + pow(cmplxNum2, 2));	//this is the only place I use cmath (I think)
	return a;
}

int Complex::compareTo(const Complex& complex2) const
{
	Complex temp = subtract(complex2);
	if (temp.getNum1() < 0)
		return -1;
	else if (temp.getNum1() == 0)
		return 0;
	else
		return 1;
}

bool Complex::equals(const Complex& complex2) const
{
	if (compareTo(complex2) == 0)
		return true;
	else
		return false;
}

string Complex::toString() const
{
	stringstream ss;
	ss << cmplxNum1 <<" "<<cmplxNum2<<"i";
	return ss.str();
}

/////////////////////////this division marks the start of many of the overloaded operators (cause it looked kinda messy)

Complex& Complex::operator+=(const Complex& complex2)
{
	*this = add(complex2);
	return *this;
}

Complex& Complex::operator-=(const Complex& complex2)
{
	*this = subtract(complex2);
	return *this;
}

Complex& Complex::operator*=(const Complex& complex2)
{
	*this = multiply(complex2);
	return *this;
}

Complex& Complex::operator/=(const Complex& complex2)
{
	*this = divide(complex2);
	return *this;
}

double& Complex::operator[](int index)
{
	if (index == 0)
		return cmplxNum1;
	else
		return cmplxNum2;
}

Complex& Complex::operator++()
{
	cmplxNum1 *= 2;
	cmplxNum2 *= 2;
	return *this;
}

Complex& Complex::operator--()
{
	cmplxNum1 /= 2;
	cmplxNum2 /= 2;
	return *this;
}

Complex Complex::operator++(int dummy)
{
	Complex temp(cmplxNum1,cmplxNum2);
	cmplxNum1 *= 2;
	cmplxNum2 *= 2;
	return temp;
}

Complex Complex::operator--(int dummy)
{
	Complex temp(cmplxNum1, cmplxNum2);
	cmplxNum1 /= 2;
	cmplxNum2 /= 2;
	return temp;
}

ostream & operator<<(ostream &out, const Complex &complex)
{
	out << complex.cmplxNum1 << " " << complex.cmplxNum2;
	return out;
}

istream & operator<<(istream &in, Complex &complex)
{
	cout << "Enter the two values for the complex number: ";
	in >> complex.cmplxNum1 >> complex.cmplxNum2;
	return in;
}