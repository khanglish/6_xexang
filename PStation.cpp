#include "PStation.h"
#include "Car.h"

PStation::PStation() {
    this->Place = Point(0,0);
}

PStation::PStation(Point P2){
    this->Place = P2;
}

bool PStation ::sale(Car c, double Petrol){
    Point temp = c.getGPS();
    if(temp.distanceTo(this->Place) > 0.01){
	return false;
    }
    else{
	c.addPetrol(Petrol);
	return true;
    }
}

Point PStation::getPlace(){
    return this->Place;
}
PStation::~PStation() {
    
}

