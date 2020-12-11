#ifndef __FACT_TEST_HPP__
#define __FACT_TEST_HPP__
#include "gtest/gtest.h"
#include "../header/restaurant.hpp"
#include "../header/item.hpp"
#include "../header/tag.hpp"
#include "../header/fooditem.hpp"
#include "../header/category.hpp"
#include "../header/pricebreakdown.hpp"
#include "../header/ddpricebreakdown.hpp"
#include "../header/uepricebreakdown.hpp"

TEST(PriceBreakdownTest, Test) {
    Restaurant* test = new Restaurant("Chick-Fil-A");
    PriceBreakdown* uePrices = new UEPriceBreakdown();
    PriceBreakdown* ddPrices = new DDPriceBreakdown();
    uePrices->collectPriceMetadata(test);
    ddPrices->collectPriceMetadata(test);
}

#endif //__FACT_TEST_HPP__
