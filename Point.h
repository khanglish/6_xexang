#ifndef _point
#define _point
#include <math.h>
#include <iostream>

class Point{
private:
	double x;
	double y;
public:
	Point();
	Point(double x, double y);
	Point(const Point &P2); // copy 
	double distanceTo(Point P2);
	double getX();
	double getY();
	void print();
	~Point();
};

#endif 