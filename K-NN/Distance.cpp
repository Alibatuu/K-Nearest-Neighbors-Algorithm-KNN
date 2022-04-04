#include "Distance.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <map>
#include <iomanip>
using namespace std;
Distance::Distance(int Index, vector<double>& Values, int Group, double Distance)
{
	setDistance(Distance);
	setIndex(Index);
	setGroup(Group);
	for (int i = 0; i < Values.size(); i++)
		this->valuess.push_back(Values[i]);
}

Distance::~Distance()
{
}


void Distance::setIndex(int a)
{
	index = a;
}

int Distance::getIndex() const
{
	return index;
}

void Distance::setGroup(int b)
{
	group = b;
}

int Distance::getGroup() const
{
	return group;
}

double Distance::getValue(int a) const
{
	return valuess[a];
}

void Distance::setDistance(double a)
{
	distance = a;
}

double Distance::getDistance() const
{
	return distance;
}