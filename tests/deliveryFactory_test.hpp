#ifndef __FACT_TEST_HPP__
#define __FACT_TEST_HPP__
#include "gtest/gtest.h"
#include "../header/restaurant.hpp"
#include "../header/item.hpp"
#include "../header/tag.hpp"
#include "../header/factory.hpp"
#include "../header/fooditem.hpp"
#include "../header/category.hpp"

TEST(FactoryTest, BasicFactoryTest) {
    Restaurant* test = new Restaurant("Chick-Fil-A");
    Factory* fact = new UberEatsFactory(test);
    fact->createPriceBreakdown();
}

#endif //__FACT_TEST_HPP__
