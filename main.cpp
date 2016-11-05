#include <iostream>
#include <string>
#include "Point.h"
#include "Time.h"

using namespace std;

int main(){
	Point *diem1 = new Point(3,4);
	cout << diem1->getX() << endl;
	cout << diem1->getY() << endl;
	cout << diem1->getDistance() <<endl;
	return 0;
}
