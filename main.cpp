// #include "src/BinaryTree.h"
// #include "src/Node.h"
#include "src/Date.h"
#include "src/Person.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string test;

std::string capitalizeString(std::string word) {
    std::transform(std::begin(word), std::end(word), std::begin(word),
                   [](char const &c) {
                       return std::tolower(c);
                   });
    word[0] = std::toupper(word[0]);
    return word;
}

Gender inputGender() {// Function that takes in user input as a string and returns gender
    std::string gender;
    std::cout << "Enter gender (male/female): ";
    while (true) {
        std::cin >> gender;
        gender = capitalizeString(gender);
        if (gender == "Male") {
            return Gender::male;
        }
        if (gender == "Female") {
            return Gender::female;
        } else {
            std::cout << "\nError: please enter a valid gender (male/female): ";
        }
    }
}

std::string genderValueToString(Gender gender) {
    switch (gender) {
        case male: {
            return "male";
        }
        case female: {
            return "female";
        }
        case unknownGender: {
            return "unknown";
        }
    }
}

bool yesOrNo() {
    std::string answer;
    while (true) {
        std::cin >> answer;
        answer = capitalizeString(answer);
        if (answer == "Yes") {
            return true;
        }
        if (answer == "No") {
            return false;
        } else {
            std::cout << "\nError: please enter a valid choice (yes/no): ";
        }
    }
}

Person createPerson() {
    std::string firstName, lastName, dateOfBirth, dateOfDeath;
    State state = unknownState;
    Gender gender = unknownGender;
    std::cout << "Enter firstname:";
    std::cin >> firstName;
    std::cout << "Enter lastname:";
    std::cin >> lastName;
    std::cout << "Enter date of birth (DD/MM/YYYY):";
    std::cin >> dateOfBirth;
    std::cout << "Is the person deceased (Yes/No)?";
    bool answer = yesOrNo();
    if (answer) {
        std::cout << "Enter date of death (DD/MM/YYYY):";
        std::cin >> dateOfDeath;
        state = deceased;
    }
    gender = inputGender();
    Person person(firstName, lastName, dateOfBirth, dateOfDeath, gender, state);
    return person;
}

void printPersonInfo(const Person &person) {// Function to print information about a person
    std::cout << "Showing information for: " << '\n';
    std::cout << "Firstname: " << person.getFirstName() << '\n';
    std::cout << "Lastname: " << person.getLastName() << '\n';
    std::cout << "Date of birth: " << person.getDateOfBirth() << '\n';
    if (!person.getStatus()) {
        std::cout << "Date of death: " << person.getDateOfDeath() << '\n';
    }
    std::string gender = genderValueToString(person.getGender());
    std::cout << "Gender: " << capitalizeString(gender) << '\n'
              << '\n';
}

void printPerson() {// Function to print a person by first and last name
    std::string firstName, lastName;
    std::cout << "Enter the firstname of the person that you want to display: ";
    std::cin >> firstName;
    firstName = capitalizeString(firstName);
    std::cout << "Enter the lastname of the person that you want to display: ";
    std::cin >> lastName;
    lastName = capitalizeString(lastName);
}

void displayMenu() {// Function to display menu
    bool quit = false;
    while (!quit) {
        std::cout << R"(

    _                        _              ____ _                _
   / \   _ __   ___ ___  ___| |_ ___  _ __ / ___| |__   __ _ _ __| |_
  / _ \ | '_ \ / __/ _ \/ __| __/ _ \| '__| |   | '_ \ / _` | '__| __|
 / ___ \| | | | (_|  __/\__ \ || (_) | |  | |___| | | | (_| | |  | |_
/_/   \_\_| |_|\___\___||___/\__\___/|_|   \____|_| |_|\__,_|_|   \__|
)"
                  << "\n";
        std::cout << "Main menu:"
                  << "\n";
        std::cout << "[1] Print all persons"
                  << "\n";
        std::cout << "[2] Search for person"
                  << "\n";
        std::cout << "[3] Add person"
                  << "\n";
        std::cout << "[4] Edit person"
                  << "\n";
        std::cout << "[5] Delete person"
                  << "\n";
        std::cout << "[6] Exit"
                  << "\n"
                  << "\n";
        std::cout << "Enter choice:";
        int choice;
        while (!(std::cin >> choice)) {
            std::cout << "Invalid input, please input a number"
                      << "\n";
            std::cin.clear();
            std::cin.ignore(132, '\n');
        }

        switch (choice) {
            case 1: {
                //printPeople();
                break;
            }
            case 2: {
                printPerson();
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                // TODO editPerson(); Work in progress
                break;
            }
            case 5: {
                //deletePerson();
                break;
            }
            case 0:
                quit = true;
                break;
            default:
                std::cout << "Please enter a number between 0 and 5: "
                          << "\n";
                break;
        }
    }
}

int main() {
    Date dateOfBirth;
    dateOfBirth.setDate();
    dateOfBirth.printDate();
    std::cout << dateOfBirth.getDate();
    return 0;
}