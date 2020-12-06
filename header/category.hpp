#ifndef __CATEGORY_HPP__
#define __CATEGORY_HPP__
#include <vector>
#include <iostream>
#include "tag.hpp"
using namespace std;

class Category{
    private:
        string name;
        vector<Tag*> tags;
    public:
        Category();
        virtual void addTag(Tag* tag);
        virtual void removeTag(Tag* tag);
        virtual void display() const;
};

#endif