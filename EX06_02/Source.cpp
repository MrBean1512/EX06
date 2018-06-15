#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string name;
	cout << "Enter a file name"<<endl<<
		"Try 'smash_mouth.txt' to test the program (it has 39 characters)" << endl;
	cin >> name;

	ifstream fluffy(name.c_str());
	if (fluffy.fail()) {
		cout << "That file does not exist. I pitty the fool." << endl;
		return 0;
	}

	int count = 0;
	string temp;
	while (!fluffy.eof())
	{
		fluffy >> temp;
		if (fluffy.fail()) break;
		count=count +temp.size();
	}

	cout << "The number of chars in this file is: " << count << endl;

	return 0;
}