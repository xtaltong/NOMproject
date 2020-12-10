#include "header/category.hpp"
#include "header/factory.hpp"
#include "header/fooditem.hpp"
#include "header/item.hpp"
#include "header/pricebreakdown.hpp"
#include "header/timebreakdown.hpp"
#include "header/restaurant.hpp"
#include "header/strategy.hpp"
#include "header/tag.hpp"
#include "header/timebreakdown.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;
string restaurant;
int option = 1;

int main(){
    cout << "Welcome to NOM!" << endl;
    cout << "Please select a restaurant you would like to eat at: ";
    //display restaurant list
    cin >> restaurant;
    Restaurant* user = new Restaurant(restaurant);
    cout << "Now it is time to select your order!" << endl;
    while (option != 0){
        user->printMenu();
        cout << "0: Exit" << endl;
        //display menu
        cin >> option;
        if (option == 0){
            break;
        }
        else{
            string temp = user->getMenu().at(option - 1);
            Item* item = new Item(temp, -1);
            user->addItem(item);
        }
    }
    cout << endl;
    cout << "Do you want cheapest price(0) or fastest time (1)? ";
    cin >> option;

    //strategy pattern

    return 1;
}