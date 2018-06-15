#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	ofstream out("Exercise13_1.txt");
	if (!out) {
		out.open("Exercise13_1.txt");
		cout << "Creating new file"<<endl;
	}
	cout << "Saving random numbers into file" << endl;

	srand(time(NULL));
	int randal = 0;
	for (int i = 0; i < 100; i++) {
		randal = rand();
		out << randal << " ";
	}
	cout << "Done." << endl;

	return 0;
}