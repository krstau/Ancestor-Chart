#include "../external/Catch2/catch.hpp"
#include "../include/Person.hpp"
#include "../src/Person.cpp"


TEST_CASE("Person functionality", "[Person]"){
    Person testPerson = Person();

    SECTION("Defualt constructor and getters"){
        REQUIRE(testPerson.getFirstName() == "Unknown");
        REQUIRE(testPerson.getLastName() == "Unknown");
        REQUIRE(testPerson.getFullName() == "Unknown Unknown");
        REQUIRE(testPerson.getDateOfBirth().getDay() == 1);
        REQUIRE(testPerson.getDateOfBirth().getMonth() == 1);
        REQUIRE(testPerson.getDateOfBirth().getYear() == 1970);
        REQUIRE(testPerson.getDateOfDeath().getDay() == 1);
        REQUIRE(testPerson.getDateOfDeath().getMonth() == 1);
        REQUIRE(testPerson.getDateOfDeath().getYear() == 1970);
        REQUIRE(testPerson.getGender() == Person::unknownGender);
        REQUIRE(testPerson.getState() == Person::unknownState);
    }
    SECTION("Constructor with arguments"){

        std::string firstName = "Ivar";
        std::string lastName = "Aasen";
        Date dateOfBirth = Date();
        Date dateOfDeath = Date();
        dateOfBirth.setDate(05, 8, 1813);
        dateOfDeath.setDate(23, 9, 1896);
        Person::Gender gender = Person::male;
        Person::State state = Person::deceased;

        testPerson = Person(firstName, lastName, dateOfBirth, dateOfDeath,  gender, state);

        REQUIRE(testPerson.getDateOfBirth().getDay() == 5);
        REQUIRE(testPerson.getDateOfBirth().getMonth() == 8);
        REQUIRE(testPerson.getDateOfBirth().getYear() == 1813);
        REQUIRE(testPerson.getDateOfDeath().getDay() == 23);
        REQUIRE(testPerson.getDateOfDeath().getMonth() == 9);
        REQUIRE(testPerson.getDateOfDeath().getYear() == 1896);
        REQUIRE(testPerson.getGender() == Person::male);
        REQUIRE(testPerson.getState() == Person::deceased);
    }
}