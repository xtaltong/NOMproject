#ifndef __RESTAURANT_TEST_HPP__
#define __RESTAURANT_TEST_HPP__
#include "gtest/gtest.h"
#include "../header/restaurant.hpp"

TEST(RestaurantTest, GetNameRestaurantTest) {
    Restaurant* test = new Restaurant("Chick-Fil-A");
    EXPECT_EQ(test->getRestaurantName(), "Chick-Fil-A"); 
    delete test;
}

TEST(RestaurantTest, AddItemsRestaurantTest) {
    Restaurant* test = new Restaurant("Chick-Fil-A");
    Item* sandwich = new Item("Chicken Sandwich", 5.99);
    Item* fries = new Item("Waffle Fries", 2.99);
    test->addItem(sandwich);
    test->addItem(fries);
    test->display();
    EXPECT_EQ(test->getItem(0), sandwich);
    EXPECT_EQ(test->getItem(1), fries);
}

TEST(RestaurantTest, RemoveItemsRestaurantTest) {
    Restaurant* test = new Restaurant("Chick-Fil-A");
    Item* sandwich = new Item("Chicken Sandwich", 5.99);
    Item* drink = new Item("Medium Drink", 1.99);
    Item* fries = new Item("Waffle Fries", 2.99);
    test->addItem(sandwich);
    test->addItem(drink);
    test->addItem(fries);
    test->display();
    EXPECT_EQ(test->getItem(0), sandwich);
    test->removeItem(sandwich);
    EXPECT_EQ(test->getItem(0), drink);
    test->removeItem(fries);
    EXPECT_EQ(test->getItem(0), drink);
    test->removeItem(drink);
    test->display();
    EXPECT_EQ(test->getItem(0), nullptr);
}

TEST(RestaurantTest, GetOrderRestaurantTest) {
    Restaurant* rest = new Restaurant("Chick-Fil-A");
    Item* sandwich = new Item("Chicken Sandwich", 5.99);
    Item* drink = new Item("Medium Drink", 1.99);
    Item* fries = new Item("Waffle Fries", 2.99);
    rest->addItem(sandwich);
    rest->addItem(drink);
    rest->addItem(fries);
    vector<Item *> test = rest->getOrder();
    EXPECT_EQ(test.at(0), sandwich);
    EXPECT_EQ(test.at(1), drink);
    EXPECT_EQ(test.at(2), fries); 
}

#endif //__RESTAURANT_TEST_HPP__
