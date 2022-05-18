#ifndef PERSON_CLI_PERSON_H
#define PERSON_CLI_PERSON_H
#include "Date.hpp"
#include "Formatting.hpp"
#include <string>

/**
 * Person class.
 */
class Person {
public:
    /**
     * Gender enum.
     * Allows the gender of the person to be either male, female or unknown.
     */
    enum Gender {
        male, /**< Gender value male. */
        female, /**< Gender value female. */
        unknownGender /**< Gender value unknown. */
    };
    /**
     * State enum.
     * Allows the state of the person to be either alive, deceased or unknown.
     */
    enum State {
        alive, /**< State value alive. */
        deceased, /**< State value deceased. */
        unknownState /**< State value unknown. */
    };
    /**
     * Constructor to create a person.
     *
     * @param firstName Firstname of the person.
     * @param lastName Lastname of the person.
     * @param dateOfBirth Date of birth of the person.
     * @param dateOfDeath Date of death of the person.
     * @param gender Gender of the person.
     * @param state State of the person.
     */
    Person(std::string firstName = "Unknown", std::string lastName = "Unknown", Date dateOfBirth = Date(), Date dateOfDeath = Date(), Gender gender = unknownGender, State state = unknownState);
    friend std::ostream &operator << (std::ostream &os, const Person &person);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getFullName() const;
    Date getDateOfBirth() const;
    Date getDateOfDeath() const;
    Gender getGender() const;
    State getState() const;
    static Gender inputGender();

private:
    std::string firstName_;
    std::string lastName_;
    Date dateOfBirth_;
    Date dateOfDeath_;
    Gender gender_;
    State state_;
};
#endif//PERSON_CLI_PERSON_H
