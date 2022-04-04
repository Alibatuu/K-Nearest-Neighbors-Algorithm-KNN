#ifndef CALCULATE_H
#define CALCULATE_H
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <map>
#include <iomanip>
#include "Point.h"
#include "Distance.h"
using namespace std;
class Calculate : public Point
{
private:
	vector<double> testing;
public:
	Calculate();
	~Calculate();
	void knn(vector<Distance>& points);
protected:
};

#endif