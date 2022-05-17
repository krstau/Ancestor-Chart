#ifndef ANCESTOR_CHART_DATE_H
#define ANCESTOR_CHART_DATE_H
#include <iostream>
#include <string>

/**
 * Date class.
 */
class Date {
public:
    Date();
    std::string getDate() const;
    void setDate(int day, int month, int year);
    static void enterDate(Date &dateType);
    static bool checkIfDateIsValid(int day, int month, int year) ;

private:
    int day_;
    int month_;
    int year_;
};

#endif//ANCESTOR_CHART_DATE_H
