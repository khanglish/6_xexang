#ifndef _time
#define _time

#include <string>

class Time{
private:
	unsigned int hh;
	unsigned int mm;
	unsigned int ss;
	unsigned int sum; // sum  = hh*3600 + mm*60 + ss
public:
	Time(unsigned int sum);
	Time(unsigned int hh, unsigned int mm,unsigned int ss);
	unsigned int getHH();
	unsigned int getMM();
	unsigned int getSS();
        unsigned int getSum();
	std::string getSTime();
	Time add(Time T2);
	Time minus(Time T2);
	bool increase(Time T2);
	bool decrease(Time T2);
};

#endif