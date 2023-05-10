#include <iostream>
#include "list_class.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

List list;

TEST_CASE("Test List PushBack method", "[List PushBack]") {
    INFO("Testing PushBack method");
	list.PushBack(55);
	list.PushBack(1);
    SECTION("List test section") {
        CHECK(list.Size() == 2);
		REQUIRE(list.PopBack() == 1);
    }
}

TEST_CASE("Test List PushFront method", "[List PushFront]") {
    INFO("Testing PushFront method");
    list.PushFront(17);
	list.PushFront(2);
    SECTION("List test section") {
        CHECK(list.Size() == 3);
		REQUIRE(list.PopFront() == 2);
    }
}

TEST_CASE("Test List PopBack method on empty list", "[List PopBack]") {
    list.Clear();
	INFO("Testing PopBack method on empty list");
    SECTION("List test section") {
        REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
    }
}

TEST_CASE("Test List PopFront method on empty list", "[List PopFront]") {
    list.Clear();
	INFO("Testing PopFront method on empty list");
    SECTION("List test section") {
        REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
    }
}

List new_list;

TEST_CASE("Custom test list class", "[List Custom]") {
	INFO("Testing list class in a custom way");
    SECTION("List test section") {
		new_list.PushBack(15);
		REQUIRE(new_list.Size() == 1);
		REQUIRE(new_list.PopBack() == 15);
		new_list.PushFront(5);
		new_list.PushBack(4);
		new_list.PopFront();
		REQUIRE(new_list.PopFront() == 4);
        REQUIRE_THROWS_AS(new_list.PopFront(), std::runtime_error);
    }
}

int main() {
	
    return Catch::Session().run();
}