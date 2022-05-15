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
    Person rootPerson = AncestorChart::createPerson();
    AncestorChart tree(rootPerson);
}

std::vector<Person> AncestorChart::getPersonsMatchingFirstName(const std::string &firstName) {
    std::vector<Person> persons;
    nodePointerFunction printPersons = [&persons, &firstName](Node<Person> *node) {
        Person person = node->getData();
        if (person.getFirstName() == firstName) {
            persons.emplace_back(person);
        }
    };
    persons_.traverseDepthFirst(printPersons);
    return persons;
}

std::vector<Person> AncestorChart::getPersonsMatchingLastName(const std::string &lastName) {
    std::vector<Person> persons;
    nodePointerFunction printPersons = [&persons, &lastName](Node<Person> *node) {
        Person person = node->getData();
        if (person.getLastName() == lastName) {
            persons.emplace_back(person);
        }
    };
    persons_.traverseDepthFirst(printPersons);
    return persons;
}

std::vector<Person> AncestorChart::getPersonsMatchingFullName(const std::string &fullName) {
    std::vector<Person> persons;
    nodePointerFunction printPersons = [&persons, &fullName](Node<Person> *node) {
        Person person = node->getData();
        if (person.getFullName() == fullName) {
            persons.emplace_back(person);
        }
    };
    persons_.traverseDepthFirst(printPersons);
    return persons;
}

std::vector<Person> AncestorChart::getPersonsMatchingGender(const Person::Gender &Gender) {
    std::vector<Person> persons;
    nodePointerFunction printPersons = [&persons, &Gender](Node<Person> *node) {
        Person person = node->getData();
        if (person.getGender() == Gender) {
            persons.emplace_back(person);
        }
    };
    persons_.traverseDepthFirst(printPersons);
    return persons;
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

void AncestorChart::printPersonsWithFirstName(const std::string &firstName) {
    nodePointerFunction printPersons = [&firstName](Node<Person> *node) {
        Person person = node->getData();
        if (person.getFirstName() == firstName) {
            std::cout << person.getFullName() << '\n';
        }
    };
    persons_.traverseDepthFirst(printPersons);
}

void AncestorChart::printPersonsWithLastName(const std::string &lastName) {
    nodePointerFunction printPersons = [&lastName](Node<Person> *node) {
        Person person = node->getData();
        if (person.getLastName() == lastName) {
            std::cout << person.getLastName() << '\n';
        }
    };
    persons_.traverseDepthFirst(printPersons);
}

void AncestorChart::printPersonsWithFullName(const std::string &fullName) {
    nodePointerFunction printPersons = [&fullName](Node<Person> *node) {
        Person person = node->getData();
        if (person.getFullName() == fullName) {
            std::cout << person.getFullName() << '\n';
        }
    };
    persons_.traverseDepthFirst(printPersons);
}

void AncestorChart::printPersonsWithGender(const Person::Gender &gender) {
    nodePointerFunction printPersons = [&gender](Node<Person> *node) {
        Person person = node->getData();
        if (person.getGender() == gender) {
            std::cout << person.getGender() << '\n';
        }
    };
    persons_.traverseDepthFirst(printPersons);
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