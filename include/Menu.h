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
    void shutdown();
    ~Menu();
    void startup();
private:
    bool running_ = true;
    AncestorChart ancestorChart_;
};

void Menu::startup(){
    running_ = true;
}

void Menu::shutdown(){
    running_ = false;
}

Menu::~Menu() {
    delete ancestorChart_;
}
Menu::Menu() {
}
#endif//ANCESTOR_CHART_MENU_H
