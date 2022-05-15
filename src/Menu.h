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
    static bool yesOrNo();
    static std::string capitalizeString(std::string);
    static void mainMenu();
private:
};

#endif//ANCESTOR_CHART_MENU_H
