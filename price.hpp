#ifndef __PRICE_HPP__
#define __PRICE_HPP__

#include <string>
#include "strategy.hpp"
/*#include "delivery.hpp"
#include "restaurant.hpp"*/
using namespace std;

class Restaurant;

class PriceStrategy : public Strategy {
    public:
        /*Constructors*/
        PriceStrategy(){}

        /*Pure Virtual Functions*/
        void compare(Restaurant* restaurant){
            string uberPrice = restaurant->priceBreakdown(uber);
            string dashPrice = restaurant->priceBreakdown(dash); 
        }
        void print(){
            cout << "UberEats Price: " << uberPrice;
            cout << "DoorDash Price: " << dashPrice;
        }
};

#endif //__PRICE_HPP__