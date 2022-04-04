#ifndef DISTANCE_H
#define DISTANCE_H
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <map>
#include <iomanip>
using namespace std;
class Distance
{
private:
	int index;
	int group;
	double distance;
	vector<double> valuess;
public:
	Distance(int index, vector<double>& Values, int group = -1, double Distance = 0.0);
	~Distance();
	void setIndex(int);
	int getIndex() const;
	void setGroup(int);
	int getGroup() const;
	double getValue(int) const;
	void setDistance(double);
	double getDistance() const;
};

#endif