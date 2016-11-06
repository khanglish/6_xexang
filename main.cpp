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
	Time *a = new Time(15,18,32);
	Time *b = new Time(14,0,0);
	cout << a->getSTime() << endl;
	cout << b->getSTime() << endl;
	Time t = a->add(*b);
	cout << t.getSTime() << endl;
	a->minus(*b);
	cout << a->getSTime() << endl;
	a->increase(*b);
	cout << a->getSTime() << endl;
	a->decrease(*b);
	cout << a->getSTime() << endl;
	return 0;
}
//https://www.atlassian.com/git/tutorials/resetting-checking-out-and-reverting/summary
