#include "pricestrategy.hpp"

PriceStrategy::PriceStrategy(){}

void PriceStrategy::compare(Restaurant* restaurant){
    string uberPrice = restaurant->priceBreakdown(uber);
    string dashPrice = restaurant->priceBreakdown(dash); 
}

void PriceStrategy::print(){
    cout << "UberEats Price: " << uberPrice;
    cout << "DoorDash Price: " << dashPrice;
}