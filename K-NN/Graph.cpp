#include "Graph.h"
#include "Distance.h"
#include "Point.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <map>
#include <iomanip>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;
Graph::Graph(vector<Distance> points)
{
	drawGraph(points);
}

Graph::~Graph()
{
}

void Graph::drawGraph(vector<Distance> points)
{
	
	cout << "AFTER K-NN OPERATION" << endl;
	Mat image(900, 1000, CV_8UC3, Scalar(255, 255, 255));
	// x and y Axes
	cv::line(image, cv::Point(25, 400), cv::Point(775, 400), Scalar(0, 0, 0), 2, 8);
	cv::line(image, cv::Point(400, 25), cv::Point(400, 775), Scalar(0, 0, 0), 2, 8);
	//Coordinate System Values 
	cv::putText(image, "-5", cv::Point(25, 395), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "-4", cv::Point(100, 395), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "-3", cv::Point(175, 395), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "-2", cv::Point(250, 395), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "-1", cv::Point(325, 395), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "0", cv::Point(405, 390), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "1", cv::Point(475, 395), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "2", cv::Point(550, 395), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "3", cv::Point(625, 395), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "4", cv::Point(700, 395), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "5", cv::Point(775, 395), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "5", cv::Point(408, 25), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "4", cv::Point(408, 100), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "3", cv::Point(408, 175), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "2", cv::Point(408, 250), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "1", cv::Point(408, 325), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "-1", cv::Point(408, 475), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "-2", cv::Point(408, 550), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "-3", cv::Point(408, 625), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "-4", cv::Point(408, 700), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::putText(image, "-5", cv::Point(408, 775), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	// Drawing Information Box 
	cv::line(image, cv::Point(840, 0), cv::Point(840, 90), Scalar(0, 0, 0), 2, 8);
	cv::line(image, cv::Point(840, 90), cv::Point(950, 90), Scalar(0, 0, 0), 2, 8);
	cv::line(image, cv::Point(950, 90), cv::Point(950, 0), Scalar(0, 0, 0), 2, 8);
	Rect r = Rect(850, 15, 10, 10);
	rectangle(image, r, Scalar(255, 0, 0), 1, 8, 0);
	cv::putText(image, "Category 0", cv::Point(870, 20), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	cv::line(image, cv::Point(845 , 35), cv::Point(865 , 35), Scalar(0, 0, 0), 1, 8);
	cv::line(image, cv::Point(845 , 35), cv::Point(855,45), Scalar(0, 0, 0), 1, 8);
	cv::line(image, cv::Point(865,35), cv::Point(855,45), Scalar(0, 0, 0), 1, 8);
	cv::putText(image, "Category 1", cv::Point(870, 40), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	Rect t = Rect(845,50,20,20);
	rectangle(image, t, Scalar(0, 0, 255), 1, 8, 0);
	cv::putText(image, "Category 2", cv::Point(870, 60), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	circle(image, cv::Point(855,80), 4, Scalar(0, 0, 255), -1, 8);
	cv::putText(image, "Samples", cv::Point(870, 85), cv::FONT_HERSHEY_DUPLEX, 0.3, cv::Scalar(0, 0, 0), 1, false);
	//Show the sorted points
	sort(points.begin(), points.begin() + 30, [](const Distance& p1, const Distance& p2) {
		return p1.getIndex() < p2.getIndex();
		});
	cout << setw(14) << "X" << setw(12) << "Y" << setw(8) << "GROUP" << endl;
	cout << "----------------------------------" << endl;
	for (int i = 0; i < points.size(); i++)
	{
		cout << "Point " << setw(2) << points[i].getIndex() << " " << setw(5) << points[i].getValue(0) << " " << setw(12) << points[i].getValue(1) << setw(8) << points[i].getGroup() << endl;
	}
	for (int i = 0; i < 30; i++)
	{
		std::string str2 = std::to_string(points[i].getIndex() + 1);
		string str1 = "Point ";
		string str = str1 + str2;
		if (points[i].getGroup() == 0)
		{
			Rect r = Rect(points[i].getValue(0) * 75 + 375 - 5+25, 750 - (points[i].getValue(1) * 75 + 375) - 5 + 25, 10, 10);
			rectangle(image, r, Scalar(255, 0, 0), 1, 8, 0);
			
		}

		else if (points[i].getGroup() == 1)
		{
			cv::line(image, cv::Point(points[i].getValue(0) * 75 + 375 - 5 + 25, 750 - (points[i].getValue(1) * 75 + 375) - 5 + 25), cv::Point(points[i].getValue(0) * 75 + 375 + 5 + 25, 750 - (points[i].getValue(1) * 75 + 375) - 5 + 25), Scalar(0, 0, 0), 1, 8);
			cv::line(image, cv::Point(points[i].getValue(0) * 75 + 375 - 5 + 25, 750 - (points[i].getValue(1) * 75 + 375) - 5 + 25), cv::Point(points[i].getValue(0) * 75 + 375 + 25, 750 - (points[i].getValue(1) * 75 + 375) + 5 + 25), Scalar(0, 0, 0), 1, 8);
			cv::line(image, cv::Point(points[i].getValue(0) * 75 + 375 + 5 + 25, 750 - (points[i].getValue(1) * 75 + 375) - 5 + 25), cv::Point(points[i].getValue(0) * 75 + 375 + 25, 750 - (points[i].getValue(1) * 75 + 375) + 5 + 25), Scalar(0, 0, 0), 1, 8);
			

		}
		else if (points[i].getGroup() == 2)
		{
			Rect r = Rect(points[i].getValue(0) * 75 + 375 - 10 + 25, 750 - (points[i].getValue(1) * 75 + 375) - 10 + 25, 20, 20);
			rectangle(image, r, Scalar(0, 0, 255), 1, 8, 0);
			

		}
		for (int i = 30; i < 40; i++)
		{
			circle(image, cv::Point(points[i].getValue(0) * 75 + 375 + 25, 750 - (points[i].getValue(1) * 75 + 375) + 25), 4, Scalar(0, 0, 255), -1, 8);
		}
		imshow("Image", image);
	}
	waitKey(0);
	return;
}