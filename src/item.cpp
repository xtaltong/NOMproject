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

void Item::addCategoryTag(string tag, string link = ""){
    Tag* t = new Category(tag);
    if (link != ""){
        for (int i = 0; i < itemTag->tags; i++)
    }
    
    else {
        itemTag->addTag(t);
    }
}

void addFoodTag(string tag, string link = ""){

}

// addTag(string tag, string link = "") [
        //     Tag* t = new Tag(tag);
        //     itemTag->addTag(t)
        //     if (link != "") {
        //         look for link
        //         add item under it
        //     }
        // ]