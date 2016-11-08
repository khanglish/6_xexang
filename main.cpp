#include "Car.h"
#include "PStation.h"
#include <vector>
using namespace std;

int main() {
    vector<Point> s; // chua diem du lich.
    s.push_back(Point(-2, -4));
    s.push_back(Point(-5, 1));
    s.push_back(Point(-1, 4));
    s.push_back(Point(5, 3));

    PStation o(Point(0, 0)); // khoi tao tram xang
    
    vector<Car> x;
    
    Car x1("1", 10, 30, 0.1, Point(-3,-1)); // khoi tao xe 1
    Car x2("2", 20, 30, 0.2, Point(5,6));// khoi tao xe 2
    
    x.push_back(x1);
    x.push_back(x2);
    for (int j = 0; j < x.size(); j++) {
	Time time_x(0); // khoi tao tong thoi gian
	vector<Point> s_x = s; // khoi tao ban sao diem du lich
	while (true) {
	    if (s_x.size() == 0) { // kiem tra con diem du lich hay khong
		break;
	    }
	    x[j].getGPS().print();
	    vector<double> d_x; // chua khoang cach den cac diem du lich con lai. 
	    for (int i = 0; i < s_x.size(); i++) {
		d_x.push_back(x[j].getGPS().distanceTo(s_x[i]));
	    }
	    int min = 0; // vi tri diem du lich gan nhat
	    for (int i = 0; i < s_x.size(); i++) {
		if (d_x[min] > d_x[i]) {
		    min = i;
		}
	    }
	    Time temp(x[j].run(s_x[min])); // cho xe chay den diem gan nhat
	    if (temp.compare(Time(0)) == 0) { // neu khong du xang
		if (o.sale(x[j], x[j].getCapacity())) {//kiem tra co gan tram xang hay khong 
		    continue; // neu gan thi do day binh va tiep tuc.
		} else {

		    Time temp2(x[j].run(o.getPlace())); // chay den tram xang
		    if (temp2.compare(Time(0)) == 0) { // neu van khong du xang
			break; // ket thuc
		    } else {
			o.sale(x[j], x[j].getCapacity());
			cout << temp.getSTime() << endl << endl;
			time_x.increase(temp2); // neu du thi cong thoi gian va chay den do xang
		    }
		}
	    } else {
		s_x.erase(s_x.begin() + min);
		time_x.increase(temp);
	    }
	    x[j].getGPS().print();
	    cout << temp.getSTime() << endl << endl;
	}
	cout << "Thoi gian tong xe "<<j+1<<": " << time_x.getSTime() << endl  << endl;
    }

    return 0;
}
//https://www.atlassian.com/git/tutorials/resetting-checking-out-and-reverting/summary
