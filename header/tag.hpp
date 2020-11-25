#ifndef __TAG_HPP__
#define __TAG_HPP__
#include <vector>
#include <iostream>
#include "item.hpp"
using namespace std;

class Tag{
    private:
       
    public:
        Tag();
        virtual void addTag(Tag* tag) = 0;
        virtual void removeTag(int index) = 0;
        virtual void display() const = 0;
};

#endif