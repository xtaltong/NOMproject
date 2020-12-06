#include "fooditem.hpp"

FoodItem::FoodItem(string name) : name(name) {}

void FoodItem::display() const {
    cout << name;
}