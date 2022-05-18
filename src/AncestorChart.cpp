#include "../include/AncestorChart.hpp"
#include <iostream>

void addPerson() {
    std::cout << "Please enter the name of the child of the person you want to add: \n";


    // Person person = AncestorChart::createPerson();
    // ancestorChart_.insertLeft(node, person);
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

std::vector<Person> AncestorChart::getPersonsMatchingFullName(const std::string &firstName, const std::string &lastName) {
    std::vector<Person> persons;
    nodePointerFunction printPersons = [&persons, &firstName, &lastName](Node<Person> *node) {
        Person person = node->getData();
        if ((person.getFirstName() == firstName) && (person.getLastName() == lastName)) {
            persons.emplace_back(person);
        }
    };
    persons_.traverseDepthFirst(printPersons);
    return persons;
}

std::vector<Person> AncestorChart::getPersonsMatchingGender(const Person::Gender &gender) {
    std::vector<Person> persons;
    nodePointerFunction printPersons = [&persons, &gender](Node<Person> *node) {
        Person person = node->getData();
        if (person.getGender() == gender) {
            persons.emplace_back(person);
        }
    };
    persons_.traverseDepthFirst(printPersons);
    return persons;
}

/**
 * Prints all persons.
 *
 * @param none.
 * @return none.
 */
void AncestorChart::printPersons() {
    nodePointerFunction printPersons = [](Node<Person> *node) {
        Person person = node->getData();
        std::cout << person.getFullName() << '\n';
    };
    persons_.traverseDepthFirst(printPersons);
}

/**
 * Prints all persons with corresponding firstname.
 *
 * @param firstname.
 * @return none.
 */
void AncestorChart::printPersonsWithFirstName(const std::string &firstName) {
    nodePointerFunction printPersons = [&firstName](Node<Person> *node) {
        Person person = node->getData();
        if (person.getFirstName() == firstName) {
            std::cout << person.getFullName() << '\n';
        }
    };
    persons_.traverseDepthFirst(printPersons);
}

/**
 * Prints all persons with corresponding lastname.
 *
 * @param lastname.
 * @return none.
 */
void AncestorChart::printPersonsWithLastName(const std::string &lastName) {
    nodePointerFunction printPersons = [&lastName](Node<Person> *node) {
        Person person = node->getData();
        if (person.getLastName() == lastName) {
            std::cout << person.getLastName() << '\n';
        }
    };
    persons_.traverseDepthFirst(printPersons);
}

/**
 * Prints all persons with corresponding full name.
 *
 * @param full name.
 * @return none.
 */
void AncestorChart::printPersonsWithFullName(const std::string &fullName) {
    nodePointerFunction printPersons = [&fullName](Node<Person> *node) {
        Person person = node->getData();
        if (person.getFullName() == fullName) {
            std::cout << person.getFullName() << '\n';
        }
    };
    persons_.traverseDepthFirst(printPersons);
}

/**
 * Prints all persons with corresponding gender.
 *
 * @param gender.
 * @return none.
 */
void AncestorChart::printPersonsWithGender(const Person::Gender &gender) {
    nodePointerFunction printPersons = [&gender](Node<Person> *node) {
        Person person = node->getData();
        if (person.getGender() == gender) {
            std::cout << person.getGender() << '\n';
        }
    };
    persons_.traverseDepthFirst(printPersons);
}