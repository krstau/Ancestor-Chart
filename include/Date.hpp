#ifndef ANCESTOR_CHART_DATE_H
#define ANCESTOR_CHART_DATE_H
#include "../include/Formatting.hpp"
#include <iomanip>
#include <iostream>

/**
 * Date class.
 */
class Date {
public:
    Date() = default;
    [[nodiscard]] int getDay() const;
    [[nodiscard]] int getMonth() const;
    [[nodiscard]] int getYear() const;
    void setDate(int day, int month, int year);
    friend std::ostream &operator << (std::ostream &os, const Date &date);
    static void inputDate(Date &dateType);
    static bool compareDates(Date &date1, Date &date2);
    static bool isValidDateFormat(std::string dateString);
    static bool isValidDate(int day, int month, int year);

private:
    int day_ = 1;
    int month_ = 1;
    int year_ = 1970;
};

#endif//ANCESTOR_CHART_DATE_H
