#include "category.hpp"

Category::Category(string name) : name(name) {}

void Category::addTag(Tag* tag) {
    tags.push_back(tag);
}

void Category::removeTag(Tag* tag) {
    for (unsigned int i = 0; i < order.size(); i++) {
        if (order.at(i) == item) {
            order.erase(order.begin() + i);
            return;
        }
    }
}

void Category::display() const {
    for (auto i : tags) {
        i->display();
    }
}