CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

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

TARGET_LINK_LIBRARIES(test gtest)
TARGET_LINK_LIBRARIES(compositeTest gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
