#include "category.hpp"

Category::Category(string name) : name(name) {}

void Category::addTag(Tag* tag) {
    tags.push_back(tag);
}

void Category::removeTag(Tag* tag) {
    for (unsigned int i = 0; i < tags.size(); i++) {
        if (order.at(i) == item) {
            order.erase(order.begin() + i);
            return;
        }
    }
}

void Category::display() const {
    cout << name;
    for (auto i : tags) {
        cout << ", ";
        i->display();
        
    }
}

// {side}
// {American, fried}
//             {potato}
//                 fries
// side 
// American, fried
//             potato
//                 fries

// Fries: $1.00
// Tags (5): side, American, fried, potato, (fries)

// side, American, fried, potato, fries
// Tag* t = new Category("side");
// Tag* a = new Category("American");
// Tag* f = new Category("fried");
// Tag* p = new Category("potato");
// Tag* i = new FoodItem("fries");
// t->addTag(a);
// t->addTag(f);
// f->addTag(p);
// p->addTag(i);
// t->display();

// Item* item = new Item("fries");
// item.addTag("side")
// item.addTag("American", "side")