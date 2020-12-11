#ifndef __RESTAURANT_HPP__
#define __RESTAURANT_HPP__

#include "item.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

class Restaurant {
	private:
		string name;
		vector<Item *> order;
		vector<Item *> menu; 

	public:
		Restaurant(string name);
		void addItem(Item* );
		void removeItem(Item* );
		Item* getItem(int ) const;
		void display() const;
		string getRestaurantName() const;
		vector<Item *> getOrder() const;
		void printMenu();
		vector<string> getMenu() const {return menu;};
};
#endif // __RESTAURANT_HPP__
