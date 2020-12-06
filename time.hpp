#ifndef __TIME_HPP__
#define __TIME_HPP__

#include <string>
#include "strategy.hpp"
/*#include "delivery.hpp"
#include "restaurant.hpp"*/
using namespace std;

class Restaurant;

class TimeStrategy : public Strategy {
    public:
        /*Constructors*/
        TimeStrategy(){}

        /*Pure Virtual Functions*/
        void compare(Restaurant* restaurant){
            char uberTime = restaurant->timeBreakdown(uber);
            char dashTime = restaurant->timeBreakdown(dash); 
        }
        void print(){
            cout << "UberEats Delivery Time Estimate: " << uberTime;
            cout << "DoorDash Delivery Time Estimate: " << dashTime;
        }
};

#endif //__TIME_HPP__S