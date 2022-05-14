#include "src/Person.h"
#include <utility>

// Multi-parameter constructor
Person::Person(std::string firstName, std::string lastName, std::string dateOfBirth, std::string dateOfDeath, Gender gender, State state)
    : firstName_(std::move(firstName)), lastName_(std::move(lastName)), dateOfBirth_(std::move(dateOfBirth)), dateOfDeath_(std::move(dateOfDeath)), gender_(gender), state_(state) {
}

std::string Person::getFirstName() const {
    return firstName_;
}

std::string Person::getLastName() const {
    return lastName_;
}

std::string Person::getFullName() const {
    return firstName_ + " " + lastName_;
}

std::string Person::getDateOfBirth() const {
    return dateOfBirth_;
}

std::string Person::getDateOfDeath() const {
    return dateOfDeath_;
}

Gender Person::getGender() const {
    return gender_;
}

State Person::getStatus() const {
    return state_;
}