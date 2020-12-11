#include "../header/factory.hpp"
#include "../header/pricebreakdown.hpp"
#include "../header/uepricebreakdown.hpp"
#include "../header/ddpricebreakdown.hpp"
#include "../header/timebreakdown.hpp"
#include "../header/uetimebreakdown.hpp"
#include "../header/ddtimebreakdown.hpp"

UberEatsFactory::UberEatsFactory(Restaurant* rest) : Factory(rest) {}

PriceBreakdown* UberEatsFactory::createPriceBreakdown() {
//    pbd = new UEPriceBreakdown();
    return pbd;
}

TimeBreakdown* UberEatsFactory::createTimeBreakdown() {
    tbd = new UETimeBreakdown();
    return tbd;
}

// void UberEatsFactory::createRestaurantList() {

// }

DoorDashFactory::DoorDashFactory(Restaurant* rest) : Factory(rest) {}

PriceBreakdown* DoorDashFactory::createPriceBreakdown() {
    pbd = new DDPriceBreakdown();
    return pbd;
}

TimeBreakdown* DoorDashFactory::createTimeBreakdown() {
    tbd = new DDTimeBreakdown();
    return tbd;
}

// void DoorDashFactory::createRestaurantList() {

// }
