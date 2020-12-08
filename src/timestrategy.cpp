#include "../header/timestrategy.hpp"
#include "../header/timebreakdown.hpp"

TimeStrategy::TimeStrategy(Restaurant* rest) Strategy(rest) {}

void TimeStrategy::compare(){
    TimeBreakdown* uepbd = uefact->createTimeBreakdown();
    TimeBreakdown* ddpbd = ddfact->createTimeBreakdown();
    vector<Fee> uefees = uepbd->collectTimeMetadata();
    vector<Fee> ddfees = ddpbd->collectTimeMetadata();

    cout << "Restaurant: " << rest->name << endl;
    cout << "Order: " << endl;
    // double orderSum = 0;
    for (auto i : rest->order) {
        cout << i->name " - $" << i->price << endl; 
        // orderSum += i->price;
    }
    cout << endl;
    // cout << "Cost - $" << orderSum << endl << endl;

    cout << "UberEats: " << endl;
    double timeSum = 0;
    for (auto i : ueTime) {
        cout << i->timeType << " - $" << i->duration << endl;
        timeSum += i->duration;
    }
    cout << endl;
    cout << "Total Time - " << timeSum << endl;
    cout << endl;
    
    cout << "DoorDash: " << endl;
    timeSum = 0;
    for (auto i : ddfees) {
        cout << i->timeType << " - $" << i->duration << endl;
        timeSum += i->duration();
    }
    cout << endl;
    cout << "Total Cost - " << timeSum << endl;
    cout << endl;
    // string uberPrice = restaurant->priceBreakdown(uber);
    // string dashPrice = restaurant->priceBreakdown(dash); 
}

// void PriceStrategy::print(){
//     cout << "UberEats Price: " << uberPrice;
//     cout << "DoorDash Price: " << dashPrice;
// }

// Restaurant: DisneyBakery
// Order:
// Waffle - $2.00
// Cookie - $1.00

// Cost - $3.00

// UberEats:
// Handling - $1.50
// Delivery - $5.00
// Tax - $3.00
// Small Order Fee - $1.00
// Total Cost - $13.50

// DoorDash:
// Handling - $1.00
// Delivery - $7.00
// Tax - $3.00
// Total Cost - $14.00