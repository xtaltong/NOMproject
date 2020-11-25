#ifndef __ITEM_HPP__
#define __ITEM_HPP__
#include <vector>
#include <iostream>
#include "tag.hpp"
using namespace std;

class Item{
    private:
        Tag* itemTag;
        string name;
        double price;
    public:
        Item();
        Item(string name, double price): name(name), price(price){};
        void setName(string name);
        string getName() const;
        void setPrice(double price);
        double getPrice() const;
        void displayItem() const;
        bool operator==(const Item &otherItem) const;
};

#endif