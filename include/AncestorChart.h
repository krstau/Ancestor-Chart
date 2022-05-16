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
    static Person createRootPerson();
    static Person createPerson();
    static void printPerson();
    void printPersons();
    void printPersonsWithFirstName(const std::string &firstName);
    void printPersonsWithLastName(const std::string &lastName);
    void printPersonsWithFullName(const std::string &fullName);
    void printPersonsWithGender(const Person::Gender &Gender);
    std::vector<Person> getPersonsMatchingFirstName(const std::string &firstName);
    std::vector<Person> getPersonsMatchingLastName(const std::string &lastName);
    std::vector<Person> getPersonsMatchingFullName(const std::string &fullName);
    std::vector<Person> getPersonsMatchingGender(const Person::Gender &Gender);


    //TODO: Move these functions to menu-class.
    static std::string genderValueToString(Person::Gender);
    //

    static Person::Gender inputGender();


private:
    typedef std::function<void(Node<Person> *)> nodePointerFunction;
    BinaryTree<Person> persons_;
};

#endif//ANCESTOR_CHART_ANCESTORCHART_H
