#ifndef __TIMEBREAKDOWN_HPP__
#define __TIMEBREAKDOWN_HPP__
#include <vector>
#include <iostream>
using namespace std;

class TimeBreakDown{
    private:

    public:
        TimeBreakDown();
        virtual void collectTimeMetaData() = 0;
};

#endif