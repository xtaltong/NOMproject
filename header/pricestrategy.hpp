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
        virtual void compare(Restaurant* restaurant);
        virtual void print();
};

#endif //__PRICE_HPP__