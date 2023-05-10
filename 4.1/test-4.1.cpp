#include <iostream>
#include "list_class.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

List list;

TEST_CASE("Test List Empty method", "[List Empty]") {
    INFO("Testing if the new List is empty");
    SECTION("List test section") {
        CHECK(list.Empty() == true);
    }
}

TEST_CASE("Test List Size method", "[List Size]") {
    list.PushBack(1);
    list.PushBack(3);
    list.PushBack(5);
    INFO("Testing the List Size method");
    SECTION("List test section") {
        CHECK(list.Size() == 3);
    }
}

TEST_CASE("Test List Clear method", "[List Clear]") {
    list.Clear();
    INFO("Testing the List Clear method");
    SECTION("List test section") {
        CHECK(list.Size() == 0);
    }
}

int main() {

    return Catch::Session().run();
}