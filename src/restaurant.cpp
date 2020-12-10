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
    if (index >= 0 && index < order.size()) {
        return order.at(index);
    }
    else {
        return nullptr;
    }
}

void Restaurant::display() const {
    cout << "Restaurant: " << name << endl;
    cout << "ORDER" << endl;
    for (unsigned int i = 0; i < order.size(); i++) {
	order.at(i)->displayItem();
    }
    cout << endl;
}

string Restaurant::getRestaurantName() const{
    return name;
}

vector<Item *> Restaurant::getOrder() const{
    return order;
}
