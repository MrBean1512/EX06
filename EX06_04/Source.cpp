#include <iostream>
#include "CircleWithConstantMemberFunctions.h"
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std;

//wasn't sure where the assignment wanted me to order the objects (ie: vector or cout)
//so I decided to use a vector

///I'm not sure how to resolve the fatal error. it seems that it might be coming from the
///code that I copied from the textbook in listing 10.9
//edit: nvm the fatal error went away and I didn't change anything
//my computer broke and my current one acts a bit funky which may be related

int Sort(vector<Circle> &r);

int main()
{
	vector<Circle> r(10);
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
		r[i].setRadius(rand()%100);

	Sort(r);

	return 0;
}

int Sort(vector<Circle> &r)
{
	vector<Circle> temp1 = r;
	int size = r[0].getNumberOfObjects();
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		temp = i;
		for (int j = 0 + i; j < i; j++)
		{
			if (temp < temp1[j].getRadius())
			{
				temp = temp1[i].getRadius();
				temp1[i].setRadius(temp1[j].getRadius());
				temp1[j].setRadius(temp);
			}
		}
	}

	for (int i = 0; i < 10; i++)
		cout << r[i].getRadius() << endl;
}