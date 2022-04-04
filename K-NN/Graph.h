#ifndef GRAPH_H
#define GRAPH_H
#include "Distance.h"
#include "Point.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <map>
#include <iomanip>
using namespace std;
class Graph
{
public:
	Graph(vector<Distance> points);
	~Graph();
	void drawGraph(vector<Distance> points);
protected:
};

#endif