#ifndef __ITEM_TEST_HPP__
#define __ITEM__TEST_HPP__
#include "gtest/gtest.h"
#include "../header/item.hpp"

TEST(ItemTest, SetterGetterItemTest) {
    Item* test = new Item("Cookie", 1.00);
    
    EXPECT_EQ(test->getName(), "Cookie");
}
/*
TEST(ItemTest, BasicItemTest) {
    Item* test1 = new Item("Chicken Sandwich", 5.99);
    Item* test2 = new Item("Medium Drink", 1.99);
    
    EXPECT_EQ(test->getItem(0), item1);
    test->removeItem(item1);
    EXPECT_EQ(test->getItem(0), item2);
}*/

#endif
