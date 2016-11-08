#include "Time.h"

using namespace std;

Time::Time(unsigned int sum) {
    this->sum = sum;
    hh = sum / 3600;
    sum -= 3600 * hh;
    mm = sum / 60;
    sum -= 60 * mm;
    ss = sum;
}

Time::Time(unsigned int hh, unsigned int mm, unsigned int ss) {
    this->hh = hh;
    this->mm = mm;
    this->ss = ss;
    sum = hh * 3600 + mm * 60 + ss;
}

unsigned int Time::getHH() {
    return hh;
}

unsigned int Time::getMM() {
    return mm;
}

unsigned int Time::getSS() {
    return ss;
}

unsigned int Time::getSum() {
    return sum;
}

string Time::getSTime() {
    string th = "";
    string tm = "";
    string ts = "";
    if (hh < 10) {
	th = "0";
    }
    if (mm < 10) {
	tm = "0";
    }
    if (ss < 10) {
	ts = "0";
    }
    string a = th + to_string(hh)  + ":" + tm + to_string(mm) + ":" + ts + to_string(ss) ;
    return a;
}

bool Time::increase(Time T2) {
    unsigned int t = sum + T2.getSum();
    //if((t / 3600) < 24)
    //{
    sum = t;
    hh = t / 3600;
    t -= 3600 * hh;
    mm = t / 60;
    t -= 60 * mm;
    ss = t;
    return true;
    //}
    //return false;
}// demo neu hh > 24 thi bao loi 

bool Time::decrease(Time T2) {
    if (T2.getSum() > sum) {
	return false;
    } else {
	sum -= T2.getSum();
	unsigned int t = sum;
	hh = t / 3600;
	t -= 3600 * hh;
	mm = t / 60;
	t -= 60 * mm;
	ss = t;
    }
}

Time Time::add(Time T2) {
    unsigned int t = sum + T2.getSum();
    //if(t / 3600 >= 24){
    //Time result(0);
    //}
    //else{
    Time result(t);
    //}
    return result;
}

Time Time::minus(Time T2) {
    unsigned int t = sum - T2.getSum();
    //if(t < 0){
    //Time result(0);
    //return result;
    // }
    //else{
    Time result(t);
    return result;
    // }

}

int Time::compare(Time T2){
    if(sum == T2.getSum()){
	return 0;
    }
    if(sum == T2.getSum() < sum){
	return 1;
    }
    return -1;
}

Time::~Time(){
    
}