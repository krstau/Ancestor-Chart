#ifndef ANCESTOR_CHART_DATE_H
#define ANCESTOR_CHART_DATE_H
#include "../include/Formatting.hpp"
#include <iomanip>
#include <iostream>
#include <string>

/**
 * Date class.
 */
class Date {
public:
    Date() = default;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDate(int day, int month, int year);
    void printDate();
    static void inputDate(Date &dateType);
    static bool isValidDateFormat(std::string dateString);
    static bool isValidDate(int day, int month, int year);

private:
    int day_ = 01;
    int month_ = 01;
    int year_ = 1970;
};

#endif//ANCESTOR_CHART_DATE_H
