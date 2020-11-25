#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

/*#include API info*/


class Factory {
    public:
        /* Pure Virtual Functions */
        virtual void createPriceBreakdown() = 0;
        virtual void createTimeBreakdown() = 0;
        virtual void createRestaurantList() = 0;
};

class UberEatsFactory : public Factory{
    public:
        virtual void createPriceBreakdown() = 0;
        virtual void createTimeBreakdown() = 0;
        virtual void createRestaurantList() = 0;
};

class DoorDashFactory : public Factory{
    public:
        virtual void createPriceBreakdown() = 0;
        virtual void createTimeBreakdown() = 0;
        virtual void createRestaurantList() = 0;
};

#endif //__FACTORY_HPP__
