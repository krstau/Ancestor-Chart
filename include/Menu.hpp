#ifndef ANCESTOR_CHART_MENU_HPP
#define ANCESTOR_CHART_MENU_HPP
#include "AncestorChart.hpp"
#include "Person.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

namespace menu {
    /**
     * Sets the state of the menu.
     */
    bool running = true;

    /**
    * Capitalizes a string.
    *
    * @param string from user input.
    * @return string with capitalized first letter.
    */
    std::string capitalizeString(std::string word) {
        std::transform(std::begin(word), std::end(word), std::begin(word),
                       [](char const &c) {
                           return std::tolower(c);
                       });
        word[0] = std::toupper(word[0]);// NOLINT(cppcoreguidelines-narrowing-conversions) TODO: Find better alternative?
        return word;
    }

    /**
    * Prompts the user for yes or no.
    *
    * @param none.
     * @return true for yes, false for no.
    */
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
                std::cout << "\nError: please enter a valid choice (yes/no):";
            }
        }
    }

    /**
     * Prompts the user for entering gender for either male or female.
    *
    * @param none.
    * @return none.
    */
    Person::Gender inputGender() {
        std::string gender;
        std::cout << "Enter gender (male/female): ";
        while (true) {
            std::cin >> gender;
            gender = capitalizeString(gender);
            if (gender == "Male") {
                return Person::Gender::male;
            }
            if (gender == "Female") {
                return Person::Gender::female;
            } else {
                std::cout << "\nError: please enter a valid gender (male/female):";
            }
        }
    }

    /**
    * Converts a gender enum to a string.
    *
    * @param gender.
    * @return the gender in string format.
    */
    std::string genderValueToString(Person::Gender gender) {
        switch (gender) {
            case Person::male: {
                return "male";
            }
            case Person::female: {
                return "female";
            }
            default: {
                return "unknown";
            }
        }
    }

    /**
    * Displays available search terms for finding a person.
    * Lets the user select a search term and find a person.
    *
    * @param none.
    * @return none.
    */
    Person selectSearchTerm(const AncestorChart &ancestorChart) {
        int searchTerm;
        std::cout << "\n"
                  << "Please select a search term, or enter 0 to return to main menu:"
                  << "\n"
                  << "[1] Firstname"
                  << "\n"
                  << "[2] Lastname"
                  << "\n"
                  << "[3] Full name"
                  << "\n"
                  << "[4] Gender"
                  << "\n"
                  << "[0] Return to main menu"
                  << "\n"
                  << "\n"
                  << "Enter choice:";
        while (!(std::cin >> searchTerm)) {
            std::cout << "Invalid input, please input a number\n";
            std::cin.clear();
            std::cin.ignore(132, '\n');
        }
        switch (searchTerm) {
            case 1: {
                std::string firstName;
                std::cout << "Please enter firstname:";
                std::cin >> firstName;
                Person person = ancestorChart.getPersonMatchingFirstName(firstName);
                return person;
                break;
            }
            case 2: {
                std::string lastName;
                std::cout << "Please enter lastname:";
                std::cin >> lastName;
                Person person = ancestorChart.getPersonMatchingLastName(lastName);
                return person;
                break;
            }
            case 3: {
                std::string fullName;
                std::cout << "Please enter full name:";
                std::cin >> fullName;
                Person person = ancestorChart.getPersonMatchingFullName(fullName);
                return person;
                break;
            }
            case 4: {
                Person::Gender gender;
                std::cout << "Please enter gender:";
                gender = inputGender();
                Person person = ancestorChart.getPersonMatchingGender(gender);
                return person;
                break;
            }
            case 0: {
                break;
            }
            default:
                std::cout << "Please enter a number between 0 and 4:\n";
                break;
        }
    }


    /**
    * Function that that takes user input from user and checks if it is an integer.
    *
    * @param none.
    * @return a integer.
    */
    int getNumberFromUser() {
        int integer;
        while (!(std::cin >> integer)) {
            std::cout << "Invalid input, please input a number\n";
            std::cin.clear();
            std::cin.ignore(132, '\n');
        }
        return integer;
    }

    /**
    * Function that takes an integer between a lower and upper value.
    *
    * @param lower.
    * @param upper.
    * @return integer between upper and lower.
    */
    int getValidIntBetween(int lower, int upper) {
        int integer;
        bool validInt = false;
        while (!validInt) {
            std::cout << "Please enter a number between: " << lower << "and" << upper << "\n";
            integer = getNumberFromUser();
            if (integer <= upper && integer >= lower) {
                validInt = true;
            }
        }
        return integer;
    }
    /**
    * Function to print logo to terminal.
    *
    * @param none.
    * @return none.
    */
    void printLogo() {
        std::cout << R"(
   _                        _              ____ _                _
  / \   _ __   ___ ___  ___| |_ ___  _ __ / ___| |__   __ _ _ __| |_
 / _ \ | '_ \ / __/ _ \/ __| __/ _ \| '__| |   | '_ \ / _` | '__| __|
/ ___ \| | | | (_|  __/\__ \ || (_) | |  | |___| | | | (_| | |  | |_
/_/   \_\_| |_|\___\___||___/\__\___/|_|   \____|_| |_|\__,_|_|   \__|
)";
    }

    /**
    * Function to print menu to terminal.
    *
    * @param none.
    * @return none.
    */
    void printMenu1() {
        printLogo();
        std::cout << "Please create a root person";
    }

    /**
    * Function to print main menu to terminal.
    *
    * @param none.
    * @return none.
    */
    void printMainMenu() {
        printLogo();
        std::cout << "\n"
                  << "Main menu:"
                  << "\n"
                  << "[1] Create a new ancestor chart"
                  << "\n"
                  << "[2] Add person"
                  << "\n"
                  << "[3] Search for person"
                  << "\n"
                  << "[4] Edit person"
                  << "\n"
                  << "[5] Delete person"
                  << "\n"
                  << "[0] Exit"
                  << "\n"
                  << "\n"
                  << "Enter choice:";
    }

    void shutdown() {
        running = false;
    }

    /**
    * Function to display a menu to the terminal.
    *
    * @param none.
    * @return none.
    */
    void mainMenu() {

        printMenu1();
        Person rootPerson = AncestorChart::createPerson();
        AncestorChart ancestorChart = AncestorChart(rootPerson);
        while (running) {

            printMainMenu();

            int choice = getValidIntBetween(0, 5);

            switch (choice) {
                case 1: {
                    std::cout << "Please create a root person for the ancestor chart: \n";
                    break;
                }
                case 2: {
                    // Person person();
                    // addPerson();
                    break;
                }
                case 3: {
                    std::cout << "Please select a search term for the person you want to find: ";
                    selectSearchTerm(ancestorChart);
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
                    shutdown();
                    break;
                default:
                    std::cout << "Please enter a number between 0 and 5: "
                              << "\n";
                    break;
            }
        }
    }
}// namespace menu
#endif//ANCESTOR_CHART_MENU_HPP