#ifndef __DDTIMEBREAKDOWN_HPP__
#define __DDTIMEBREAKDOWN_HPP__
#include <vector>
#include <iostream>
#include "timebreakdown.hpp"
using namespace std;

class DDTimeBreakdown:TimeBreakDown{
    private:

    public:
        DDTimeBreakdown();
        void collectTimeMetaData();
};

#endif