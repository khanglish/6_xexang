#include "Point.h"
#include <math.h>

Point::Point(){
	x = 0;
	y = 0;
}

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}

Point::Point(const Point &P2){
	this->x = P2.x;
	this->y = P2.y;
} 

double Point::getX(){
	return x;
}

double Point::getY(){
	return y;
}

double Point::getDistance(){
	double result = sqrt(x*x+y*y);
}
