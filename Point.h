#ifndef _point
#define _point

class Point{
private:
	double x;
	double y;
public:
	Point();
	Point(double x, double y);
	Point(const Point &P2); // copy 
	double getDistance();
	double getX();
	double getY();
};

#endif 