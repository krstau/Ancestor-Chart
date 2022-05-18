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

/**
     * Prompts the user for entering gender for either male or female.
    *
    * @param none.
    * @return none.
    */
Person::Gender Person::inputGender() {
    std::string gender;
    std::cout << "Enter gender (male/female):" << std::endl;
    while (true) {
        std::cin >> gender;
        gender = capitalizeString(gender);
        if (gender == "Male") {
            return Person::Gender::male;
        }
        if (gender == "Female") {
            return Person::Gender::female;
        } else {
            std::cout << std::endl << "Error: please enter a valid gender (male/female):" << std::endl;
        }
    }
}

/**
    * Converts a gender enum to a string.
    *
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

//TODO: ask user who this person is the parent of
//with lambda function; find all people matching description and return in a vector
//from the returned vector, ask the user which is the correct person
//ask the user; is the person the mother or the father of the correct person
//if father, add or edit leftNode, if mother add or edit rightNode
Person Person::createPerson() {
    std::string firstName, lastName;
    Date dateOfDeath;
    Date dateOfBirth;
    Person::State state = Person::alive;
    Person::Gender gender;
    std::cout << "Enter firstname:" << std::endl;
    std::cin >> firstName;
    firstName = capitalizeString(firstName);
    std::cout << "Enter lastname:" << std::endl;
    std::cin >> lastName;
    lastName = capitalizeString(lastName);
    std::cout << "Enter date of birth (DD/MM/YYYY):" << std::endl;
    Date::enterDate(dateOfBirth);
    std::cout << "Is the person deceased (Yes/No)?" << std::endl;
    bool answer = yesOrNo();
    if (answer) {// TODO: Check if date of year isn't less than year of birth
        std::cout << "Enter date of death (DD/MM/YYYY):" << std::endl;
        Date::enterDate(dateOfDeath);
        state = Person::deceased;
    }
    gender = inputGender();
    return {firstName, lastName, dateOfBirth, dateOfDeath, gender, state};
}

/**
    * Prints all available information for a person.
    *
    * @param &person.
    * @return os.
    */
std::ostream &operator<<(std::ostream &os, const Person &person) {
    os << "Firstname: " << person.getFirstName() << '\n'
       << "Lastname: " << person.getLastName() << '\n'
       << "Gender: " << Person::genderValueToString(person.getGender()) << '\n'
       << "Date of birth: " << person.getDateOfBirth().getDate() << '\n';
    if (person.getState() == Person::deceased) {
        os << "Date of death: " << person.getDateOfDeath().getDate() << '\n';
    }
    return os;
}