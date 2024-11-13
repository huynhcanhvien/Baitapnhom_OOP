#include "Date.hpp"
#include <stdexcept>
using namespace std;

bool checkNamNhuan(const int& year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDayInMonth(const int& month, const int& year) {
    int dayInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month < 1 || month > 12) {
        throw invalid_argument("Tháng không hợp lệ");
    }
    if (checkNamNhuan(year)) dayInMonth[1] = 29;
    return dayInMonth[month - 1];
}

bool isValid(const Date& date) {
    if (date.year < 0 || date.month < 1 || date.month > 12 || date.day < 1) {
        return false;
    }
    return date.day <= getDayInMonth(date.month, date.year);
}

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
    if (!isValid(*this)) {
        throw invalid_argument("Ngày không hợp lệ trong constructor");
    }
}

Date::Date(const Date& date) : day(date.day), month(date.month), year(date.year) {}

std::ostream& operator <<(std::ostream& out, const Date& date) {
    out << date.day << "/" << date.month << "/" << date.year;
    return out;
}

std::istream& operator >>(std::istream& in, Date& date) {
    do {
        std::cout << "Nhập ngày, tháng, năm: ";
        in >> date.day >> date.month >> date.year;
        if (!isValid(date))
            cout << "Ngày không hợp lệ, nhập lại!\n";
    } while (!isValid(date));

    return in;
}

Date Date::operator +(int days) {
    Date new_date(*this);
    new_date.day += days;

    while (new_date.day > getDayInMonth(new_date.month, new_date.year)) {
        new_date.day -= getDayInMonth(new_date.month, new_date.year);
        new_date.month++;
        if (new_date.month > 12) {
            new_date.month = 1;
            new_date.year++;
        }
    }
    return new_date;
}

Date Date::operator -(int days) {
    Date new_date(*this);

    while (days > 0) {
        if (new_date.day > days) {
            new_date.day -= days;
            days = 0;
        } else {
            days -= new_date.day;
            new_date.month--;
            if (new_date.month < 1) {
                new_date.month = 12;
                new_date.year--;
            }
            new_date.day = getDayInMonth(new_date.month, new_date.year);
        }
    }

    return new_date;
}

Date& Date::operator ++() {
    day++;
    if (day > getDayInMonth(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}

Date Date::operator ++(int) {
    Date temp = *this;
    ++(*this);
    return temp;
}

Date& Date::operator --() {
    day--;
    if (day < 1) {
        month--;
        if (month < 1) {
            month = 12;
            year--;
        }
        day = getDayInMonth(month, year);
    }
    return *this;
}

Date Date::operator --(int) {
    Date temp = *this;
    --(*this);
    return temp;
}

const Date& Date::operator =(const Date& x) {
    if (this != &x) {
        this->day = x.day;
        this->month = x.month;
        this->year = x.year;
    }
    return *this;
}
