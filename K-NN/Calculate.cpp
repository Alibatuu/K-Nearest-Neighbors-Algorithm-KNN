#include "Calculate.h"
#include "Point.h"
#include "Distance.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <map>
#include <iomanip>
using namespace std;
Calculate::Calculate()
{
	setValues();
	knn(points);
}

Calculate::~Calculate()
{
}

void Calculate::knn(vector<Distance>& points)
{
	testing.clear();
	double x;
	double y;
	int k;
	cout << "Enter K value: " << endl;
	cin >> k;
	for (int j = 0; j < 10; j++)
	{
		double first = rand15();
		double second = rand15();
		testing.clear();
		testing.push_back(first);
		testing.push_back(second);
		Distance d1(30+j, testing);
		points.push_back(d1);
		cout << "TEST POINT " << d1.getValue(0) << "   " << d1.getValue(1) << endl;
		for (int i = 0; i < 30; i++)
		{
			double dist = 0.0;
			dist = sqrt(pow(points[i].getValue(0) - d1.getValue(0), 2) + pow(points[i].getValue(1) - d1.getValue(1), 2));
			points[i].setDistance(dist);


		}

		cout << "\nBEFORE SORTING:\n" << endl;
		for (int i = 0; i < 30; i++)
		{
			cout << "Distance" << setw(3) << points[i].getIndex() << ": " << setw(7) << points[i].getDistance() << endl;
		}
		sort(points.begin(), points.begin() + 30, [](const Distance& p1, const Distance& p2) {
			return p1.getDistance() < p2.getDistance();
			});
		cout << "\nAFTER SORTING:\n" << endl;
		for (int i = 0; i < 30; i++)
		{
			cout << "Points " << setw(2) << points[i].getIndex() << " :X-> " << setw(3) << points[i].getValue(0) << " Y-> " << setw(3) << points[i].getValue(1) << " Distance: " << setw(8) << points[i].getDistance() << " Group: " << points[i].getGroup() << endl;
		}

		int freq1 = 0;
		int freq2 = 0;
		int freq3 = 0;
		for (int i = 0; i < k; i++)
		{
			if (points[i].getGroup() == 0)
				freq1++;
			else if (points[i].getGroup() == 1)
				freq2++;
			else if (points[i].getGroup() == 2)
				freq3++;
		}
		cout << "Freq for group 0: " << freq1 << endl;
		cout << "Freq for group 1: " << freq2 << endl;
		cout << "Freq for group 2: " << freq3 << endl;
		int m = std::max({ freq1,freq2,freq3 });
		cout << "Max: " << m << endl;
		if (std::max({ freq1,freq2,freq3 }) == freq1)
			points[30 + j].setGroup(0);
		else if (std::max({ freq1,freq2,freq3 }) == freq2)
			points[30 + j].setGroup(1);
		else
			points[30 + j].setGroup(2);
		cout << j+1 << ". test point's" << " group is " << points[30 + j].getGroup() << endl;
		cout << "----------------------------------" << endl;
		
	}
	Graph g(points);

}
