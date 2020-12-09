#include "../header/pricebreakdown.hpp"
#include "../header/uepricebreakdown.hpp"
#include "../header/restaurant.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

UEPriceBreakdown::UEPriceBreakdown() {}

void UEPriceBreakdown::collectPriceMetadata(Restaurant *rest) {
    ifstream fin;
    fin.open("../CSV/UberEats - Restauraunt List.csv");

    if(!fin.is_open()){
        throw runtime_error("Could not open File");
    }
    vector<string> row; 
    string line, word, temp;
    while(fin >> temp){
        row.clear();
        getline(fin,line);
        istringstream ss(line);
        while(ss >> word){
            //finish later
        }
    }

    for (auto i : rest->getOrder()) {
        //find its price from DD files and save it to the item
    }
    //get handling
    //double hFee = handling x num Items
    Fee handlingFee("Handling", hFee);
    feeBreakdown.push_back(handlingFee);
    //get deliveryfee
    //double dFee = fee x distance
    Fee deliveryFee("Delivery", dFee);
    feeBreakdown.push_back(deliveryFee);
    //tax % x cost
    Fee tax("Tax", tFee);
    feeBreakdown.push_back(tax);
    //if less than 5 items
        //get small handling fee
        Fee small("Small Order Fee", sFee);
        feeBreakdown.push_back(sFee);

    // {(handling, 1), (delivery, 5), (tax, 3)}
    // {(delivery, 4), (handling, 2), (tax, 3)}
}