#ifndef __STRATEGY_HPP__
#define __STRATEGY_HPP__

#include <string>
/*#include "delivery.hpp"
#include "restaurant.hpp"*/
class Restaurant;

class Strategy {
    public:
        /* Constructors */
        Strategy() { };

        /* Pure Virtual Functions */
        virtual void compare(Restaurant* restaurant) = 0;
        virtual void print();
};

#endif //__STRATEGY_HPP__
