#include "./Headers/Date.h"
#include <ctime>
#include <iostream>

bool operator<(const Date &d1, const Date &d2)
{
    return d1.time < d2.time;
}

void Date::print() const
{
    char buf[50];
    struct tm *timeInfo = localtime(&time);
    strftime(buf, sizeof(buf), output_format, timeInfo);
    std::cout << buf << '\n';
}

Date::Date(const MyString &input)
{

    struct tm timeStruct = {};
    if (strptime(input.c_str(), input_format, &timeStruct) == NULL)
    {
        throw std::invalid_argument("Invalid time format or string");
    }
    time = mktime(&timeStruct);
}

void Date::updateCurrentTime()
{
    time = std::time(nullptr);
}

bool isSameDay(const Date &d1, const Date &d2)
{
    struct tm tm1;
    struct tm tm2;

    localtime_r(&d1.time, &tm1);
    localtime_r(&d2.time, &tm2);

    return (tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon && tm1.tm_mday == tm2.tm_mday);
}

time_t Date::getUnixTime() const
{
    return time;
}

Date::Date(long unixTime)
{
    time = unixTime;
}
