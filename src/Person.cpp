#include "../include/Person.hpp"

/**
 * Person default constructor.
 */
Person::Person() {
    firstName_ = "Unknown";
    lastName_ = "Unknown";
    dateOfBirth_ = Date();
    dateOfDeath_ = Date();
    gender_ = unknownGender;
    state_ = unknownState;
}

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

/**
 * Prints all available information for a person
 * using overloading.
 * @param &person.
 * @return os.
 */
std::ostream &operator<<(std::ostream &os, const Person &person) {
    os << "Firstname: " << person.getFirstName() << '\n'
       << "Lastname: " << person.getLastName() << '\n'
       << "Gender: " << Person::genderValueToString(person.getGender()) << '\n';
    os << "Date of birth: " << person.getDateOfBirth() << '\n';
    if (person.getState() == Person::deceased) {
        os << "Date of death: " << person.getDateOfDeath() << '\n';
    }
    return os;
}

/**
 * Prompts the user for entering state.
 * @return state as enum.
 */
Person::State Person::inputState() {
    std::string state;
    std::cout << "Enter state (alive/deceased/unknown):";
    while (true) {
        std::cin >> state;
        state = capitalizeString(state);
        if (state == "Alive") {
            return Person::State::alive;
        }
        if (state == "Deceased") {
            return Person::State::deceased;
        }
        if (state == "Unknown") {
            return Person::State::unknownState;
        } else {
            std::cout << std::endl << "Error: please enter a valid state (alive/deceased/unknown):" << std::endl;
        }
    }
}

/**
 * Prompts the user for entering gender.
 * @return gender as enum.
 */
Person::Gender Person::inputGender() {
    std::string gender;
    std::cout << "Enter gender (male/female/unknown):";
    while (true) {
        std::cin >> gender;
        gender = capitalizeString(gender);
        if (gender == "Male") {
            return Person::Gender::male;
        }
        if (gender == "Female") {
            return Person::Gender::female;
        }
        if (gender == "Unknown") {
            return Person::Gender::unknownGender;
        } else {
            std::cout << std::endl << "Error: please enter a valid gender (male/female/unknown):" << std::endl;
        }
    }
}

/**
 * Converts a gender enum to a string.
 * @param gender.
 * @return the gender in string format.
 */
std::string Person::genderValueToString(Person::Gender gender) {
    switch (gender) {
        case Person::male: {
            return "Male";
        }
        case Person::female: {
            return "Female";
        }
        default: {
            return "Unknown";
        }
    }
}

/**
 * Creates a person.
 * @return Person created.
 */
Person Person::createPerson() {
    std::string firstName, lastName;
    Date dateOfDeath;
    Date dateOfBirth;
    Person::State state;
    Person::Gender gender;
    bool validDate = false;
    std::cout << "Enter firstname:";
    std::cin >> firstName;
    firstName = capitalizeString(firstName);
    std::cout << "Enter lastname:";
    std::cin >> lastName;
    lastName = capitalizeString(lastName);
    std::cout << "Enter date of birth (DD/MM/YYYY):";
    Date::inputDate(dateOfBirth);
    state = inputState();
    if (state == State::deceased) {
        while (!validDate) {
            std::cout << "Enter date of death (DD/MM/YYYY):";
            Date::inputDate(dateOfDeath);
            if (Date::compareDates(dateOfBirth, dateOfDeath)) {
                state = Person::deceased;
                validDate = true;
            }
            else {
                std::cout << std::endl << "Date of death cannot be before date of birth!" << std::endl;
            }
        }
    }
    gender = inputGender();
    return {firstName, lastName, dateOfBirth, dateOfDeath, gender, state};
}