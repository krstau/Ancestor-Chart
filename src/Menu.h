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
    bool yesOrNo();
    std::string capitalizeString(std::string);
    void mainMenu();
private:
    AncestorChart ancestorChart;
};

#endif//ANCESTOR_CHART_MENU_H
