#ifndef __TAG_TEST_HPP__
#define __TAG_TEST_HPP__
#include "gtest/gtest.h"
#include "../header/restaurant.hpp"
#include "../header/item.hpp"
#include "../header/tag.hpp"
#include "../header/fooditem.hpp"
#include "../header/category.hpp"

TEST(FoodItemTest, FoodItemTest) {
	Tag* test = new FoodItem("Chicken Sandwich");
	Tag* newtag = new FoodItem("Drink");
	EXPECT_EQ(test->getName(), "Chicken Sandwich");
	test->display();
	cout << endl;
	test->addTag(newtag);
	EXPECT_EQ(test->find("Chicken Sandwich"), nullptr);
}

TEST(CategoryTest, BasicCategoryTest) {
	Tag* test = new Category("Sandwich");
	test->display();
	EXPECT_EQ(test->getName(), "Sandwich");
}

TEST(CategoryTest, ComplexCategoryTest) {
	Tag* test = new Category("Sandwich");
	EXPECT_EQ(test->find("Sandwich"), nullptr);
}
  
/*
TEST(TagTest, BasicTagTest) {
    Restaurant* test = new Restaurant("Chick-Fil-A");
    Item* item1 = new Item("Chicken Sandwich", 5.99);
    Item* item2 = new Item("Medium Drink", 1.99);
    test->addItem(item1);
    test->addItem(item2);
    item1->addFoodTag();
}
*/
#endif //__TAG_TEST_HPP__
