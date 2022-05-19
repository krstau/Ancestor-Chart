#include "../include/AncestorChart.hpp"

/**
 * Function to get binary tree.
 * @return binary tree.
 */
BinaryTree<Person> AncestorChart::getBinaryTree() const {
    return binaryTree_;
}

/**
  * Function to add a person to the ancestor chart.
  * @param ancestorChart
  */
void AncestorChart::addPerson(AncestorChart &ancestorChart) {
    Node<Person> *node = searchForNode(ancestorChart);
    if (node != nullptr) {
        std::cout << "Adding parent to " << node->getData().getFullName() << ": " << std::endl;
        Person person = Person::createPerson();
        ancestorChart.getBinaryTree().insertNode(node, person);
        std::cout << person.getFullName() << " has been added as " << node->getData().getFullName() << "'s parent!" << std::endl;
    }
    promptToReturnToMainMenu();
}

/**
  * Function to print a person in the ancestor chart.
  * @param ancestorChart
  */
void AncestorChart::printPerson(AncestorChart &ancestorChart) {
    Node<Person> *node = searchForNode(ancestorChart);
    if (node != nullptr) {
        std::cout << "\nDisplaying information for " << node->getData().getFullName() << ":" << std::endl;
        std::cout << node->getData();
    }
}

/**
  * Function to edit a person in the ancestor chart.
  * @param ancestorChart
  */
void AncestorChart::editPerson(AncestorChart &ancestorChart) {
    Node<Person> *node = searchForNode(ancestorChart);
    if (node != nullptr) {
        std::cout << "Editing " << node->getData().getFullName() << "'s information: " << std::endl;
        Person person = Person::createPerson();
        node->setData(person);
    }
}


/**
  * Function to delete a person in the ancestor chart.
  * @param ancestorChart
  */
/*
void AncestorChart::deletePerson(AncestorChart &ancestorChart) {
    Node<Person> *node = searchForNode(ancestorChart);
    if (node != nullptr) {
        if(node->isLeaf()){
            //delete
        }
        else { //TODO: add logic asking user if setting data to unknown instead of deleting is fine
            Person unknownperson = Person();
            node->setData(unknownperson);
        }
    }
}
 */

/**
 * Prints all persons in the ancestor chart.
 * @param &ancestorChart.
 * @return none.
 */
void AncestorChart::printAllPersons(AncestorChart &ancestorChart) {
    nodePointerFunction printPersons = [](Node<Person> *node) {
        Person person = node->getData();
        std::cout << person.getFullName() << std::endl;
    };
    ancestorChart.getBinaryTree().traverseDepthFirst(printPersons);
    promptToReturnToMainMenu();
}

/**
    * Displays available search terms for finding a person.
    * Lets the user select a search term and find a person.
    *
    * @param none.
    * @return person.
    */
std::vector<Node<Person> *> selectSearchTerm(AncestorChart ancestorChart) {
    std::vector<Node<Person> *> persons;
    int searchTerm = inputValidIntBetween(0, 4);
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
            std::cout << std::endl << "Please enter a number between 0 and 4:" << std::endl;
            break;
    }
    return persons;
}

Node<Person> *AncestorChart::searchForNode(AncestorChart &ancestorChart) {
    std::vector<Node<Person> *> persons = selectSearchTerm(ancestorChart);

    if (persons.empty()) {
        std::cout << "No person matching search could be found";
        return nullptr;
    }

    if (persons.size() == 1) {
        return persons[0];
    } else {
        std::cout << "\n"
                  << "List of persons: " << std::endl;
        for (size_t index{}; index < persons.size(); ++index) {
            std::cout << "\n"
                      << "[" << index << "]"
                      << " " << persons[index]->getData().getFullName() << std::endl;
        }
        std::cout << "\n"
                  << "Please select a person: ";
        int selectedPerson = inputValidIntBetween(0, persons.size());
        return persons[selectedPerson];
    }
}

std::vector<Node<Person> *> AncestorChart::getPersonsMatchingFirstName(const std::string &firstName) {
    std::vector<Node<Person> *> persons;
    nodePointerFunction printPersons = [&persons, &firstName](Node<Person> *node) {
        Person person = node->getData();
        if (person.getFirstName() == firstName) {
            persons.emplace_back(node);
        }
    };
    binaryTree_.traverseDepthFirst(printPersons);
    return persons;
}

std::vector<Node<Person> *> AncestorChart::getPersonsMatchingLastName(const std::string &lastName) {
    std::vector<Node<Person> *> persons;
    nodePointerFunction printPersons = [&persons, &lastName](Node<Person> *node) {
        Person person = node->getData();
        if (person.getLastName() == lastName) {
            persons.emplace_back(node);
        }
    };
    binaryTree_.traverseDepthFirst(printPersons);
    return persons;
}

std::vector<Node<Person> *> AncestorChart::getPersonsMatchingFullName(const std::string &firstName, const std::string &lastName) {
    std::vector<Node<Person> *> persons;
    nodePointerFunction printPersons = [&persons, &firstName, &lastName](Node<Person> *node) {
        Person person = node->getData();
        if ((person.getFirstName() == firstName) && (person.getLastName() == lastName)) {
            persons.emplace_back(node);
        }
    };
    binaryTree_.traverseDepthFirst(printPersons);
    return persons;
}

std::vector<Node<Person> *> AncestorChart::getPersonsMatchingGender(const Person::Gender &gender) {
    std::vector<Node<Person> *> persons;
    nodePointerFunction printPersons = [&persons, &gender](Node<Person> *node) {
        Person person = node->getData();
        if (person.getGender() == gender) {
            persons.emplace_back(node);
        }
    };
    binaryTree_.traverseDepthFirst(printPersons);
    return persons;
}
void AncestorChart::deleteAllPersons(AncestorChart &ancestorChart) {

}
