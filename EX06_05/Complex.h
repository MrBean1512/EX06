#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <string>
#include <iostream>
using namespace std;

//I'm not sure how to respond to error LNK2005 because they weren't consistently showing up

class Complex
{
public:
	Complex(double, double);
	Complex(double);
	Complex();
	double getNum1() const;
	double getNum2() const;

	Complex add(const Complex& complex2) const;
	Complex subtract(const Complex& complex2) const;
	Complex multiply(const Complex& complex2) const;
	Complex divide(const Complex& complex2)const;
	double abs()const;
	int compareTo(const Complex& complex2) const;
	bool equals(const Complex& complex2) const;
	string toString() const;

	Complex& operator+=(const Complex& complex2);
	Complex& operator-=(const Complex& complex2);
	Complex& operator*=(const Complex& complex2);
	Complex& operator/=(const Complex& complex2);

	double& operator[](int index);

	Complex& operator++();
	Complex& operator--();
	Complex operator++(int dummy);
	Complex operator--(int dummy);

	Complex operator+() { return (*this); }
	Complex operator-() { return (Complex(-cmplxNum1,-cmplxNum2)); }

	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator<<(istream&, Complex&);
private:
	double cmplxNum1;
	double cmplxNum2;

};


//my brother showed me how to conveniently define bools adjacent to their declarations
bool operator<(const Complex& op1, const Complex& op2) { return (op1.compareTo(op2)<0); }
bool operator<=(const Complex& op1, const Complex& op2) { return (op1.compareTo(op2)<=0); }
bool operator>(const Complex& op1, const Complex& op2) { return (op1.compareTo(op2)>0); }
bool operator>=(const Complex& op1, const Complex& op2) { return (op1.compareTo(op2)>=0); }
bool operator==(const Complex& op1, const Complex& op2) { return (op1.compareTo(op2)==0); }
bool operator!=(const Complex& op1, const Complex& op2) { return (op1.compareTo(op2)!=0); }

Complex operator+(const Complex& op1, const Complex& op2) { return (op1.add(op2)); }
Complex operator-(const Complex& op1, const Complex& op2) { return (op1.subtract(op2)); }
Complex operator*(const Complex& op1, const Complex& op2) { return (op1.multiply(op2)); }
Complex operator/(const Complex& op1, const Complex& op2) { return (op1.divide(op2)); }
#endif