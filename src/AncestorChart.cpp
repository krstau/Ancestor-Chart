#include "../include/AncestorChart.hpp"

/**
 * AncestorChart constructor.
 */
AncestorChart::AncestorChart(const Person &rootPerson) : binaryTree_(BinaryTree<Person>(rootPerson)){}

/**
 * Create new ancestor chart.
 * @return ancestorChart.
 */
Person AncestorChart::createRootPerson() {
    Person rootPerson = Person::createPerson();
    return rootPerson;
}

/**
 * Add person to ancestor chart.
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
 * Print person in ancestor chart.
 */
void AncestorChart::printPerson(AncestorChart &ancestorChart) {
    Node<Person> *node = searchForNode(ancestorChart);
    if (node != nullptr) {
        std::cout << "\nDisplaying information for " << node->getData().getFullName() << ":" << std::endl;
        std::cout << node->getData();
    }
}

/**
 * Edit person in ancestor chart.
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
 * Delete all persons in ancestor chart.
 */
void AncestorChart::deleteAllPersons(AncestorChart &ancestorChart) {
    nodePointerFunction printPersons = [](Node<Person> *node) {
        Person person = node->getData();
        std::cout << person.getFullName() << std::endl;
    };
    ancestorChart.getBinaryTree().traverseDepthFirst(printPersons);
    promptToReturnToMainMenu();
}

/**
 * Deletes a person in ancestor chart.
 */
void AncestorChart::deletePerson(AncestorChart &ancestorChart) {
    Node<Person> *node = searchForNode(ancestorChart);
    if (node != nullptr) {
        std::cout << "Are you sure you want to delete " << node->getData().getFullName() << "? (yes/no)" << std::endl;
        bool confirmation = yesOrNo();
        if (confirmation) {
            if (node->isLeaf()) {
                Node<Person> *parentNode = searchForParent(ancestorChart, node);
                if (parentNode != nullptr) {
                    if (parentNode->getLeftPtr() == node) {
                        delete node;
                        parentNode->setLeftPtr(nullptr);
                    }
                    else {
                        delete node;
                        parentNode->setRightPtr(nullptr);
                    }
                }
            }
            else {
                std::cout << node->getData().getFullName() << " has ancestors in the Graph!" << std::endl;
                std::cout << "Do you want to set " << node->getData().getFullName() << "'s information to unknown?" << std::endl;
                bool answer = yesOrNo();
                if (answer) {
                    std::cout << node->getData().getFullName() << " has been wiped!" << std::endl;
                    Person unknownPerson = Person();
                    node->setData(unknownPerson);
                }
            }
        }
    }
}

/**
 * Prints all persons in the ancestor chart.
 * @param &ancestorChart.
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
 * Gets the binary tree object in the ancestor chart.
 * @param binaryTree_.
 */
BinaryTree<Person> AncestorChart::getBinaryTree() const {
    return binaryTree_;
}

/**
  * Displays available search terms for finding a person.
  * Lets the user select a search term and find a person.
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
            std::cout << "Please enter a number between 0 and 4:\n";
            break;
    }
    return persons;
}

/**
 * Function to search for persons by traits.
 * Displays the persons and enabled user to select correct person.
 * @param &ancestorChart.
 * @return persons.
 */
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
                  << "Please select a person: " << std::endl;
        int selectedPerson = inputValidIntBetween(0, persons.size());
        return persons[selectedPerson];
    }
}

/**
 *
 * @param firstName
 * @return
 */
Node<Person> * AncestorChart::searchForParent(AncestorChart &ancestorChart, Node<Person> * &nodeToBeDeleted) {
    std::vector<Node<Person> *> persons;
    nodePointerFunction compareNodes = [&persons, &nodeToBeDeleted](Node<Person> *node) {
        Person person = node->getData();
        if (node->getLeftPtr() == nodeToBeDeleted || node->getRightPtr() == nodeToBeDeleted ) {
            persons.emplace_back(node);
        }
    };
    ancestorChart.getBinaryTree().traverseDepthFirst(compareNodes);

    if (persons.size() == 1) {
        return persons[0];
    }
    else {
        std::cout << "You cannot delete the root person!";
        return nullptr;
    }
}


/**
 *
 * @param firstName
 * @return
 */
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

/**
 *
 * @param firstName
 * @return
 */
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

/**
 *
 * @param firstName
 * @return
 */
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

/**
 *
 * @param firstName
 * @return
 */
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