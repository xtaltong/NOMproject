#ifndef __CATEGORY_HPP__
#define __CATEGORY_HPP__
#include <vector>
#include <iostream>
#include "tag.hpp"
using namespace std;

class Category{
    private:
        vector<Tag*> tags;
    public:
        Category();
        void addTag(Tag* tag);
        void removeTag(int index);
        void display() const;
};

#endif