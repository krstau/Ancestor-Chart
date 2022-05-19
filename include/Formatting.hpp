#ifndef ANCESTORCHART_FORMATTING_HPP
#define ANCESTORCHART_FORMATTING_HPP
#include <algorithm>
#include <iostream>
#include <limits>
#include <string>

namespace {
    /**
    * Function that that takes user input from user and checks if it is an integer.
    *
    * @param none.
    * @return a integer.
    */
    int validateNumberInput() {
        int integer;
        while (!(std::cin >> integer)) {
            std::cout << "Invalid input, please input a number" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    int inputValidIntBetween(int lower, int upper) {
        int choice;
        bool validInt = false;
        while (!validInt) {
            choice = validateNumberInput();
            if (choice <= upper && choice >= lower) {
                validInt = true;
            } else {
                std::cout << "Please enter a number between: " << lower << " and " << upper << "\n";
            }
        }
        return choice;
    }

    /**
    * Capitalizes a string.
    *
    * @param string from user input.
    * @return string with capitalized first letter.
    */
    std::string capitalizeString(std::string word) {
        std::string filter = " \n\r\t\f\v";
        size_t start = word.find_first_not_of(filter);
        word = (start == std::string::npos) ? "" : word.substr(start);
        size_t end = word.find_last_not_of(filter);
        word = (end == std::string::npos) ? "" : word.substr(0, end + 1);
        std::transform(std::begin(word), std::end(word), std::begin(word),
                       [](char const &c) {
                           return std::tolower(c);
                       });
        word[0] = std::toupper(word[0]);
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
    * Prompts the user an option to return to main menu.
    *
    * @param none.
    */
    void promptToReturnToMainMenu() {
        std::cout << "\n"
                  << "Enter 0 to return to main menu." << std::endl;
        bool validInput = false;
        while (!validInput) {
            std::string input;
            std::cin >> input;
            if (stoi(input) == 0) {
                validInput = true;
            } else {
                std::cout << "Invalid input, please enter 0 to return to main menu." << std::endl;
            }
        }
    }
}// namespace
#endif//ANCESTORCHART_FORMATTING_HPP
