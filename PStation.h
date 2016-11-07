#ifndef PSTATION_H
#define PSTATION_H
#include "Car.h"

class PStation {
public:
    PStation();
    PStation(Point P2);
    bool sale(Car c, double Petrol);
    Point getPlace();
    ~PStation();
private:
    Point Place;
};

#endif /* PSTATION_H */

