#ifndef ANCESTOR_CHART_MENU_HPP
#define ANCESTOR_CHART_MENU_HPP
#include "AncestorChart.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <limits>

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
    std::cout << "Enter gender (male/female):" << std::endl;
    while (true) {
        std::cin >> gender;
        gender = capitalizeString(gender);
        if (gender == "Male") {
            return Person::Gender::male;
        }
        if (gender == "Female") {
            return Person::Gender::female;
        } else {
            std::cout << std::endl << "Error: please enter a valid gender (male/female):" << std::endl;
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
            return "Male";
        }
        case Person::female: {
            return "Female";
        }
        default: {
            return "unknown";
        }
    }
}

//TODO: ask user who this person is the parent of
//with lambda function; find all people matching description and return in a vector
//from the returned vector, ask the user which is the correct person
//ask the user; is the person the mother or the father of the correct person
//if father, add or edit leftNode, if mother add or edit rightNode
Person createPerson() {
    std::string firstName, lastName;
    Date dateOfDeath;
    Date dateOfBirth;
    Person::State state = Person::alive;
    Person::Gender gender;
    std::cout << "Enter firstname:" << std::endl;
    std::cin >> firstName;
    firstName = capitalizeString(firstName);
    std::cout << "Enter lastname:" << std::endl;
    std::cin >> lastName;
    lastName = capitalizeString(lastName);
    std::cout << "Enter date of birth (DD/MM/YYYY):" << std::endl;
    Date::enterDate(dateOfBirth);
    std::cout << "Is the person deceased (Yes/No)?" << std::endl;
    bool answer = yesOrNo();
    if (answer) {// TODO: Check if date of year isn't less than year of birth
        std::cout << "Enter date of death (DD/MM/YYYY):" << std::endl;
        Date::enterDate(dateOfDeath);
        state = Person::deceased;
    }
    gender = inputGender();
    return {firstName, lastName, dateOfBirth, dateOfDeath, gender, state};
}

/**
    * Prints all available information for a person.
    *
    * @param &person.
    * @return os.
    */
std::ostream &operator<<(std::ostream &os, const Person &person) {
    os << "Firstname: " << person.getFirstName() << '\n'
       << "Lastname: " << person.getLastName() << '\n'
       << "Gender: " << genderValueToString(person.getGender()) << '\n'
       << "Date of birth: " << person.getDateOfBirth().getDate() << '\n';
    if (person.getState() == Person::deceased) {
        os << "Date of death: " << person.getDateOfDeath().getDate() << '\n';
    }
    return os;
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
        std::cout << "Invalid input, please input a number" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max() , '\n');
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
    int integer = getNumberFromUser();
    bool validInt = false;
    while (!validInt) {
        if (integer <= upper && integer >= lower) {
            validInt = true;
        } else {
            std::cout << "Please enter a number between: " << lower << " and " << upper << "\n";
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
)"
              << "\n";
}

/**
    * Function to print menu to terminal.
    *
    * @param none.
    * @return none.
    */
void printSetupMenu() {
    printLogo();
    std::cout << "Please create a root person:\n";
}

/**
    * Function to print main menu to terminal.
    *
    * @param none.
    * @return none.
    */
void printMainMenu() {
    printLogo();
    std::cout << "Main menu:"
              << "\n"
              << "[1] Add person"
              << "\n"
              << "[2] Search for person"
              << "\n"
              << "[3] Edit person"
              << "\n"
              << "[4] Delete person"
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
    * Displays available search terms for finding a person.
    * Lets the user select a search term and find a person.
    *
    * @param none.
    * @return person.
    */
std::vector<Node<Person>*> selectSearchTerm(AncestorChart ancestorChart) {  //change back datatype to std::vector<Person> if node implementation does not work!
    //std::vector<Person> returnpersons;   delete this if we make nodes return!
    std::vector<Node<Person>*> returnpersons;
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

    int searchTerm = getValidIntBetween(0, 4);

    switch (searchTerm) {
        case 1: {
            std::string firstName;
            std::cout << "Please enter firstname:";
            std::cin >> firstName;
            firstName = capitalizeString(firstName);
            returnpersons = ancestorChart.getPersonsMatchingFirstName(firstName);
            return returnpersons;
        }
        case 2: {
            std::string lastName;
            std::cout << "Please enter lastname:";
            std::cin >> lastName;
            lastName = capitalizeString(lastName);
            returnpersons = ancestorChart.getPersonsMatchingLastName(lastName);
            return returnpersons;
        }
        case 3: {
            std::string firstName, lastName;
            std::cout << "Please enter firstname:";
            std::cin >> firstName;
            firstName = capitalizeString(firstName);
            std::cout << "Please enter lastname:";
            std::cin >> lastName;
            lastName = capitalizeString(lastName);
            returnpersons = ancestorChart.getPersonsMatchingFullName(firstName, lastName);
            return returnpersons;
        }
        case 4: {
            Person::Gender gender;
            std::cout << "Please enter gender:";
            gender = inputGender();
            returnpersons = ancestorChart.getPersonsMatchingGender(gender);
            return returnpersons;
        }
        case 0: {
            break;
        }
        default:
            std::cout << "Please enter a number between 0 and 4:\n";
            break;
    }
    return returnpersons;
}

/**
    * Function to display a menu to the terminal.
    *
    * @param none.
    * @return none.
    */
void mainMenu() {
    std::cout << "Welcome to:";
    printSetupMenu();
    Person rootPerson = createPerson();
    AncestorChart ancestorChart = AncestorChart(rootPerson);
    std::cout << rootPerson;
    while (running) {

        printMainMenu();

        int choice = getValidIntBetween(0, 4);

        switch (choice) {
            case 1: {
                // Person person();
                // addPerson();
                break;
            }
            case 2: {
                int selectedPerson;
                std::vector<Node<Person>*> persons = selectSearchTerm(ancestorChart);
/*
                if (persons.size() == 0){
                    std::cout << "No person matching search could be found";
                }

                if (persons.size() == 1){
                    std::cout << persons[1]->getData().getFullName() << std::endl;
                }
                else { */
                    std::cout << "\n"
                              << "List of persons: " << std::endl;
                    for (size_t index{}; index < persons.size(); ++index) {
                        std::cout << "\n"
                                  << "[" << index << "]"
                                  << " " << persons[index]->getData().getFullName() << std::endl;
                    }
                    std::cout << "\n"
                              << "Please select a person: " << std::endl;
                    std::cin >> selectedPerson;
                //}
                break;
            }
            case 3: {
                // addPerson();
                break;
            }
            case 4: {

                break;
            }
            case 5: {
                // deletePerson();
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
#endif//ANCESTOR_CHART_MENU_HPP