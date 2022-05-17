#include "../include/Menu.hpp"

/**
 * Main function.
 *
 * @param none.
 * @return 0.
 */
int main() {
    Date dateOfBirth;
    Date::enterDate(dateOfBirth);
    std::cout << dateOfBirth.getDate();
    menu::mainMenu();
    return 0;
}