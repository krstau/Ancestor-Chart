#ifndef PERSON_CLI_PERSON_H
#define PERSON_CLI_PERSON_H
#include "Date.hpp"
#include <string>
#include <utility>

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
     * Person default constructor.
     */
    Person();
    Person(std::string firstName, std::string lastName, Date dateOfBirth, Date dateOfDeath, Gender gender, State state);
    friend std::ostream &operator << (std::ostream &os, const Person &person);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getFullName() const;
    Date getDateOfBirth() const;
    Date getDateOfDeath() const;
    Gender getGender() const;
    State getState() const;
    static Person createPerson();
    static Gender inputGender();
    static std::string genderValueToString(Gender gender);

private:
    std::string firstName_;
    std::string lastName_;
    Date dateOfBirth_;
    Date dateOfDeath_;
    Gender gender_;
    State state_;
};
#endif//PERSON_CLI_PERSON_H
