#include <iostream>
#include "list_class.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

List list;

TEST_CASE("Test List Empty method", "[List Empty Test]") {
    INFO("Testing Empty method");
    SECTION("List test section") {
        CHECK(list.Empty() == true);
    }
}

TEST_CASE("Test List Size method", "[List Size Test]") {
    INFO("Testing Size method");
	list.PushFront(2);
    SECTION("List test section") {
        CHECK(list.Size() == 1);
    }
}

TEST_CASE("Test List Clear method", "[List Clear Test]") {
    list.Clear();
	INFO("Testing Clear method");
    SECTION("List test section") {
        CHECK(list.Size() == 0);
    }
}

int main() {
	
    return Catch::Session().run();
}