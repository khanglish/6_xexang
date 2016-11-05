#ifndef _khaibao
#define _khaibao

#include <string>
using namespace std;

class Point{
private:
	double x;
	double y;
public:
	Point();
	Point(double x, double y);
	Point(Point &P2); // copy 
	double getDistance();
	double getX();
	double getY();
};


class Time{
private:
	unsigned int hh;
	unsigned int mm;
	unsigned int ss;
	unsigned int sum; // sum  = hh*3600 + mm*60 + ss
public:
	Time(unsigned int sum);
	Time(unsigned int hh, unsigned int mm,unsigned int ss);
	unsigned int getHH();
	unsigned int getMM();
	unsigned int getSS();
	string getSTime();
	Time add(Time T2);
	Time minus(Time T2);
	bool increase(Time T2);
};

class Car{
private:
	string id; // to recognize car
	double Petrol;
	double Capacity;
	double Waste; 
public:
	Car(string id);
	Car(string id, double Petrol, double Capacity, double Waste);
	bool addPetrol(double Petrol); // co kiem tra khoang cach < 10m thi cho do xang
	Time run(Point Des);
	Point getGPS();
	double distance();
};
#endif