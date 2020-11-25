#ifndef __FOODITEM_HPP__
#define __FOODITEM_HPP__
#include <vector>
#include <iostream>
#include "tag.hpp"
using namespace std;

class FoodItem{
    private:
        string name;
    public:
        FoodItem();
        void display() const;
};

#endif