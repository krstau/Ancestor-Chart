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
    explicit AncestorChart(const Person &rootPerson) : persons_(BinaryTree<Person>(rootPerson)){}
    static Person createPerson();
    void addPerson();
    void printPerson();
    void printPersons();
    Person getPersonMatchingFirstName(const std::string &firstName) const;
    Person getPersonMatchingLastName(const std::string &lastName) const;
    Person getPersonMatchingFullName(const std::string &firstName, const std::string &lastName) const;
    Person getPersonMatchingGender(const Person::Gender &Gender) const;

    void printPersonsWithFirstName(const std::string &firstName);
    void printPersonsWithLastName(const std::string &lastName);
    void printPersonsWithFullName(const std::string &fullName);
    void printPersonsWithGender(const Person::Gender &Gender);
    std::vector<Node<Person>*> getPersonsMatchingFirstName(const std::string &firstName);
    std::vector<Node<Person>*> getPersonsMatchingLastName(const std::string &lastName);
    std::vector<Node<Person>*> getPersonsMatchingFullName(const std::string &firstName, const std::string &lastName);
    std::vector<Node<Person>*> getPersonsMatchingGender(const Person::Gender &Gender);

private:
    typedef std::function<void(Node<Person> *)> nodePointerFunction;
    BinaryTree<Person> persons_;
};

#endif//ANCESTOR_CHART_ANCESTORCHART_HPP
