#pragma once
#include "../util/String.h"
#include <ctime>
#include <iostream>

static const char *input_format = "%Y-%m-%d";
static const char *output_format = "%a %b %d %H:%M %Y";

class Date
{
  private:
    time_t time = 0;

  public:
    Date()
    {
    }
    Date(const MyString &input);

    void print() const;
    void updateCurrentTime();
    time_t getUnixTime() const;

    friend bool operator<(const Date &d1, const Date &d2);
    friend bool isSameDay(const Date &d1, const Date &d2);

    friend std::ostream &operator<<(std::ostream &os, const Date &date);
    friend std::istream &operator>>(std::istream &is, Date &date);
};
