#include "Complex.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	double complex[4];
	cout << "Enter the first set of complex numbers: ";
	cin >> complex[0] >> complex[1];
	cout << "Enter the second set of complex numbers: ";
	cin >> complex[2] >> complex[3];
	Complex set1(complex[0], complex[1]);
	Complex set2(complex[2], complex[3]);

	cout << "(" << set1.toString() << ") + (" << set2.toString() << ") = " << set1.add(set2).toString() << endl;
	cout << "(" << set1.toString() << ") - (" << set2.toString() << ") = " << set1.subtract(set2).toString() << endl;
	cout << "(" << set1.toString() << ") * (" << set2.toString() << ") = " << set1.multiply(set2).toString() << endl;
	cout << "(" << set1.toString() << ") / (" << set2.toString() << ") = " << set1.divide(set2).toString() << endl;
	cout << "|" << set1.toString() << "| = " << set1.abs() << endl;
}