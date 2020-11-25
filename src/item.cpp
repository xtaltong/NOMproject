#include "../header/item.hpp"
#include "../header/tag.hpp"
#include <iostream>
using namespace std;

Item::Item(){}

void Item::displayItem() const{
    cout << "Item: " << this->name << " Price: $" << this->price << endl;
}

bool Item::operator==(const Item &otherItem) const{
    if (this->name == otherItem.name && this->price == otherItem.price){
        return true;
    }
    else{
        return false;
    }
}

void Item::setName(string name){
    this->name = name;
}

string Item::getName() const{
    return name;
}

void Item::setPrice(double price){
    this->price = price;
}

double Item::getPrice() const{
    return price;
}