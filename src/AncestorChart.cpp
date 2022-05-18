#include "../include/AncestorChart.hpp"
#include <iostream>

/*
void AncestorChart::addPerson() {
    std::cout << "Who's parent do you want to add?" << "\n";
    Node<Person> *node = searchforNode(ancestorChart);
    if (node != nullptr){
        Person person = AncestorChart::createPerson();
        persons_.insertNode(node, person);
    }
}
*/

void AncestorChart::searchForPerson() {
    Node<Person> *node = searchforNode(ancestorChart);
    if (node != nullptr) {
        std::cout << node->getData();
    }
}

void AncestorChart::editPerson(){

}

void AncestorChart::deletePerson(){

}

/**
    * Displays available search terms for finding a person.
    * Lets the user select a search term and find a person.
    *
    * @param none.
    * @return person.
    */
std::vector<Node<Person>*> selectSearchTerm(AncestorChart ancestorChart) {
    std::vector<Node<Person>*> persons;
    int searchTerm = getValidIntBetween(0, 4);
    switch (searchTerm) {
        case 1: {
            std::string firstName;
            std::cout << "Please enter firstname:";
            std::cin >> firstName;
            firstName = capitalizeString(firstName);
            persons = ancestorChart.getPersonsMatchingFirstName(firstName);
            return persons;
        }
        case 2: {
            std::string lastName;
            std::cout << "Please enter lastname:";
            std::cin >> lastName;
            lastName = capitalizeString(lastName);
            persons = ancestorChart.getPersonsMatchingLastName(lastName);
            return persons;
        }
        case 3: {
            std::string firstName, lastName;
            std::cout << "Please enter firstname:";
            std::cin >> firstName;
            firstName = capitalizeString(firstName);
            std::cout << "Please enter lastname:";
            std::cin >> lastName;
            lastName = capitalizeString(lastName);
            persons = ancestorChart.getPersonsMatchingFullName(firstName, lastName);
            return persons;
        }
        case 4: {
            Person::Gender gender;
            std::cout << "Please enter gender:";
            gender = Person::inputGender();
            persons = ancestorChart.getPersonsMatchingGender(gender);
            return persons;
        }
        case 0: {
            break;
        }
        default:
            std::cout << "Please enter a number between 0 and 4:\n";
            break;
    }
    return persons;
}

Node<Person>* AncestorChart::searchforNode(AncestorChart &ancestorChart) {
    std::vector<Node<Person>*> persons = selectSearchTerm(ancestorChart);

    if (persons.empty()){
        std::cout << "No person matching search could be found";
        return nullptr;
    }

    if (persons.size() == 1){
        return persons[0];
    }
    else {
        std::cout << "\n" << "List of persons: " << std::endl;
        for (size_t index{}; index < persons.size(); ++index) {
            std::cout << "\n"
                      << "[" << index << "]"
                      << " " << persons[index]->getData().getFullName() << std::endl;
        }
        std::cout << "\n"
                  << "Please select a person: " << std::endl;
        int selectedPerson = getValidIntBetween(0, persons.size());
        return persons[selectedPerson];
    }
}

std::vector<Node<Person>*> AncestorChart::getPersonsMatchingFirstName(const std::string &firstName) {
    std::vector<Node<Person>*> persons;
    nodePointerFunction printPersons = [&persons, &firstName](Node<Person> *node) {
        Person person = node->getData();
        if (person.getFirstName() == firstName) {
            persons.emplace_back(node);
        }
    };
    persons_.traverseDepthFirst(printPersons);
    return persons;
}

std::vector<Node<Person>*> AncestorChart::getPersonsMatchingLastName(const std::string &lastName) {
    std::vector<Node<Person>*> persons;
    nodePointerFunction printPersons = [&persons, &lastName](Node<Person> *node) {
        Person person = node->getData();
        if (person.getFirstName() == lastName) {
            persons.emplace_back(node);
        }
    };
    persons_.traverseDepthFirst(printPersons);
    return persons;
}

std::vector<Node<Person>*> AncestorChart::getPersonsMatchingFullName(const std::string &firstName, const std::string &lastName) {
    std::vector<Node<Person>*> persons;
    nodePointerFunction printPersons = [&persons, &firstName, &lastName](Node<Person> *node) {
        Person person = node->getData();
        if ((person.getFirstName() == firstName) && (person.getLastName() == lastName)) {
            persons.emplace_back(node);
        }
    };
    persons_.traverseDepthFirst(printPersons);
    return persons;
}

std::vector<Node<Person>*> AncestorChart::getPersonsMatchingGender(const Person::Gender &gender) {
    std::vector<Node<Person>*> persons;
    nodePointerFunction printPersons = [&persons, &gender](Node<Person> *node) {
        Person person = node->getData();
        if (person.getGender() == gender) {
            persons.emplace_back(node);
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