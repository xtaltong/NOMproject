#ifndef __FOODITEM_HPP__
#define __FOODITEM_HPP__
#include <vector>
#include <iostream>
#include "tag.hpp"
using namespace std;

class FoodItem{
    private:
        double price;
        string name;
    public:
        FoodItem();
        void addTag(Tag* tag);
        void removeTag(int index);
        void display() const;
};

#endif