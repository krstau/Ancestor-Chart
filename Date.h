#ifndef ANCESTOR_CHART_DATE_H
#define ANCESTOR_CHART_DATE_H
#include <iostream>
#include <string>

class Date {
public:
    Date();
    std::string getDate() const;
    void printDate() const;
    void setDate();

private:
    int day_;
    int month_;
    int year_;
};

Date::Date() {// Date defaults to 01/01/1970
    day_ = 1;
    month_ = 1;
    year_ = 1970;
}

std::string Date::getDate() const {
    return std::to_string(day_) + "/" + std::to_string(month_) + "/" + std::to_string(year_);
}

void Date::printDate() const {
    std::cout << day_ << "/" << month_ << "/" << year_;
}

void Date::setDate() {
    std::string date;
    char delimiter = '/';
    bool validDay = false, validMonth = false, validYear = false;
    while (!validDay || !validMonth || !validYear) {
        std::cout << "Please enter the date (DD/MM/YYYY): ";
        std::cin >> date;
        int day = std::stoi(date.substr(0, 2));
        int month = std::stoi(date.substr(3, 2));
        int year = std::stoi(date.substr(6));
        if (day < 1 || day > 31) {
            std::cout << "Day must be between 1 and 31\n";
        } else {
            day_ = day;
            validDay = true;
        }
        if (month < 1 || month > 12) {
            std::cout << "Month must be between 1 and 12\n";
        } else {
            month_ = month;
            validMonth = true;
        }
        if (year < 1500 || year > 3000) {
            std::cout << "Year must be between 1500 and 3000\n";
        } else {
            year_ = year;
            validYear = true;
        }
    }
}

#endif//ANCESTOR_CHART_DATE_H
