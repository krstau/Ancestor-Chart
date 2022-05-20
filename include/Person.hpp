#ifndef PERSON_CLI_PERSON_H
#define PERSON_CLI_PERSON_H
#include "Date.hpp"
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
        male,
        female,
        unknownGender
    };
    /**
     * State enum.
     * Allows the state of the person to be either alive, deceased or unknown.
     */
    enum State {
        alive,
        deceased,
        unknownState
    };
    /**
     * Person default constructor.
     */
    Person();
    Person(std::string firstName, std::string lastName, Date dateOfBirth, Date dateOfDeath, Gender gender, State state);
    friend std::ostream &operator << (std::ostream &os, const Person &person);
    [[nodiscard]] std::string getFirstName() const;
    [[nodiscard]] std::string getLastName() const;
    [[nodiscard]] std::string getFullName() const;
    [[nodiscard]] Date getDateOfBirth() const;
    [[nodiscard]] Date getDateOfDeath() const;
    [[nodiscard]] Gender getGender() const;
    [[nodiscard]] State getState() const;
    static Person createPerson();
    static Gender inputGender();
    static State inputState();
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
