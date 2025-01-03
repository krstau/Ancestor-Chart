#include "../include/AncestorChart.hpp"

/**
 * AncestorChart constructor.
 * @param rootPerson
 */
AncestorChart::AncestorChart(const Person &rootPerson) : binaryTree_(BinaryTree<Person>(rootPerson)){}

/**
 * Create rootPerson.
 * @return rootPerson.
 */
Person AncestorChart::createRootPerson() {
    Person rootPerson = Person::createPerson();
    return rootPerson;
}

/**
 * Add person to ancestor chart.
 * @param ancestorChart
 */
void AncestorChart::addPerson(AncestorChart &ancestorChart) {
    Node<Person> *node = searchForNode(ancestorChart);
    if (node != nullptr) {
        if (node->hasSpace()) {
            std::cout << "Adding parent to " << node->getData().getFullName() << ": " << std::endl;
            Person person = Person::createPerson();
            ancestorChart.getBinaryTree().insertNode(node, person);
            std::cout << person.getFullName() << " has been added as " << node->getData().getFullName() << "'s parent!" << std::endl;
        }
        else {
            std::cout << node->getData().getFullName() << " already has 2 parents!" << std::endl;
        }
    }
    promptToReturnToMainMenu();
}

/**
 * Print person in ancestor chart.
 * @param ancestorChart
 */
void AncestorChart::printPerson(AncestorChart &ancestorChart) {
    Node<Person> *node = searchForNode(ancestorChart);
    if (node != nullptr) {
        std::cout << "\nDisplaying information for " << node->getData().getFullName() << ":\n" << std::endl;
        std::cout << node->getData();
    }
    promptToReturnToMainMenu();
}

/**
 * Edit person in ancestor chart.
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
 * Delete all persons in ancestor chart.
 * @param ancestorChart
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
 * If a person has ancestors in the ancestor chart,
 * you will get an option to set the person to "unknown",
 * which sets the person to Person default constructor.
 * @param ancestorChart
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
                std::cout << node->getData().getFullName() << " has ancestors in the ancestor chart!" << std::endl;
                std::cout << "Do you want to set " << node->getData().getFullName() << "'s information to unknown? (yes/no)" << std::endl;
                bool answer = yesOrNo();
                if (answer) {
                    std::cout << node->getData().getFullName() << "'s information has been wiped!" << std::endl;
                    Person unknownPerson = Person();
                    node->setData(unknownPerson);
                }
            }
        }
    }
}

/**
 * Prints all persons in the ancestor chart.
 * @param &ancestorChart
 */
void AncestorChart::printAllPersons(AncestorChart &ancestorChart) {
    std::vector<Node<Person> *> persons;
    Node <Person>* selectedNode;
    nodePointerFunction printPersons = [&persons](Node<Person> *node) {
        persons.emplace_back(node);
    };
    ancestorChart.getBinaryTree().traverseDepthFirst(printPersons);
    std::cout << "\n"
              << "List of persons:" << std::endl;
    for (int index = 0; index < persons.size(); ++index) {
        std::cout << "\n"
                  << "[" << index << "]"
                  << " " << persons[index]->getData().getFullName() << std::endl;
    }
    std::cout << "\n"
              << "Please select a person:";
    int choice = inputValidIntBetween(0, persons.size()); // NOLINT(cppcoreguidelines-narrowing-conversions)
    selectedNode = persons[choice];
    std::cout << "\nDisplaying information for " << selectedNode->getData().getFullName() << ":" << std::endl;
    std::cout << selectedNode->getData();
    promptToReturnToMainMenu();
}

/**
 * Gets the binary tree object in the ancestor chart.
 * @return binaryTree_
 */
BinaryTree<Person> AncestorChart::getBinaryTree() const {
    return binaryTree_;
}

/**
  * Displays available search terms for finding a person.
  * Lets the user select a search term and find a person.
  * @param ancestorChart
  * @return persons vector
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
 * Displays the persons and enables user to select correct person.
 * @param ancestorChart.
 * @return person as a node
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
                  << "List of persons meeting search requirements: " << std::endl;
        for (size_t index{}; index < persons.size(); ++index) {
            std::cout << "\n"
                      << "[" << index << "]"
                      << " " << persons[index]->getData().getFullName() << std::endl;
        }
        std::cout << "\n"
                  << "Please select a person: " << std::endl;
        int selectedPerson = inputValidIntBetween(0, persons.size()); // NOLINT(cppcoreguidelines-narrowing-conversions)
        return persons[selectedPerson];
    }
}

/**
 * Searches for parent node of node to be deleted.
 * @param firstName
 * @return persons
 * @return nullptr
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
 * Gets persons with matching firstname.
 * @param firstName of person
 * @return persons vector
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
 * Gets persons with matching lastname.
 * @param lastName of person
 * @return persons vector
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
 * Gets persons with matching full name.
 * @param firstName persons firstname
 * @param lastName persons lastname
 * @return persons vector
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
 * Gets persons with matching gender.
 * @param gender persons gender
 * @return persons as vector
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