#ifndef __TIMEBREAKDOWN_HPP__
#define __TIMEBREAKDOWN_HPP__
#include <vector>
#include <iostream>
using namespace std;

class TimeBreakdown{
    private:

    public:
        TimeBreakdown();
        virtual void collectTimeMetaData() = 0;
};

#endif