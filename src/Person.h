#ifndef PERSON_CLI_PERSON_H
#define PERSON_CLI_PERSON_H
#include <string>

enum Gender {male, female, unknownGender};
enum State {alive, deceased, unknownState};

class Person {
public:
    Person(std::string firstName, std::string lastName, std::string dateOfBirth, std::string dateOfDeath, Gender gender, State state);
    [[nodiscard]] std::string getFirstName() const;
    [[nodiscard]] std::string getLastName() const;
    [[nodiscard]] std::string getFullName() const;
    [[nodiscard]] std::string getDateOfBirth() const;
    [[nodiscard]] std::string getDateOfDeath() const;
    [[nodiscard]] Gender getGender() const;
    [[nodiscard]] State getStatus() const;

private:
    std::string firstName_;
    std::string lastName_;
    std::string dateOfBirth_;
    std::string dateOfDeath_;
    Gender gender_;
    State state_;
};

#endif//PERSON_CLI_PERSON_H
