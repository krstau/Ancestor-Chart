#include "src/Menu.h"

/**
 * Prompts the user for yes or no.
 *
 * @param none.
 * @return true for yes, false for no.
 */
bool Menu::yesOrNo() {
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
* Capitalizes a string.
*
* @param string from user input.
* @return string with capitalized first letter.
*/
std::string Menu::capitalizeString(std::string word) {
    std::transform(std::begin(word), std::end(word), std::begin(word),
                   [](char const &c) {
                       return std::tolower(c);
                   });
    word[0] = std::toupper(word[0]);// NOLINT(cppcoreguidelines-narrowing-conversions)
    return word;
}

/**
* Displays available search terms for finding a person.
* Lets the user select a search term and find a person.
*
* @param none.
* @return none.
*/
void selectSearchTerm() {
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
            AncestorChart::printPersonsWithFirstName(firstName);
            break;
        }
        case 2: {
            std::string lastName;
            std::cout << "Please enter lastname:";
            std::cin >> lastName;
            AncestorChart::printPersonsWithLastName(lastName);
            break;
        }
        case 3: {
            std::string fullName;
            std::cout << "Please enter full name:";
            std::cin >> fullName;
            AncestorChart::printPersonsWithFullName(fullName);
            break;
        }
        case 4: {
            Person::Gender gender;
            std::cout << "Please enter gender:";
            gender = AncestorChart::inputGender();
            AncestorChart::printPersonsWithGender(gender);
            break;
        }
        case 0: {
            Menu::mainMenu();
            break;
        }
        default:
            std::cout << "Please enter a number between 0 and 4:\n";
            break;
    }
}

/**
* Function to display a menu to the terminal.
*
* @param none.
* @return none.
*/
void Menu::mainMenu() {
    bool exitMenu = false;
    while (!exitMenu) {
        std::cout << R"(
   _                        _              ____ _                _
  / \   _ __   ___ ___  ___| |_ ___  _ __ / ___| |__   __ _ _ __| |_
 / _ \ | '_ \ / __/ _ \/ __| __/ _ \| '__| |   | '_ \ / _` | '__| __|
/ ___ \| | | | (_|  __/\__ \ || (_) | |  | |___| | | | (_| | |  | |_
/_/   \_\_| |_|\___\___||___/\__\___/|_|   \____|_| |_|\__,_|_|   \__|
)"
                  << "\n"
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
                  << "[6] Exit"
                  << "\n"
                  << "\n"
                  << "Enter choice:";
        int choice;
        while (!(std::cin >> choice)) {
            std::cout << "Invalid input, please input a number\n";
            std::cin.clear();
            std::cin.ignore(132, '\n');
        }

        switch (choice) {
            case 1: {
                std::cout << "Please create a root person for the ancestor chart: \n";
                AncestorChart::createRootPerson();
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                std::cout << "Please select a search term for the person you want to find: ";
                selectSearchTerm();
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
                exitMenu = true;
                break;
            default:
                std::cout << "Please enter a number between 0 and 5: "
                          << "\n";
                break;
        }
    }
}