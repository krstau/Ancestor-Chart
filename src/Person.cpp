#include "../include/Person.hpp"
#include <utility>

// Multi-parameter constructor
Person::Person(std::string firstName, std::string lastName, Date dateOfBirth, Date dateOfDeath, Gender gender, State state)
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

Date Person::getDateOfBirth() const {
    return dateOfBirth_;
}

Date Person::getDateOfDeath() const {
    return dateOfDeath_;
}

Person::Gender Person::getGender() const {
    return gender_;
}

Person::State Person::getState() const {
    return state_;
}