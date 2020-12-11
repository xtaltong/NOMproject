#include "../header/pricebreakdown.hpp"
#include "../header/ddpricebreakdown.hpp"
#include "../header/restaurant.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "../header/factory.hpp"
// #include "../header/pricebreakdown.hpp"
// #include "../header/uepricebreakdown.hpp"
// #include "../header/ddpricebreakdown.hpp"
// #include "../header/timebreakdown.hpp"
// #include "../header/uetimebreakdown.hpp"
// #include "../header/ddtimebreakdown.hpp"

UberEatsFactory::UberEatsFactory(Restaurant* rest) : Factory(rest) {}

void UberEatsFactory::createPriceBreakdown() {
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
    
    double subtotal = rest->getSubtotal();
    //small order fee
    double smallFee = 3;
    //if subtotal(before tax) < $15, apply small order fee
    if(subtotal < 15){
        Fee small("Small Order Fee", smallFee);
        feeBreakdown.push_back(small);
    }
    double tFee = 0.0872*subtotal;
    //tax = 108.72 x cost
    Fee tax("Tax", tFee);
    feeBreakdown.push_back(tax);
    //service fee = handling x num Items
     //service fee = 15%    
    double servFee = subtotal * 1.15;
    Fee serviceFee("Service", servFee);
    feeBreakdown.push_back(serviceFee);
    //delivery Fee = fee x distance
    double dFee = stod(row[2]) * stod(row[1]);
    Fee deliveryFee("Delivery", dFee);
    feeBreakdown.push_back(deliveryFee);
    // pbd = new UEPriceBreakdown();
    // return pbd;

}

void UberEatsFactory::createTimeBreakdown() {
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
    
    // calculate time needed to prepare food
    int foodPrep = rest->getOrder().size() * 2;
    Time cooking("Cooking", foodPrep);
    timeBreakdown.push_back(cooking);

    int deliveryTime = stoi(row[4]);
    Time delivery("Delivery", deliveryTime);
    timeBreakdown.push_back(delivery);
    // tbd = new UETimeBreakdown();
    // return tbd;
}

// void UberEatsFactory::createRestaurantList() {

// }

DoorDashFactory::DoorDashFactory(Restaurant* rest) : Factory(rest) {}

void DoorDashFactory::createPriceBreakdown() {
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

    double subtotal = rest->getSubtotal();
    //small order fee
    double smallFee = 2.50;
    //if subtotal(before tax + promocode) < 15, apply small order fee
    if(subtotal < 10){
        Fee small("Small Order Fee", smallFee);
        feeBreakdown.push_back(small);
    }
    //promocode calculations: 20% off on orders > $15, up to $5
    if(subtotal > 15 && subtotal < 25){
        subtotal = .80 * subtotal;
    } 
    //tax = 8.72% x cost
    double tFee = 0.0872*subtotal;
    Fee tax("Tax", tFee);
    feeBreakdown.push_back(tax);
    //service fee = servicefee% x subtotal
    double servFee = subtotal * stod(column[4]);
    Fee serviceFee("Service", servFee);
    feeBreakdown.push_back(serviceFee);
    //delivery fee = fee x distance
    double dFee = stod(column[2]) * stod(column[1]);
    Fee deliveryFee("Delivery", dFee);
    feeBreakdown.push_back(deliveryFee);
    // pbd = new DDPriceBreakdown();
    // return pbd;
}

void DoorDashFactory::createTimeBreakdown() {
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

    // calculate time needed to prepare food
    int foodPrep = (rest->getOrder().size()) * 2;
    Time cooking("Cooking", foodPrep);
    timeBreakdown.push_back(cooking);

    int deliveryTime = stoi(column[4]);
    Time delivery("Delivery", deliveryTime);
    timeBreakdown.push_back(delivery);
    // tbd = new DDTimeBreakdown();
    // return tbd;
}

// void DoorDashFactory::createRestaurantList() {

// }
