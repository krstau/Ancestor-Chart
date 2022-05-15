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
   word[0] = std::toupper(word[0]); // NOLINT(cppcoreguidelines-narrowing-conversions)
   return word;
}

/**
* Function to display a menu to the terminal.
*
* @param none.
* @return none.
*/
void Menu::display() {
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
                 << "[2] Search for person"
                 << "\n"
                 << "[3] Add person"
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
           std::cout << "Invalid input, please input a number"
                     << "\n";
           std::cin.clear();
           std::cin.ignore(132, '\n');
       }

       switch (choice) {
           case 1: {
               AncestorChart::createRootPerson();
               break;
           }
           case 2: {
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
               exitMenu = true;
               break;
           default:
               std::cout << "Please enter a number between 0 and 5: "
                         << "\n";
               break;
       }
   }
}
