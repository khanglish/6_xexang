#include "Car.h"
#include "PStation.h"
#include <vector>
using namespace std;

int main() {
    vector<Point> s; // chua diem du lich.
    s.push_back(Point(-2,-4));
    s.push_back(Point(-5,1));
    s.push_back(Point(-1,4));
    s.push_back(Point(5,3));
    
    PStation o(Point(0,0)); // khoi tao tram xang
    
    Point point_x1(-3,-1); // diem bat dau
    Car x1("1",10,30,0.1,point_x1);// khoi tao xe 1
    Time time_x1(0); // khoi tao tong thoi gian
    vector<Point> s_x1 = s; // khoi tao ban sao diem du lich
    
    while(true){
	x1.getGPS().print();
	if(s_x1.size() == 0){ // kiem tra con diem du lich hay khong
	    break;
	}
	vector<double> d_x1; // chua khoang cach den cac diem du lich con lai. 
	for(int i = 0; i < s_x1.size() ; i++ ){
	    d_x1.push_back(x1.getGPS().distanceTo(s_x1[i]));
	}
	int min = 0; // vi tri diem du lich gan nhat
	for(int i = 0; i < s_x1.size() ; i++ ){
	    if(d_x1[min] > d_x1[i]){
		min = i;
	    }
	}
	Time temp(x1.run(s_x1[min])); // cho xe chay den diem gan nhat
	if(temp.compare(Time(0)) == 0){ // neu khong du xang
	    if(o.sale(x1,x1.getCapacity())){//kiem tra co gan tram xang hay khong 
		continue; // neu gan thi do day binh va tiep tuc.
	    }
	    else{
		
		Time temp2(x1.run(o.getPlace())); // chay den tram xang
		if(temp2.compare(Time(0)) == 0){ // neu van khong du xang
		    break; // ket thuc
		}
		else{
		    o.sale(x1,x1.getCapacity());
		    time_x1.increase(temp2); // neu du thi cong thoi gian va chay den do xang
		}
	    }
	}
	else{
	    s_x1.erase(s_x1.begin() + min);
	    time_x1.increase(temp);
	}
	x1.getGPS().print();
	cout << time_x1.getSTime() << endl;
    }
    cout << time_x1.getSTime() << endl;
    return 0;
}
//https://www.atlassian.com/git/tutorials/resetting-checking-out-and-reverting/summary
