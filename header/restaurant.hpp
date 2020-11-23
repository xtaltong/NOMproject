#ifndef __RESTAURANT_HPP__
#define __RESTAURANT_HPP__

#include "item.hpp"
#include <vector>
#include <iostream>
using namespace std;

class Restaurant {
	private:
		string name;
		vector<Item *> order;

	public:
		Restaurant(string name);
		void addItem(Item* );
		void removeItem(Item* );
		void getItem(int ) const;
		void display() const;
};
#endif __RESTAURANT_HPP__
