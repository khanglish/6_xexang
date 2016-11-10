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

    Car x1("1", 10, 30, 0.1, Point(-3, -1)); // khoi tao xe 1
    Car x2("2", 20, 30, 0.2, Point(5, 6)); // khoi tao xe 2

    x.push_back(x1);
    x.push_back(x2);
    for (int j = 0; j < x.size(); j++) {
	Time time_x(0); // khoi tao tong thoi gian
	vector<Point> s_x = s; // khoi tao ban sao diem du lich
	while (true) {
	    if (s_x.size() <= 0) { // kiem tra con diem du lich hay khong
		break;
	    }
	    cout << "Diem bat dau: ";
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
	    if (x[j].getGPS().is(s_x[min])) {// xe dang o diem den tiep theo.
		cout << "Xe dang o diem den." << endl;
		s_x.erase(s_x.begin() + min);
	    } else {
		Time temp(x[j].run(s_x[min])); // cho xe chay den diem gan nhat, neu duoc thi thay se thay doi GPS
		if (x[j].getGPS().is(s_x[min])) { // chay duoc
		    cout << "Diem den: ";
		    x[j].getGPS().print();
		    cout << temp.getSTime() << endl << endl;
		    s_x.erase(s_x.begin() + min);
		    time_x.increase(temp);
		} else {
		    double temp_Petrol = o.sale(x[j], x[j].getCapacity());
		    if (temp_Petrol != 0) { //kiem tra co gan tram xang hay khong 
			cout << "Gan diem do xang nen do xang." << endl << endl;
		    } else { // khong chay duoc
			Time temp2(x[j].run(o.getPlace())); // chay den tram xang
			if (temp2.compare(Time(0)) == 0) { // neu van khong du xang
			    cout << "Khong du xang de chay den cay xang hoac diem ke tiep hoac do dung tich binh xang ." << endl << endl; // co the do dung tich khong du.
			    break; // ket thuc
			} else {
			    o.sale(x[j], x[j].getCapacity());
			    cout << "Chay den tram xang: ";
			    x[j].getGPS().print();
			    cout << temp2.getSTime() << endl << endl;
			    time_x.increase(temp2); // neu du thi cong thoi gian
			}
		    }
		}
	    }
	}
	cout << "Thoi gian tong xe " << j + 1 << ": " << time_x.getSTime() << endl << endl;
    }

    return 0;
}
