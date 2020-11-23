#include "../header/item.hpp"
#include "../header/restaurant.hpp"
#include <iostream>
using namespace std;

Restaurant::Restaurant(string name) : name(name) {}

void Restaurant::addItem(Item* item) {
    order.push_back(item);
}

void Restaurant::removeItem(Item* item) {

}

Item* Restaurant::getItem(int index) const {
    return order.at(index);
}

void Restaurant::display() const {
    
}
