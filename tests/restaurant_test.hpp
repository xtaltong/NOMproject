#ifndef __RESTAURANT_TEST_HPP__
#define __RESTAURANT_TEST_HPP__
#include "gtest/gtest.h"
#include "../header/restaurant.hpp"
#include "item.hpp"
TEST(RestaurantTest, BasicRestaurantTest) {
    Restaurant* test = new Restaurant("Chick-Fil-A");
    Item* item1 = new Item("Chicken Sandwich", 5.99);
    Item* item2 = new Item("Medium Drink", 1.99);
    test->addItem(item1);
    test->addItem(item2);
    EXPECT_EQ(test->getItem(0), item1);
    test->removeItem(item1);
    EXPECT_EQ(test->getItem(0), item2);
}

#endif //__RESTAURANT_TEST_HPP__