#include "Time.h"

using namespace std;

Time::Time(unsigned int sum){
    hh = sum / 3600;
    sum -= 3600 * hh;
    mm = sum / 60;
    sum -= 60 * mm;
    ss = sum;
    this->sum = sum;
    if(hh >= 24)
    {
	hh = hh / 24 - 1;
    }
}

Time::Time(unsigned int hh, unsigned int mm, unsigned int ss){
    this->hh = hh;
    this->mm = mm;
    this->ss = ss;
    sum = hh * 3600 + mm * 60 +ss;
}

unsigned int Time::getHH(){
    return hh;
}

unsigned int Time::getMM(){
    return mm;
}

unsigned int Time::getSS(){
    return ss;
}

string Time::getSTime(){
    string th = "";
    string tm = "";
    string ts = "";
    if(hh < 10){
	th = "0";
    }
    if(mm < 10){
	tm = "0";
    }
    if(ss < 10){
	ts = "0";
    }
    string a = to_string(hh) + th +":" + to_string(mm) + tm + ":" + to_string(ss) + ts; 
    return  a;
}

bool Time::increase(Time T2){
    
    return true;
}

bool Time::decrease(Time T2){
    
    if(hh < T2.getHH() ){
    }
}
Time Time::add(Time T2){
    
}

Time  Time::minus(Time T2){
    
}


