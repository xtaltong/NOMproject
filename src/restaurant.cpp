#include "../header/item.hpp"
#include "../header/restaurant.hpp"
#include <iostream>
using namespace std;

Restaurant::Restaurant(string name) : name(name) {}

void Restaurant::addItem(Item* item) {
    order.push_back(item);
}

void Restaurant::removeItem(Item* item) {
    for (unsigned int i = 0; i < order.size(); i++) {
        if (order.at(i) == item) {
            order.erase(order.begin() + i);
            return;
        }
    }
}

Item* Restaurant::getItem(int index) const {
    return order.at(index);
}

void Restaurant::display() const {
    for (unsigned int i = 0; i < order.size(); i++) {
        order.at(i)->displayItem();
        cout << endl;
    }
}
