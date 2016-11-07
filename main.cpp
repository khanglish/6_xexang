#include "Car.h"
#include "PStation.h"
#include <vector>
using namespace std;

int main() {
    vector<Point> s;
    s.push_back(Point(-2,-4));
    s.push_back(Point(-5,1));
    s.push_back(Point(-1,4));
    s.push_back(Point(5,3));
    
    PStation o(Point(0,0));
    
    Point x1(-3,-1);
    Car xe1("1",10,30,0.1,x1);
    
    Time temp_x1(0);
    for(int i = 0; i < s.size(); i++){
	Point t(xe1.getGPS());
	t.print();
	Time t1(xe1.run(s[i]));
	if(t1.compare(Time(0)) == 0){
	    Time t2(xe1.run(o.getPlace()));
	    if(t2.compare(Time(0)) == 0 ){
		break;
	    }
	    else{
		temp_x1.add(t2);
	    }
	}
	else{
	    temp_x1.add(t1);
	}
    }
    cout << temp_x1.getSTime() << endl;
    return 0;
}
//https://www.atlassian.com/git/tutorials/resetting-checking-out-and-reverting/summary
