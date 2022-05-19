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
    /**
     * Constructor to create an ancestor chart.
     *
     * @param firstName Firstname of the person.
     */
    explicit AncestorChart(const Person &rootPerson) : binaryTree_(BinaryTree<Person>(rootPerson)){}
    static void addPerson(AncestorChart &ancestorChart);
    static void printPerson(AncestorChart &ancestorChart);
    // static void deletePerson(AncestorChart &ancestorChart);
    static void editPerson(AncestorChart &ancestorChart);
    static void printAllPersons(AncestorChart &ancestorChart) ;
    static void deleteAllPersons(AncestorChart &ancestorChart);
    BinaryTree<Person> getBinaryTree() const;
    static Node<Person>* searchForNode(AncestorChart &ancestorChart);
    Node<Person> *searchForParent(AncestorChart &ancestorChart, Node<Person> * &nodeToBeDeleted);
    std::vector<Node<Person>*> getPersonsMatchingFirstName(const std::string &firstName);
    std::vector<Node<Person>*> getPersonsMatchingLastName(const std::string &lastName);
    std::vector<Node<Person>*> getPersonsMatchingFullName(const std::string &firstName, const std::string &lastName);
    std::vector<Node<Person>*> getPersonsMatchingGender(const Person::Gender &Gender);


private:
    BinaryTree<Person> binaryTree_;
    typedef std::function<void(Node<Person> *)> nodePointerFunction;

};

#endif//ANCESTOR_CHART_ANCESTORCHART_HPP
