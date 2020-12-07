#ifndef __STRATEGY_HPP__
#define __STRATEGY_HPP__

#include <string>
/*#include "delivery.hpp"
#include "restaurant.hpp"*/
#include "factory.hpp"
class Restaurant;

class Strategy {
    private:
        Factory* uefact = new UEDeliveryFactory();
        Factory* ddfact = new DDDeliveryFactory();
    public:
        /* Constructors */
        Strategy() { };


        /* Pure Virtual Functions */
        virtual void compare(Restaurant* restaurant) = 0;
        virtual void print();
};

#endif //__STRATEGY_HPP__

// client:
// DeliveryOptionFactory* ue = new UberEatsEdlivery;

// DeliveryOptionFactory* dd = new DoorDashDelivery;
// ue->pricebreakdown();
// dd->pricebreakdown();
// info = ue->extractinfo
// Strategy* s = new PriceStrategy();
// s->compare(info1, info2);
