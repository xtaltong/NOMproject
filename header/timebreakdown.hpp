#ifndef __TIMEBREAKDOWN_HPP__
#define __TIMEBREAKDOWN_HPP__
#include <vector>
#include <iostream>
using namespace std;

struct Time {
	string timeType;
	int time;
	Time(string timeType, int time) : timeType(timeType), time(time) {};
};

class TimeBreakdown{
    private:

    public:
        TimeBreakdown();
        virtual void collectTimeMetaData() = 0;
};

#endif