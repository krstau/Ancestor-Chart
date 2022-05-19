#ifndef ANCESTOR_CHART_DATE_H
#define ANCESTOR_CHART_DATE_H
#include <iostream>
#include <string>
#include "../include/Formatting.hpp"

/**
 * Date class.
 */
class Date {
public:
    Date();
    std::string getDate() const;
    void setDate(int day, int month, int year);
    static void inputDate(Date &dateType);
    static bool isValidDateFormat(std::string dateString);
    static bool isValidDate(int day, int month, int year) ;

private:
    int day_;
    int month_;
    int year_;
};

#endif//ANCESTOR_CHART_DATE_H
