#ifndef ANCESTOR_CHART_MENU_HPP
#define ANCESTOR_CHART_MENU_HPP
#include "Formatting.hpp"
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
 * Shuts down menu.
 */
void shutdown() {
    running = false;
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
AncestorChart setupAncestorChart() {
    std::cout << "Please create a root person:\n";
    Person rootPerson = AncestorChart::createPerson();
    AncestorChart ancestorChart = AncestorChart(rootPerson);
    return ancestorChart;
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
              << "[5] Print all persons"
              << "\n"
              << "[0] Exit"
              << "\n"
              << "\n"
              << "Enter choice:";
}

void printSearchMenu(){
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
    * Function to display a menu to the terminal.
    *
    * @param none.
    * @return none.
    */
void mainMenu() {
    std::cout << "Welcome to:";
    printLogo();
    AncestorChart ancestorChart = setupAncestorChart();
    while (running) {
        printMainMenu();
        int choice = getValidIntBetween(0, 4);
        switch (choice) {
            case 1: {
                std::cout << "Who's parent do you want to add?" << "\n";
                printSearchMenu();
                AncestorChart::addPerson(ancestorChart);
                break;
            }
            case 2: {
                std::cout << "Something" << "\n";
                printSearchMenu();
                AncestorChart::searchForPerson(ancestorChart);
                break;
            }
            case 3: {
                std::cout << "Something" << "\n";
                printSearchMenu();
                AncestorChart::editPerson(ancestorChart);
                break;
            }
            case 4: {
                std::cout << "Something" << "\n";
                printSearchMenu();
                AncestorChart::deletePerson(ancestorChart);
                break;
            }
            case 5: {
                std::cout << "Something" << "\n";
                printSearchMenu();
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