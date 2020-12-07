#include "../header/factory.hpp"

UberEatsFactory::UberEatsFactory(Restaurant* rest) : Factory(rest) {}

PriceBreakdown* UberEatsFactory::createPriceBreakdown() {
    pbd = new UEPriceBreakdown();
    return pbd;
}

void UberEatsFactory::createTimeBreakdown() {
    tbd = new UETimeBreakdown();
    return tbd;
}

// void UberEatsFactory::createRestaurantList() {

// }

DoorDashFactory::DoorDashFactory(Restaurant* rest) : Factory(rest) {}

void DoorDashFactory::createPriceBreakdown() {
    pbd = new DDPriceBreakdown();
    return pbd;
}

void DoorDashFactory::createTimeBreakdown() {
    tbd = new DDTimeBreakdown();
    return tbd;
}

// void DoorDashFactory::createRestaurantList() {

// }