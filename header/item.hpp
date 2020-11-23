#ifndef __ITEM_HPP__
#define __ITEM_HPP__
#include <vector>
#include <iostream>
#include "tag.hpp"
using namespace std;

class Item{
    private:
        Tag* itemTag;
    public:
        Item();
        void displayItem() const;
        bool operator==(const Item &otherItem) const;
};

#endif