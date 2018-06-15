#include <iostream>
#include <fstream>
#include <string>
#include "Baby.h"
#include <vector>
using namespace std;

int main()
{
	cout << "Popularity of baby names from 2001 to 2010" << endl;
	fstream fileNames("fileNames.txt", ios::in | ios::out);
	if (!fileNames) {
		fileNames.open("fileNames.txt", ios::out);
		cout << "generating file names..." << endl;
		for (int i = 0; i < 9; i++)
			fileNames << "Babynameranking200" << (i + 1)<<".txt#";
		fileNames << "Babynameranking2010.txt";
	}

	fileNames.close();
	int year;
	char gender;
	string name;
	cout << "Enter a year: ";
	cin >> year;
	cout << "Enter a gender ('m' or 'f'): ";
	cin >> gender;
	cout << "Enter a name: ";
	cin >> name;

	string fileName;
	fileNames.open("fileNames.txt",ios::in);
	for (int i = 0; i < (year - 2000); i++) {
		getline(fileNames, fileName, '#');
	}
	fileNames.close();

	cout << "attempting to open" << fileName << endl;

	ifstream babies(fileName.c_str());
	if (!babies) {
		cout << "error" << endl;
		return 0;
	}

	string MtempName;
	string FtempName;
	int nullify;
	int tempRank;
	int count=0;
	for (int i = 0; i < 1000;i++)
	{
		if (babies.eof()) {
			cout << "That name is unranked" << endl;
			break;
		}
		babies >> tempRank >> nullify >> MtempName >> nullify >> FtempName;
		cout << nullify;

		if (gender == 'm' && name == MtempName)
		{
			cout << name << " is ranked #" << tempRank << " in the year " << year << endl;
			i++;
		}
		if (gender == 'f' && name == FtempName)
		{
			cout << name << " is ranked #" << tempRank << " in the year " << year << endl;
			i++;
		}
		else
		count++;
	}

	return 0;
}