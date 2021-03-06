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

void mainMenu(){
    cout << "--Menu--" << endl;
    cout << "1. Check Menu" << endl;
    cout << "2. Add Food Item" << endl;
    cout << "3. Delete Food Item" << endl;
    cout << "4. View Order" << endl;
    cout << "0. Continue" << endl;
}

int main(){
    cout << "Welcome to NOM!" << endl;
    cout << "Please select a restaurant you would like to eat at: ";
    //display restaurant list
    cin >> restaurant;
    Restaurant* user = new Restaurant(restaurant);
    user->createMenu();
    cout << "Now it is time to select your order!" << endl;
    while (option != 0){
        mainMenu();
        //display menu
        cin >> option;
        if (option == 0){
            break;
        }
        else if (option == 1){
            user->printMenu();
        }
        else if (option == 2){
            cout << "Enter the food item number you want: ";
            int itemNumber = 0;
            cin >> itemNumber;
            Item* item = user->getMenuItem(itemNumber);
            user->addItem(item);
        }
        else if(option == 3){
            for (int i = 0; i < user->getOrder().size(); i++)
            {
                cout << i << " - ";
                user->getOrder().at(i)->displayItem();
            }
            cout << endl;
            cout << "Enter the food item you want to remove: ";
            int itemNumber = 0;
            cin >> itemNumber;
            user->removeItem(user->getItem(itemNumber));
        }
        else if(option == 4){
            user->display();
        }
    }
    cout << endl;
    cout << "Do you want cheapest price(0) or fastest time (1)? ";
    cin >> option;

    //strategy
    if (option == 0){
        //price comparison
    }

    if (option == 1){
        //time comparison
    }

    return 1;
}