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
    static void searchForPerson(AncestorChart &ancestorChart);
    static void deletePerson(AncestorChart &ancestorChart);
    static void editPerson(AncestorChart &ancestorChart);
    static void printPerson();
    void printPersons();
    BinaryTree<Person> getBinaryTree() const;
    static Node<Person>* searchForNode(AncestorChart &ancestorChart);
    std::vector<Node<Person>*> getPersonsMatchingFirstName(const std::string &firstName);
    std::vector<Node<Person>*> getPersonsMatchingLastName(const std::string &lastName);
    std::vector<Node<Person>*> getPersonsMatchingFullName(const std::string &firstName, const std::string &lastName);
    std::vector<Node<Person>*> getPersonsMatchingGender(const Person::Gender &Gender);

private:
    typedef std::function<void(Node<Person> *)> nodePointerFunction;
    BinaryTree<Person> binaryTree_;
};

#endif//ANCESTOR_CHART_ANCESTORCHART_HPP
