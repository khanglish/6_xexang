#include "Point.h"

using namespace std;

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

double Point::distanceTo(Point P2){
    return sqrt(pow(x-P2.getX() , 2) +pow(y-P2.getY(),2 ));
}

void Point::print(){
    cout << "( " << x << " , " << y << " )" << endl ;
}
Point::~Point(){

}