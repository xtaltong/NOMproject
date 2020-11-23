#include "../header/item.hpp"
#include "../header/restaurant.hpp"
#include <iostream>
using namespace std;

Restaurant::Restaurant() {}

void Restaurant::addItem(Item* item) {
    order.push_back(item);
}

void Restaurant::removeItem(Item* item) {
    for auto i : order {
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
    for auto i : order {
        order.at(i).display();
        cout << endl;
    }
}
