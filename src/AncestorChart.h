#ifndef ANCESTOR_CHART_ANCESTORCHART_H
#define ANCESTOR_CHART_ANCESTORCHART_H
#include "BinaryTree.h"
#include "Person.h"
#include <algorithm>
#include <string>

/**
 * Ancestor chart class.
 */
class AncestorChart {
public:
    explicit AncestorChart(const Person &rootPerson) : persons_(BinaryTree<Person>(rootPerson)){};
    static void createRootPerson();
    static Person createPerson();
    static void printPerson();
    void printPersons();
    void printPersonsWithName(const std::string &name);
    std::vector<Person> getPersonsMatchingName(const std::string &name);


    //TODO: Move these functions to menu-class.
    static std::string genderValueToString(Person::Gender);
    //

    static Person::Gender inputGender();


private:
    typedef std::function<void(Node<Person> *)> nodePointerFunction;
    BinaryTree<Person> persons_;
};

#endif//ANCESTOR_CHART_ANCESTORCHART_H
