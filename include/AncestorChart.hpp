#ifndef ANCESTOR_CHART_ANCESTORCHART_HPP
#define ANCESTOR_CHART_ANCESTORCHART_HPP
#include "BinaryTree.hpp"
#include <algorithm>
#include <string>

/**
 * AncestorChart class
 */
class AncestorChart {
public:
    explicit AncestorChart(const Person& rootPerson);
    static Person createRootPerson();
    static void addPerson(AncestorChart &ancestorChart);
    static void printPerson(AncestorChart &ancestorChart);
    static void editPerson(AncestorChart &ancestorChart);
    static void deletePerson(AncestorChart &ancestorChart);
    static void printAllPersons(AncestorChart &ancestorChart) ;
    static void deleteAllPersons(AncestorChart &ancestorChart);
    static Node<Person>* searchForNode(AncestorChart &ancestorChart);
    static Node<Person> *searchForParent(AncestorChart &ancestorChart, Node<Person> * &nodeToBeDeleted);
    [[nodiscard]] BinaryTree<Person> getBinaryTree() const;
    std::vector<Node<Person>*> getPersonsMatchingFirstName(const std::string &firstName);
    std::vector<Node<Person>*> getPersonsMatchingLastName(const std::string &lastName);
    std::vector<Node<Person>*> getPersonsMatchingFullName(const std::string &firstName, const std::string &lastName);
    std::vector<Node<Person>*> getPersonsMatchingGender(const Person::Gender &Gender);

private:
    BinaryTree<Person> binaryTree_;
    typedef std::function<void(Node<Person> *)> nodePointerFunction;
};

#endif//ANCESTOR_CHART_ANCESTORCHART_HPP
