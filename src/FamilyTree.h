#ifndef ANCESTOR_CHART_FAMILYTREE_H
#define ANCESTOR_CHART_FAMILYTREE_H
#include "BinaryTree.h"
#include "Menu.h"
#include "Person.h"
#include <algorithm>
#include <string>

class FamilyTree {
public:
    explicit FamilyTree(const Person &owner) : persons_(BinaryTree<Person>(owner)){};
    Person createPerson();
    void printPerson();
    void printPersons();
    void printPersonsWithName(const std::string &name);
    std::vector<Person> getPersonsMatchingName(const std::string &name);


    //TODO: Move these functions to menu-class.
    bool yesOrNo();
    std::string capitalizeString(std::string);
    static std::string genderValueToString(Gender);
    void printPersonInfo(const Person &person);
    //

    Gender inputGender();


private:
    typedef std::function<void(Node<Person> *)> nodePointerFunction;
    BinaryTree<Person> persons_;
};

std::vector<Person> FamilyTree::getPersonsMatchingName(const std::string &name) {
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

void FamilyTree::printPersonsWithName(const std::string &name) {
    nodePointerFunction printPersons = [&name](Node<Person> *node) {
        Person person = node->getData();
        if (person.getFirstName() == name) {
            std::cout << person.getFullName() << '\n';
        }
    };
    persons_.traverseDepthFirst(printPersons);
}

void FamilyTree::printPersons() {
    nodePointerFunction printPersons = [](Node<Person> *node) {
        Person person = node->getData();
        std::cout << person.getFullName() << '\n';
    };
    persons_.traverseDepthFirst(printPersons);
}

//TODO: Use ostream-operator overloading instead, see markaren github (linkedlist.hpp, search for ostream)
void FamilyTree::printPersonInfo(const Person &person) {// Function to print information about a person
    std::cout << "Showing information for: " << '\n';
    std::cout << "Firstname: " << person.getFirstName() << '\n';
    std::cout << "Lastname: " << person.getLastName() << '\n';
    std::cout << "Date of birth: " << person.getDateOfBirth() << '\n';
    if (!person.getStatus()) {
        std::cout << "Date of death: " << person.getDateOfDeath() << '\n';
    }
    std::string gender = genderValueToString(person.getGender());
    std::cout << "Gender: " << capitalizeString(gender) << '\n'
              << '\n';
}

void FamilyTree::printPerson() {// Function to print a person by first and last name
    std::string firstName, lastName;
    std::cout << "Enter the firstname of the person that you want to display: ";
    std::cin >> firstName;
    firstName = capitalizeString(firstName);
    std::cout << "Enter the lastname of the person that you want to display: ";
    std::cin >> lastName;
    lastName = capitalizeString(lastName);
}

//TODO: ask user who this person is the parent of
//with lambda function; find all people matching description and return in a vector
//from the returned vector, ask the user which is the correct person
//ask the user; is the person the mother or the father of the correct person
//if father, add or edit leftNode, if mother add or edit rightNode
Person FamilyTree::createPerson() {
    std::string firstName, lastName, dateOfBirth, dateOfDeath;
    State state = unknownState;
    Gender gender = unknownGender;
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
        state = deceased;
    }
    gender = inputGender();
    return {firstName, lastName, dateOfBirth, dateOfDeath, gender, state};
}

Gender FamilyTree::inputGender() {
    std::string gender;
    std::cout << "Enter gender (male/female): ";
    while (true) {
        std::cin >> gender;
        gender = capitalizeString(gender);
        if (gender == "Male") {
            return Gender::male;
        }
        if (gender == "Female") {
            return Gender::female;
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
std::string FamilyTree::genderValueToString(Gender gender) {
    switch (gender) {
        case male: {
            return "male";
        }
        case female: {
            return "female";
        }
        default: {
            return "unknown";
        }
    }
}



#endif//ANCESTOR_CHART_FAMILYTREE_H
