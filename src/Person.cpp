#include "../include/Person.hpp"
#include <utility>

/**
 * Person constructor.
 * @param firstName Firstname of person.
 * @param lastName Lastname of person.
 * @param dateOfBirth Date of birth of person.
 * @param dateOfDeath Date of death of person.
 * @param gender Gender of person.
 * @param state State of person.
 */
Person::Person(std::string firstName, std::string lastName, Date dateOfBirth, Date dateOfDeath, Gender gender, State state)
    : firstName_(std::move(firstName)), lastName_(std::move(lastName)), dateOfBirth_(dateOfBirth), dateOfDeath_(dateOfDeath), gender_(gender), state_(state) {
}

/**
 * Gets firstname of Person object.
 * @return firstname of person.
 */
std::string Person::getFirstName() const {
    return firstName_;
}

/**
 * Gets firstname of Person object.
 * @return lastname of person.
 */
std::string Person::getLastName() const {
    return lastName_;
}

/**
 * Gets full name of Person object.
 * @return full name.
 */
std::string Person::getFullName() const {
    return firstName_ + " " + lastName_;
}

/**
 * Gets date of birth of Person object.
 * @return date of birth.
 */
Date Person::getDateOfBirth() const {
    return dateOfBirth_;
}

/**
 * Gets date of death of Person object.
 * @return date of death.
 */
Date Person::getDateOfDeath() const {
    return dateOfDeath_;
}

/**
 * Gets gender of Person object.
 * @return gender.
 */
Person::Gender Person::getGender() const {
    return gender_;
}

/**
 * Gets state of Person object.
 * @return state.
 */
Person::State Person::getState() const {
    return state_;
}
