#ifndef ANCESTOR_CHART_MENU_H
#define ANCESTOR_CHART_MENU_H
#include "AncestorChart.h"
#include <iostream>
#include <algorithm>
/**
 * Menu class.
 *
 */
class Menu {
public:
    Menu();
    bool yesOrNo();
    std::string capitalizeString(std::string);
    void printMainMenu();
    void mainMenu();
    void execute();
    void shutdown();

private:
    bool running_ = true;
    AncestorChart ancestorChart_;
};
#endif//ANCESTOR_CHART_MENU_H
