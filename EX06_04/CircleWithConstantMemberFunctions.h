#ifndef CIRCLEWITHCONSTANTMEMBERFUNCTIONS_H_
#define CIRCLEWITHCONSTANTMEMBERFUNCTIONS_H_
#include <iostream>
using namespace std;

class Circle
{
public:
	Circle();
	Circle(double);
	double getArea() const;
	double getRadius() const;
	void setRadius(double);
	static int getNumberOfObjects();
	int compareTo(const Circle& complex2) const;

	//I can't figure out why these won't work, I tried them in EX06_05 and they worked fine
	//PT -- the difference here is that you have the functions inside the class (as member functions).
	//      move them outside the class, and I think they'll work just fine.
	// 16/20
	bool operator<(const Circle& op1, const Circle& op2) { return (op1.compareTo(op2)<0); }
	bool operator<=(const Circle& op1, const Circle& op2) { return (op1.compareTo(op2) <= 0); }
	bool operator>(const Circle& op1, const Circle& op2) { return (op1.compareTo(op2)>0); }
	bool operator>=(const Circle& op1, const Circle& op2) { return (op1.compareTo(op2) >= 0); }
	bool operator==(const Circle& op1, const Circle& op2) { return (op1.compareTo(op2) == 0); }
	bool operator!=(const Circle& op1, const Circle& op2) { return (op1.compareTo(op2) != 0); }
private:
	double radius;
	static int numberOfObjects;
};
#endif
