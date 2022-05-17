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
    Date(int day, int month, int year);
    std::string getDate() const;
    void setDate(int day, int month, int year);
    static void enterDate(Date dateType);
    static bool checkIfDateIsValid(int day, int month, int year) ;

private:
    int day_;
    int month_;
    int year_;
};

/**
* Date default constructor.
* Sets the date to 01/01/1970.
*/
Date::Date() {
    day_ = 1;
    month_ = 1;
    year_ = 1970;
}

/**
 * Function to get the date.
 * @return Date as a string in XX/XX/XXXX-format.
 */
std::string Date::getDate() const {
    return std::to_string(day_) + "/" + std::to_string(month_) + "/" + std::to_string(year_);
}

/**
 * Function to set the date.
 * @param day Day of the date.
 * @param month Month of the date.
 * @param year Year of the date.
 */
void Date::setDate(int day, int month, int year){
    day_ = day;
    month_ = month;
    year_ = year;
}

/**
 * Function to check if date is a valid date.
 *
 * @param day Day of the date.
 * @param month Month of the date.
 * @param year Year of the date.
 * @return true if date is valid, false if not.
 */
bool Date::checkIfDateIsValid(int day, int month, int year) {
    if ((day >= 1 && day <= 30) &&
        (month == 4) || (month == 6) ||(month == 9) || (month == 11)) {
        return true;
    }
    else if ((day >= 1 && day <= 31) &&
             (month == 1) || (month == 3) || (month == 5) || (month == 7) ||
             (month == 8) || (month == 10) || (month == 12)) {
        return true;
    }
    else if ((day >= 1 && day <= 28) && (month == 2) && (year % 4 == 0)) {
        return true;
    }
    else if ((day >= 1 && day <= 29) && (month == 2) && (year % 4 != 0)) {
        return true;
    }
    else {
        return false;
    }
}

/**
 * Enter date function.
 * Takes user input as a string,
 * splits the string into day, month and year.
 * Sets the date only if it is a valid date.
 */
void Date::enterDate(Date dateType) {
    std::string dateInput;
    int validDate = false;
    while (!validDate) {
        std::cout << "Please enter the date (DD/MM/YYYY): ";
        std::cin >> dateInput;
        int day = std::stoi(dateInput.substr(0, 2));
        int month = std::stoi(dateInput.substr(3, 2));
        int year = std::stoi(dateInput.substr(6));
        if (checkIfDateIsValid(day, month, year)) {
            dateType.setDate(day, month , year);
            validDate = true;
        }
        else {
            std::cout << "\nInvalid date! Please try again:";
        }
    }
}


#endif//ANCESTOR_CHART_DATE_H
