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