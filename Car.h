#ifndef CAR_H
#define CAR_H
#include "Point.h"
#include "Time.h"

class Car{
private:
	std::string id; // to recognize car
	double Petrol;
	double Capacity;
	double Waste;
	Point GPS;
public:
	Car(std::string id);
	Car(std::string id, double Petrol, double Capacity, double Waste, Point GPS);
	double addPetrol(double Petrol); // co kiem tra khoang cach < 10m thi cho do xang
	Time run(Point Des);
	Point getGPS();
	double getDistance();
	double getCapacity();
	~Car();
};

#endif /* CAR_H */

