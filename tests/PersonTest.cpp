#include "../external/Catch2/catch.hpp"
#include "../include/Person.hpp"
#include "../src/Person.cpp"

TEST_CASE("Edit info in person", "[Person]"){
    std::string firstName = "Ivar";
    std::string lastName = "Aasen";
    std::string dateOfBirth = "05/08/1813";
    std::string dateOfDeath = "23/09/1896";
    Gender gender = male;
    State state = deceased;






            Person Person(firstName, lastName, dateOfBirth, dateOfDeath, gender, );


}
