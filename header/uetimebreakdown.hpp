#ifndef __UETIMEBREAKDOWN_HPP__
#define __UETIMEBREAKDOWN_HPP__
#include <vector>
#include <iostream>
#include "timebreakdown.hpp"
using namespace std;

class UETimeBreakdown: public TimeBreakdown{
    private:

    public:
        UETimeBreakdown();
        void collectTimeMetaData();
};

#endif //__UETIMEBREAKDOWN_HPP__