#include "src/AncestorChart.h"
#include "src/Menu.h"
#include <iostream>

//TODO: ask user who this person is the parent of
//with lambda function; find all people matching description and return in a vector
//from the returned vector, ask the user which is the correct person
//ask the user; is the person the mother or the father of the correct person
//if father, add or edit leftNode, if mother add or edit rightNode
Person AncestorChart::createPerson() {
    std::string firstName, lastName, dateOfBirth, dateOfDeath;
    Person::State state = Person::unknownState;
    Person::Gender gender = Person::unknownGender;
    std::cout << "Enter firstname:";
    std::cin >> firstName;
    std::cout << "Enter lastname:";
    std::cin >> lastName;
    std::cout << "Enter date of birth (DD/MM/YYYY):";
    std::cin >> dateOfBirth;
    std::cout << "Is the person deceased (Yes/No)?";
    bool answer = Menu::yesOrNo();
    if (answer) {
        std::cout << "Enter date of death (DD/MM/YYYY):";
        std::cin >> dateOfDeath;
        state = Person::deceased;
    }
    gender = inputGender();
    return {firstName, lastName, dateOfBirth, dateOfDeath, gender, state};
}

void AncestorChart::createRootPerson(){
    std::cout << "Please create a root person for the ancestor chart: \n";
    Person rootPerson = AncestorChart::createPerson();
    AncestorChart tree(rootPerson);
}


std::vector<Person> AncestorChart::getPersonsMatchingName(const std::string &name) {
    std::vector<Person> persons;
    nodePointerFunction printPersons = [&persons, &name](Node<Person> *node) {
        Person person = node->getData();
        if (person.getFirstName() == name) {
            persons.emplace_back(person);
        }
    };
    persons_.traverseDepthFirst(printPersons);
    return persons;
}

void AncestorChart::printPersonsWithName(const std::string &name) {
    nodePointerFunction printPersons = [&name](Node<Person> *node) {
        Person person = node->getData();
        if (person.getFirstName() == name) {
            std::cout << person.getFullName() << '\n';
        }
    };
    persons_.traverseDepthFirst(printPersons);
}

void AncestorChart::printPersons() {
    nodePointerFunction printPersons = [](Node<Person> *node) {
        Person person = node->getData();
        std::cout << person.getFullName() << '\n';
    };
    persons_.traverseDepthFirst(printPersons);
}

void AncestorChart::printPerson() {// Function to print a person by first and last name
    std::string firstName, lastName;
    std::cout << "Enter the firstname of the person that you want to display: ";
    std::cin >> firstName;
    firstName = Menu::capitalizeString(firstName);
    std::cout << "Enter the lastname of the person that you want to display: ";
    std::cin >> lastName;
    lastName = Menu::capitalizeString(lastName);
}

Person::Gender AncestorChart::inputGender() {
    std::string gender;
    std::cout << "Enter gender (male/female): ";
    while (true) {
        std::cin >> gender;
        gender = Menu::capitalizeString(gender);
        if (gender == "Male") {
            return Person::Gender::male;
        }
        if (gender == "Female") {
            return Person::Gender::female;
        } else {
            std::cout << "\nError: please enter a valid gender (male/female):";
        }
    }
}

/**
 * Converts a gender enum to a string.
 *
 * @param gender the enum representing the gender.
 * @return the gender in string format.
 */
std::string AncestorChart::genderValueToString(Person::Gender gender) {
    switch (gender) {
        case Person::male: {
            return "male";
        }
        case Person::female: {
            return "female";
        }
        default: {
            return "unknown";
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Person &person) {
    os << "Firstname: " << person.getFirstName() << '\n'
       << "Lastname: " << person.getLastName() << '\n'
       << "Gender: " << person.getGender() << '\n'
       << "State: " << person.getState() << '\n'
       << "Date of birth: " << person.getDateOfBirth() << '\n'
       << "Date of death: " << person.getDateOfDeath() << '\n';
    return os;
}