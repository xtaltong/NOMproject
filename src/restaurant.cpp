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
    vector <string> tempV;
    string line, word, temp, colname;

    while (fin >> temp){
        getline(fin, line);

        stringstream ss(line);

        while (getline(ss, word, ',')){
            tempV.push_back(word);
        }

        if (tempV.at(0) == "Item"){
            tempV.erase(tempV.begin());
            for (int i = 1; i < tempV.size(); i++){
                Item* item = new Item(tempV.at(i), -1);
                menu.push_back(item);
            }
            tempV.clear();
            break;
        }
    }

    while (fin >> temp){
        getline(fin, line);

        stringstream ss(line);

        while (getline(ss, word, ',')){
            tempV.push_back(word);
        }

        if (tempV.at(0) == "Price"){
            tempV.erase(tempV.begin());
            for (int i = 1; i < tempV.size(); i++){
                menu.at(i)->setPrice(stod(tempV.at(i)));
            }
            tempV.clear();
            break;
        }
    }
    fin.close();

    for (int i = 0; i < menu.size(); i++){
        string food = menu.at(i)->getName();
        double price = menu.at(i)->getPrice();
        cout << food << ": $" << price << endl;
    }
}