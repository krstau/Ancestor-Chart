#define CONFIG_CATCH_MAIN
#include "catch.hpp"
#include "../include/Date.hpp"


TEST_CASE( "Date can be set", "[Date]" ){

    Date date = Date();
    date.setDate(1, 1, 1970);
    std::string dateOutput = NULL;

    SECTION( "date can be changed" ) {
        date.setDate(24, 12, 2000);
        int dayOutput = date.getDay();
        int monthOutput = date.getMonth();
        int yearOutput = date.getYear();

        REQUIRE(dayOutput == 24);
        REQUIRE(monthOutput == 12);
        REQUIRE(yearOutput == 2000);
    }
    SECTION( "invalid date will be detected") {
        REQUIRE(!Date::isValidDate(35, 1, 1970));
        REQUIRE(!Date::isValidDate(1, 15, 1970));
        REQUIRE(!Date::isValidDate(1, 1, 300000));
        REQUIRE(!Date::isValidDate(0, 1, 1970));
        REQUIRE(!Date::isValidDate(1, 0, 1970));
        REQUIRE(!Date::isValidDate(1, 1, 0));
        REQUIRE(!Date::isValidDate(-1, 1, 1970));
        REQUIRE(!Date::isValidDate(1, -1, 1970));
        REQUIRE(!Date::isValidDate(1, 1, -1));
        REQUIRE(!Date::isValidDate(30, 2, 1970));
        REQUIRE(!Date::isValidDate(29, 2, 1970));
        REQUIRE(Date::isValidDate(29, 2, 1972));
        REQUIRE(Date::isValidDate(1, 1, 1970));
    }
}