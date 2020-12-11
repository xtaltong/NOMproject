#include "../header/pricebreakdown.hpp"
#include "../header/ddpricebreakdown.hpp"
#include "../header/restaurant.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

DDPriceBreakdown::DDPriceBreakdown() {}

void DDPriceBreakdown::collectPriceMetadata(Restaurant *rest) {
    ifstream fin;
    fin.open("../CSV/DoorDash - Restauraunt List.csv");

    if(!fin.is_open()){
        throw runtime_error("Could not open File");
    }
    vector<string> column; 
    string line, word, temp;
    getline(fin, line);
    istringstream ss(line);
    int colIdx = 0;
    while(ss >> word){
        if(word == rest->getRestaurantName()){
            column.push_back(word);
            break;
        }
        else{
            if(ss.peek() == ',') ss.ignore();
            colIdx++;
        }
    }
    while(getline(fin,line)){
        int columnIdx = 0;
        while(ss >> word){
            if(columnIdx == colIdx){
                column.push_back(word);
                if(ss.peek() == ',') ss.ignore();
            }
            else{
                columnIdx++;
            }
        }
    }


    fin.close();

    double subtotal = 0;
    //for (auto i : rest->getOrder()) {
        //find its price from UE files and save it to the item
    //}

    double dFee = stod(column[2]) * stod(column[1]);
    //if subtotal(before tax + promocode) < 15
    double smallFee = 2.50;
    if(subtotal < 10){
        Fee small("Small Order Fee", smallFee);
        feeBreakdown.push_back(smallFee);
    }
    //promocode
    if(subtotal > 15 && subtotal < 25){
        subtotal = .80 * subtotal;
    }  

    serviceFee = subtotal * stod(column[4]);
    string taxpercent = "8.72%";
    subtotal = 108.72*subtotal;

    //tax+total = 108.72 x cost
    Fee tax("Tax", tFee);
    feeBreakdown.push_back(tax);
    //get handling
    //double hFee = handling x num Items
    Fee serviceFee("Service", serviceFee);
    feeBreakdown.push_back(handlingFee);
    //get deliveryfee
    //double dFee = fee x distance
    Fee deliveryFee("Delivery", dFee);
    feeBreakdown.push_back(deliveryFee);
    
    
    // {(handling, 1), (delivery, 5), (tax, 3)}
    // {(delivery, 4), (handling, 2), (tax, 3)}
}
