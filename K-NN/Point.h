#ifndef POINT_H
#define POINT_H
#include "Distance.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;
class Point
{
private:
	int index;
	int group;
	vector<double> values;
public:
	Point();
	~Point();
	void setValues();
	double rand15(void);
	static int fillCategory(void);
protected:
	vector<Distance> points;
};

#endif