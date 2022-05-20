#ifndef ANCESTOR_CHART_MENU_HPP
#define ANCESTOR_CHART_MENU_HPP
#include "AncestorChart.hpp"
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

/**
 * Sets the state of the menu.
 */
bool running = true;

/**
 * Shuts down menu.
 */
void shutdown() {
    running = false;
}

/**
 * Function to print logo to terminal.
 */
void printLogo() {
    std::cout << R"(
    _                        _                ____ _                _
   / \   _ __   ___ ___  ___| |_ ___  _ __   / ___| |__   __ _ _ __| |_
  / _ \ | '_ \ / __/ _ \/ __| __/ _ \| '__| | |   | '_ \ / _` | '__| __|
 / ___ \| | | | (_|  __/\__ \ || (_) | |    | |___| | | | (_| | |  | |_
/_/   \_\_| |_|\___\___||___/\__\___/|_|     \____|_| |_|\__,_|_|   \__|
)" << std::endl;
}

/**
 * Function to print setup menu.
 */
void printSetupMenu() {
    printLogo();
    std::cout << "Please create a root person:"
              << "\n"
              << "[1] Create a root person for the ancestor chart"
              << "\n"
              << "[0] Exit"
              << "\n"
              << "\n"
              << "Enter choice:";
}

/**
 * Function to setup ancestor chart.
 */
Person setupRootPerson() {
    printSetupMenu();
    int choice = inputValidIntBetween(0, 1);
    switch (choice) {
        case 1: {
            Person rootPerson = AncestorChart::createRootPerson();
            return rootPerson;
        }
        case 0: {
            shutdown();
            break;
        }
        default:
            std::cout << "Please enter a number between 0 and 1:" << std::endl;
            break;
    }
    return {};
}

/**
 * Function to print main menu.
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
              << "[5] Print all persons"
              << "\n"
              << "[0] Exit"
              << "\n"
              << "\n"
              << "Enter choice:";
}

/**
 * Function to print search menu.
 */
void printSearchMenu() {
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
}

/**
* Function to display main menu to the terminal.
*/
void mainMenu() {
    Person rootPerson = setupRootPerson();
    AncestorChart ancestorChart(rootPerson);
    while (running) {
        printMainMenu();
        int choice = inputValidIntBetween(0, 5);
        switch (choice) {
            case 1: {
                std::cout << "Who's parent do you want to add?"
                          << "\n"
                          << std::endl;
                printSearchMenu();
                AncestorChart::addPerson(ancestorChart);
                break;
            }
            case 2: {
                std::cout << "Who's detailed information to search for?"
                          << "\n"
                          << std::endl;
                printSearchMenu();
                AncestorChart::printPerson(ancestorChart);
                break;
            }
            case 3: {
                std::cout << "Who's information do you want to edit?"
                          << "\n"
                          << std::endl;
                printSearchMenu();
                AncestorChart::editPerson(ancestorChart);
                break;
            }
            case 4: {
                std::cout << "Which person do you want to delete?"
                          << "\n"
                          << std::endl;
                //printSearchMenu();
                //AncestorChart::deletePerson(ancestorChart);
                break;
            }
            case 5: {
                std::cout << "\nPrinting all persons in ancestor chart: "
                          << "\n"
                          << std::endl;
                AncestorChart::printAllPersons(ancestorChart);
                break;
            }
            case 6: {
                std::cout << "\nDeleting all persons in ancestor chart: "
                          << "\n"
                          << std::endl;
                AncestorChart::deleteAllPersons(ancestorChart);
                break;
            }
            case 0: {
                shutdown();
                break;
            }
            default:
                std::cout << "Please enter a number between 0 and 5:" << std::endl;
                break;
        }
    }
}
#endif//ANCESTOR_CHART_MENU_HPP