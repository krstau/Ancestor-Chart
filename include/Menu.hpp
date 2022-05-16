#ifndef ANCESTOR_CHART_MENU_HPP
#define ANCESTOR_CHART_MENU_HPP
#include "AncestorChart.hpp"
#include <algorithm>
#include <iostream>
/**
 * Menu class.
 *
 */
class Menu {
public:
    Menu();
    static bool yesOrNo();
    static std::string capitalizeString(std::string);
    static std::string genderValueToString(Person::Gender);
    static Person::Gender inputGender();
    void printMainMenu();
    void mainMenu();
    void run();
    void shutdown();

private:
    bool running_ = true;
    AncestorChart ancestorChart_;
};
#endif//ANCESTOR_CHART_MENU_HPP
