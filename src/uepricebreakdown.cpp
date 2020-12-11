#include "../header/pricebreakdown.hpp"
#include "../header/uepricebreakdown.hpp"
#include "../header/restaurant.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

UEPriceBreakdown::UEPriceBreakdown() {}

void UEPriceBreakdown::collectPriceMetadata(Restaurant *rest) {
    ifstream fin;
    fin.open("../CSV/UberEats - Restauraunt List.csv");

    if(!fin.is_open()){
        throw runtime_error("Could not open File");
    }
    vector<string> row; 
    string line, word, temp, colname;

    while(fin >> temp){
        row.clear();
        getline(fin,line);
        istringstream ss(line);
        //checks first phrase in each column
        while(getline(ss, colname, ',')){
            //if name matches restaurant name, push row info into vector row
            if (colname == rest->getRestaurantName()){
                while(ss >> word){
                    row.push_back(word);    
                    if(ss.peek() == ',') ss.ignore();
                }
            }
        }
    }

    fin.close();
    //open restaurant csv
    //find items+price that correspond to order
    double subtotal = rest->getSubtotal();
    
    /*for (auto i : rest->getOrder()) {
        Fee item(rest->getOrder(i)->name, rest->getOrder(i)-> //find its price from UE files and save it to the item
    }*/

    double dFee = stod(row[2]) * stod(row[1]);
    //if subtotal(before tax) < 15
    double smallFee = 3;
    if(subtotal < 15){
        Fee small("Small Order Fee", smallFee);
        feeBreakdown.push_back(smallFee);
    }
        
    double servFee = subtotal * 1.15
    string taxpercent = "8.72%";
    subtotal = 108.72*subtotal;

    //tax+total = 108.72 x cost
    Fee tax("Tax", tFee);
    feeBreakdown.push_back(tax);
    //get handling
    //double hFee = handling x num Items
    Fee serviceFee("Service", servFee);
    feeBreakdown.push_back(servFee);
    //get deliveryfee
    //double dFee = fee x distance
    Fee deliveryFee("Delivery", dFee);
    feeBreakdown.push_back(deliveryFee);
    
    
    
    // {(handling, 1), (delivery, 5), (tax, 3)}
    // {(delivery, 4), (handling, 2), (tax, 3)}
}