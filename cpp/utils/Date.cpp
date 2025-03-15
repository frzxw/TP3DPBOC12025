#pragma once
#include <bits/stdc++.h>

class Date
{
private:
    int day;
    int month;
    int year;

public:
    // Default constructor
    Date() : day(1), month(1), year(1970) {}
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Setters
    void setDay(int d) { day = d; }
    void setMonth(int m) { month = m; }
    void setYear(int y) { year = y; }

    // Getters
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void display() const
    {
        std::cout << std::setw(2) << std::setfill('0') << day << "/"
                  << std::setw(2) << std::setfill('0') << month << "/"
                  << year << std::endl;
    }

    std::string toString() const
    {
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << day << "/"
            << std::setw(2) << std::setfill('0') << month << "/"
            << year;
        return oss.str();
    }

    // Destructor
    ~Date() {}
};