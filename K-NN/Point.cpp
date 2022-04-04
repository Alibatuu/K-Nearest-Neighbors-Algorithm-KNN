#include "Point.h"
#include "Distance.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <map>
#include <iomanip>
using namespace std;
Point::Point()
{

}

Point::~Point()
{
}

void Point::setValues()
{
	srand(time(0));
	vector<int> category(30);
	generate(category.begin(), category.end(), fillCategory);
	cout << "BEFORE TESTING" << endl;
	cout << setw(14) << "X" << setw(12) << "Y" << setw(8) << "GROUP" << endl;
	cout << "----------------------------------" << endl;
	for (int i = 0; i < 30; i++)
	{
		double firstt = rand15();
		double secondd = rand15();
		values.clear();
		values.push_back(firstt);
		values.push_back(secondd);
		cout << "Point " << setw(2) << i << ":" << setw(5) << values[0] << setw(12) << values[1] << setw(8) << category[i] << endl;
		Distance d(i, values, category[i], 0.0);
		points.push_back(d);
	}
	cout << endl;
}

int Point::fillCategory(void)
{
	static int p = 0;
	int hold;
	if (p < 10)
		hold = 0;
	else if (p < 20)
		hold = 1;
	else if (p < 30)
		hold = 2;
	p++;
	return hold;
}

double Point::rand15(void)
{
	double a = -5 + rand() % 11;
	return a;
}