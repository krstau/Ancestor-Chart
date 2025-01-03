#include "../include/Date.hpp"

/**
 * Function to get the day.
 * @return day_
 */
int Date::getDay() const {
    return day_;
}

/**
 * Function to get the day.
 * @return month_
 */
int Date::getMonth() const {
    return month_;
}

/**
 * Function to get the day.
 * @return year_
 */
int Date::getYear() const {
    return year_;
}

/**
 * Function to set the date.
 * @param day Day of the date.
 * @param month Month of the date.
 * @param year Year of the date.
 */
void Date::setDate(int day, int month, int year) {
    day_ = day;
    month_ = month;
    year_ = year;
}

/**
 * Function to check if date is a valid date.
 * @param day Day of the date.
 * @param month Month of the date.
 * @param year Year of the date.
 * @return true if date is valid, false if not.
 */
bool Date::isValidDate(int day, int month, int year) {
        if (((((day >= 1 && day <= 30) &&
           ((month == 4) ||
            (month == 6) ||
            (month == 9) ||
            (month == 11))) ||
          ((day >= 1 && day <= 31) &&
           (month == 1) ||
           (month == 3) ||
           (month == 5) ||
           (month == 7) ||
           (month == 8) ||
           (month == 10) ||
           (month == 12)) ||
          ((day >= 1 && day <= 28) &&
           (month == 2) &&
           (year % 4 != 0)) ||
          ((day >= 1 && day <= 29) &&
           (month == 2) &&
           (year % 4 == 0))))) {
        return true;
    }
        else {
        return false;
    }
}

/**
 * Validates if date is correct format.
 *
 * @param Date as a string.
 * @return true if the date is correct format DD/MM/YYYY.
 */
bool Date::isValidDateFormat(std::string dateString) {
    if (dateString.size() != 10) return false;
    char delimiter = '/';
    if ((dateString[2] != delimiter) || (dateString[5] != delimiter)) return false;
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) continue;
        if (!isdigit(dateString[i])) return false;
    }
    return true;
}

/**
 * Compares if date of death is less than date of birth.
 * @param &dateOfBirth
 * @param &dateOfDeath
 * @return true if the date is correct format DD/MM/YYYY.
 */
bool Date::compareDates(Date &date1, Date &date2) {
    if ((date1.getYear() < date2.getYear() ||
         (date1.getYear() == date2.getYear() &&
          date1.getMonth() < date2.getMonth()) ||
         (date1.getYear() == date2.getYear() &&
          date1.getMonth() == date2.getMonth() &&
          date1.getDay() <= date2.getDay()))) {
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
 * @param date
 */
void Date::inputDate(Date &date) {
    std::string dateInput;
    int validDate = false;
    while (!validDate) {
        std::cin >> dateInput;
        if (isValidDateFormat(dateInput)) {
            int day = std::stoi(dateInput.substr(0, 2));
            int month = std::stoi(dateInput.substr(3, 2));
            int year = std::stoi(dateInput.substr(6));
            if (isValidDate(day, month, year)) {
                date.setDate(day, month, year);
                validDate = true;
            }
        } else {
            std::cout << "\nInvalid date! Please enter a valid date (DD/MM/YYYY): \n";
        }
    }
}

/**
 * Prints the date in DD/MM/YYYY format.
 * @param date.
 * @return os.
 */
std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << std::setw(2) << std::setfill('0') << date.getDay()
       << "/" << std::setw(2) << std::setfill('0') << date.getMonth()
       << "/" << std::setw(4) << std::setfill('0') << date.getYear();
    return os;
}