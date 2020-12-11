CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(NOM
	src/main.cpp
	src/category.cpp
	src/fooditem.cpp
	src/item.cpp
	src/restaurant.cpp
)

ADD_EXECUTABLE(test
	tests/unit_test.cpp
	tests/item_test.hpp
	src/item.cpp	
	tests/restaurant_test.hpp
	src/restaurant.cpp
	src/fooditem.cpp
	src/category.cpp
)

ADD_EXECUTABLE(compositeTest
	tests/composite_test.cpp
	tests/tag_test.hpp
    src/item.cpp
    src/restaurant.cpp
    src/fooditem.cpp
	src/category.cpp
)

ADD_EXECUTABLE(factoryTest
	tests/factory_test.cpp
	tests/deliveryFactory_test.hpp
    src/item.cpp
    src/restaurant.cpp
    src/fooditem.cpp
	src/category.cpp
	src/ddpricebreakdown.cpp
	src/uepricebreakdown.cpp
	src/ddtimebreakdown.cpp
	src/uepricebreakdown.cpp
	src/factory.cpp
)

ADD_EXECUTABLE(strategyTest
	tests/strategy_test.cpp
	tests/comparisonStrategy_test.hpp
    src/item.cpp
    src/restaurant.cpp
    src/fooditem.cpp
	src/category.cpp
	src/ddpricebreakdown.cpp
	src/uepricebreakdown.cpp
	src/ddtimebreakdown.cpp
	src/uepricebreakdown.cpp
	src/factory.cpp
	src/pricestrategy.cpp
	src/timestrategy.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_LINK_LIBRARIES(compositeTest gtest)
TARGET_LINK_LIBRARIES(factoryTest gtest)
TARGET_LINK_LIBRARIES(strategyTest gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
