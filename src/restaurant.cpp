#include "../header/item.hpp"
#include "../header/restaurant.hpp"
#include <iostream>
#include <vector>
using namespace std;

Restaurant::Restaurant(string name) : name(name) {}

void Restaurant::addItem(Item* item) {
    order.push_back(item);
}

void Restaurant::removeItem(Item* item) {
    for (unsigned int i = 0; i < order.size(); i++) {
        if (order.at(i) == item) {
            order.erase(order.begin() + i);
            return;
        }
    }
}

Item* Restaurant::getItem(int index) const {
    if (index >= 0 && index < order.size()) {
        return order.at(index);
    }
    else {
        return nullptr;
    }
}

void Restaurant::display() const {
    cout << "Restaurant: " << name << endl;
    cout << "ORDER" << endl;
    for (unsigned int i = 0; i < order.size(); i++) {
	order.at(i)->displayItem();
    }
    cout << endl;
}

string Restaurant::getRestaurantName() const{
    return name;
}

vector<Item *> Restaurant::getOrder() const{
    return order;
}

void Restaurant::printMenu(){
    ifstream fin;
    stringstream ss;
    ss << "../CSV/DoorDash - " << this->name << ".csv"; 
    string FILENAME = ss.str();
    fin.open(FILENAME);

    if(!fin.is_open()){
        throw runtime_error("Could not open File");
    }

    string line, word, temp, colname;
    
    getline(fin, line);

    stringstream ss(line);

    while (getline(ss, word, ',')){
        if (word != "Item"){
            this->menu.push_back(word);
        }
    }

    for (int i; i < menu.size(); i++){
        cout << i + 1 << ": " << menu.at(i) << endl; 
    }

}