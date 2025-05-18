#include "Date.h"

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    int const maxDay = getMaxDays();
    if (day <= 0 || day>maxDay)
        return;
    Date::day = day;
}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

Months Date::getMonth() const {
    return month;
}

void Date::setMonth(Months month) {
    Date::month = month;
    int maxDay = getMaxDays();
    if (day>maxDay)
        day = maxDay;
}

int Date::getMaxDays() {
    switch(month) {
        // Trenta dì conta Novembre con April Giugno e Settembre. Di ventotto ce n'è uno. Tutti gli altri ne han trentuno.
        case Months::Nov:
        case Months::Apr:
        case Months::Jun:
        case Months::Sep:
            return 30;
        case Months::Feb:
            return 28; // FIXME take into account leap years: https://en.wikipedia.org/wiki/Leap_year#Algorithm
        default:
            return 31;
    }
}

Date::Date(int y, Months m, int d) : day(d), month(m), year(y) {
    if (day > getMaxDays())
        day = 1;
}

std::ostream &operator<<(std::ostream &stream, const Date &date) {
    stream << date.day << "/" << date.getMonthString() << "/" << date.year;
    return stream;
}

std::string Date::getMonthString() const {
    switch (month) {
        case Months::Jan:
            return "Jan";
        case Months::Feb:
            return "Feb";
        case Months::Mar:
            return "Mar";
        case Months::Apr:
            return "Apr";
        case Months::May:
            return "May";
        case Months::Jun:
            return "Jun";
        case Months::Jul:
            return "Jul";
        case Months::Aug:
            return "Aug";
        case Months::Sep:
            return "Sep";
        case Months::Oct:
            return "Oct";
        case Months::Nov:
            return "Nov";
        case Months::Dec:
            return "Dec";
    }
}

bool DateComparator::operator()(const Date &lhs, const Date &rhs) const {
    bool result = false;

    if (lhs.getYear() < rhs.getYear()) {
        result = true;
    }
    else if (lhs.getMonth() < rhs.getMonth()) {
        result = true;
    }
    else if (lhs.getDay() < rhs.getDay()) {
        result = true;
    }

    return result;
};
