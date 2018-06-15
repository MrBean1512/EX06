#include "CircleWithConstantMemberFunctions.h"
#include <vector>


Circle::Circle()
{
	radius = 1;
	numberOfObjects++;
}

Circle::Circle(double newRadius)
{
	radius = newRadius;
	numberOfObjects++;
}

double Circle::getArea() const
{
	return (3.14159*radius*radius);
}

double Circle::getRadius() const
{
	return radius;
}

void Circle::setRadius(double newRadius)
{
	radius = (newRadius >= 0) ? newRadius : 0;
}

int Circle::getNumberOfObjects()
{
	return numberOfObjects;
}

int Circle::compareTo(const Circle& circle2) const
{
	Circle temp = radius - circle2.getRadius();
	if (temp.getRadius() < 0)
		return -1;
	else if (temp.getRadius() == 0)
		return 0;
	else
		return 1;
}