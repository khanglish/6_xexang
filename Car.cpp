
#include "Car.h"
#define V1 36 // V1 hoac V2 = 0 thi chuong trinh se chay sai 
#define V2 48
using namespace std;

Car::Car(string id) { // con GPS thi mac dinh la 0,0
    this->id = id;
    Capacity = 20;
    Petrol = 10;
    Waste = 0.1;
}

Car::Car(string id, double Petrol, double Capacity, double Waste, Point GPS){ 
    this->id = id;
    this->Petrol = Petrol;
    this->Capacity = Capacity;
    this->Waste = Waste;
    this->GPS = GPS;
}

double Car::addPetrol(double Petrol){
    const double epsilon = 0.0000001;
    if(this->Petrol > Capacity || Capacity - this->Petrol < epsilon){
	return 0;
    }
    else{
	double sum = this->Petrol + Petrol;
	if(sum > this->Capacity){
	    this->Petrol = this->Capacity;
	    return this->Capacity - this->Petrol;
	}
	else{
	    this->Petrol += Petrol;
	    return Petrol;
	}
    }
}

Time Car::run(Point Des){
    srand(time(NULL));
    int V = V1 + rand() % (V2-V1+1);
    double distance = this->GPS.distanceTo(Des);
    if(distance > this->getDistance()){
	return Time(0);
    }
    if(V==0){
	cout << "Van toc bang 0" << endl;
	return Time(0);
    }
    else{
	this->Petrol -= this->Waste * distance;
	this->GPS = Des;
	double t = (distance / V )* 3600;
	unsigned int time = (unsigned int) nearbyint(t); 
	return Time(time);
    }
}

Point Car::getGPS(){
    return GPS;
}

double Car::getDistance(){
    return Petrol / Waste;
}

double Car::getCapacity(){
    return this->Capacity;
}
Car::~Car() {
}

