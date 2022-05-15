#include "src/Person.h"
#include "src/FamilyTree.h"
#include "src/Menu.h"
#include <iostream>

int main() {
    Menu::display();
    Person rootPerson = FamilyTree::createPerson();
    FamilyTree tree(rootPerson);
    // tree.printPersons();
    std::cout << '\n';
    tree.printPersonsWithName("Ole");
    return 0;
}

// TODO: Doxygen!