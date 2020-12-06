#ifndef __FOODITEM_HPP__
#define __FOODITEM_HPP__
#include <vector>
#include <iostream>
#include "tag.hpp"
using namespace std;

class FoodItem : public Tag{
    private:
        string name;
    public:
        FoodItem(string name);
        void display() const;
};

#endif