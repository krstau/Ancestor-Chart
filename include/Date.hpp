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
    Date() = default;
    std::string getDate() const;
    void setDate(int day, int month, int year);
    static void enterDate(Date &dateType);
    static bool isValidDateFormat(std::string dateString);
    static bool isValidDate(int day, int month, int year) ;

private:
    int day_ = 01;
    int month_ = 01;
    int year_ = 1970;
};

#endif//ANCESTOR_CHART_DATE_H
