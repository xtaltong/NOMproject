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
	cout << endl;
	EXPECT_EQ(test->getName(), "Sandwich");
}

TEST(CategoryTest, ComplexCategoryTest) {
	Tag* test = new Category("Sandwich");
	Tag* newTag = new FoodItem("Chicken Sandwich");
	EXPECT_EQ(test->find("Sandwich"), nullptr);
	test->addTag(newTag);
	EXPECT_EQ(test->find("Chicken Sandwich"), newTag);
	EXPECT_EQ(test->find("Sandwich"), nullptr);
	test->display();
	cout << endl;
}

TEST(CategoryTest, Complex2CategoryTest) {
	Tag* test = new Category("American");
	Tag* ckn = new Category("Chicken");
	Tag* sandwich = new Category("Sandwich");
	test->addTag(ckn);
	test->addTag(sandwich);
	EXPECT_EQ(test->find("Chicken"), ckn);
	EXPECT_EQ(test->find("Sandwich"), sandwich);
	test->display();
	cout << endl;
	Tag* foodItem = new FoodItem("Chicken Sandwich");
	sandwich->addTag(foodItem);
	EXPECT_EQ(test->find("Chicken Sandwich"), nullptr);
	EXPECT_EQ(sandwich->find("Chicken Sandwich"), foodItem);
	EXPECT_EQ(ckn->find("Chicken Sandwich"), nullptr);
	test->display();
	cout << endl;
}

TEST(CategoryTest, Complex3CategoryTest) {
	Tag* test = new Category("American");
        Tag* ckn = new Category("Chicken");
        Tag* sandwich = new Category("Sandwich");
	Tag* meat = new Category("Meat");
	test->addTag(meat);
	test->addTag(sandwich);
	meat->addTag(ckn);
	Tag* fast = new Category("Fast Food");
	test->addTag(fast);
	Tag* foodItem = new FoodItem("Chicken Sandwich");
	sandwich->addTag(foodItem);	
	test->display();
	cout << endl;
	EXPECT_EQ(test->find("American"), nullptr);
	EXPECT_EQ(test->find("Meat"), meat);
	EXPECT_EQ(meat->find("Chicken"), ckn);
}
 
TEST(TagTest, ComplexItemTagTest) {
	Item* item1 = new Item("Chicken Sandwich", 5.99);
	Item* item2 = new Item("Medium Drink", 1.99);
	Item* item3 = new Item("Waffle Fries", 2.99);
    	item1->addCategoryTag("American");
	item1->addCategoryTag("Meat", "American");
	item1->addCategoryTag("Sandwich", "American");
	item1->addCategoryTag("Chicken", "Meat");
	item1->addFoodTag("Chicken Sandwich", "Sandwich");
	item1->addCategoryTag("Fast Food");
	item2->addFoodTag("Drink");
	item3->addCategoryTag("Fried");
	item3->addCategoryTag("Potato", "Fried");
	item3->addFoodTag("Waffle Fries", "Potato");
	item3->addFoodTag("Golden");

	item1->displayItem();	
	item2->displayItem();
	item3->displayItem();
}

TEST(TagTest, ItemNoTagTest) {
	Item* test = new Item("Chicken Sandwich", 5.99);
	test->displayItem();
	EXPECT_EQ(test->getName(), "Chicken Sandwich");
	EXPECT_EQ(test->getPrice(), 5.99);
}

TEST(TagTest, ItemTagIntegrationTest) {
	Item* test = new Item("Chicken Sandwich", 5.99);
	test->addCategoryTag("American");
	Item* other = new Item("Chicken Sandwich", 5.99);
	
	EXPECT_EQ(*test == *other, true);
}

TEST(TagTest, RestaurantTagTest) {
	Restaurant* test = new Restaurant("Chick-Fil-A");
	Item* item1 = new Item("Chicken Sandwich", 5.99);
	Item* item2 = new Item("Medium Drink", 1.99);
	Item* item3 = new Item("Waffle Fries", 2.99);
	test->addItem(item1);
	test->addItem(item2);
	test->addItem(item3);

	item1->addCategoryTag("American");
        item1->addCategoryTag("Meat", "American");
        item1->addCategoryTag("Sandwich", "American");
        item1->addCategoryTag("Chicken", "Meat");
        item1->addFoodTag("Chicken Sandwich", "Sandwich");
	item3->addCategoryTag("Fried");
	item3->addCategoryTag("Potato", "Fried");

	test->display();

	EXPECT_EQ(test->getRestaurantName(), "Chick-Fil-A");
	EXPECT_EQ(test->getItem(0), item1);
		
}

TEST(TagTest, RestaurantTagTest2) {
	Restaurant* test = new Restaurant("Chick-Fil-A");
        Item* item1 = new Item("Chicken Sandwich", 5.99);
        Item* item2 = new Item("Medium Drink", 1.99);
        Item* item3 = new Item("Waffle Fries", 2.99);
        test->addItem(item1);
        test->addItem(item2);
        test->addItem(item3);

        item1->addCategoryTag("American");
        item1->addCategoryTag("Meat", "American");
        item1->addCategoryTag("Sandwich", "American");
        item1->addCategoryTag("Chicken", "Meat");
        item1->addFoodTag("Chicken Sandwich", "Sandwich");
        item3->addCategoryTag("Fried");
        item3->addCategoryTag("Potato", "Fried");
	
	test->removeItem(item2);

	EXPECT_EQ(test->getItem(0), item1);
	EXPECT_EQ(test->getItem(1), item3);
	EXPECT_EQ(test->getItem(2), nullptr);	

	test->removeItem(item1);
	
	EXPECT_EQ(test->getItem(0), item3);
	EXPECT_EQ(test->getItem(1), nullptr);

        test->display();
	
}

#endif //__TAG_TEST_HPP__
