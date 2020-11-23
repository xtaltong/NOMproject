#include "../header/item.hpp"
#include "../header/tag.hpp"
#include <iostream>
using namespace std;

Item::Item(){}

void Item::displayItem() const{
    cout << "Item: " << itemTag->name << " Price: $" << itemTag->price << endl;
}

bool Item::operator==(const Item &otherItem) const{
    if (this->itemTag->name == otherItem.itemTag->name && this->itemTag->price == otherItem.itemTag->price){
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