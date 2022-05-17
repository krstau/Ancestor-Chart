#define CONFIG_CATCH_MAIN
#include "../external/Catch2/catch.hpp"
#include "../include/Date.hpp"


TEST_CASE( "Date can be set", "[Date]" ){

    Date date = Date();
    date.setDate(1, 1, 1970);
    std::string dateOutput = NULL;

    SECTION( "date can be changed to a valid date" ) {
        date.setDate(24, 12, 2000);
        dateOutput = date.getDate();

        REQUIRE(dateOutput == "24/12/2000");
    }
    SECTION( "invalid date will be detected") {
        REQUIRE(!checkIfDateIsValid(35, 1, 1970));
        REQUIRE(!checkIfDateIsValid(1, 15, 1970));
        REQUIRE(!checkIfDateIsValid(1, 1, 300000));
        REQUIRE(!checkIfDateIsValid(0, 1, 1970));
        REQUIRE(!checkIfDateIsValid(1, 0, 1970));
        REQUIRE(!checkIfDateIsValid(1, 1, 0));
        REQUIRE(!checkIfDateIsValid(30, 2, 1970));
        REQUIRE(!checkIfDateIsValid(29, 2, 1970));
        REQUIRE(checkIfDateIsValid(29, 2, 1972));
        REQUIRE(checkIfDateIsValid(1, 1, 1970));
    }
}