#ifndef PERSON_CLI_PERSON_H
#define PERSON_CLI_PERSON_H
//#include "Date.h"
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
        unknownState/**< State value unknown. */
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
    Person(std::string firstName, std::string lastName, std::string dateOfBirth, std::string dateOfDeath, Gender gender, State state);
    friend std::ostream& operator << (std::ostream& os, const Person& dt);
    [[nodiscard]] std::string getFirstName() const;
    [[nodiscard]] std::string getLastName() const;
    [[nodiscard]] std::string getFullName() const;
    [[nodiscard]] std::string getDateOfBirth() const;
    [[nodiscard]] std::string getDateOfDeath() const;
    [[nodiscard]] Gender getGender() const;
    [[nodiscard]] State getState() const;

private:
    std::string firstName_;
    std::string lastName_;
    std::string dateOfBirth_;
    std::string dateOfDeath_;
    Gender gender_;
    State state_;
};


#endif//PERSON_CLI_PERSON_H
