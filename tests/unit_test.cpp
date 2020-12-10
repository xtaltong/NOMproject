#include "gtest/gtest.h"

#include "item_test.hpp"
#include "tag_test.hpp"
//#include "restaurant_test.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
