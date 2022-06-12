#ifndef MY_DATE_H
#define MY_DATE_H

#include <string>
#include <array>
#include <stdexcept>
#include <iostream>

using std::array;
using std::string;
using std::stoi;
using std::cout;
using std::runtime_error;

string alpha = "qazwsxedcrfvtgbyhnujmikolp", num = "0123456789";



class MyDate
{
    friend void printDate(MyDate);
private:
    unsigned year, month, date;

public:
    MyDate(string date_str);
};

MyDate::MyDate(string date_str)
{
    for (auto &c : date_str)
    {
        if (isalpha(c))
        {
            c = tolower(c);
        }
    }
    auto alpha1 = date_str.find_first_of(alpha);
    if (alpha1 != string::npos) // 字母在其中 
    {
        auto alpha2 = date_str.find_last_of(alpha);
        string month_name = date_str.substr(alpha1, alpha2 - alpha1 + 1);
        // 全部转化成小写月份
        if (month_name == "jan" || month_name == "january")
        {
            month = 1;
        }
        else if (month_name == "feb" || month_name == "feburary")
        {
            month = 2;
        }
        else if (month_name == "mar" || month_name == "march")
        {
            month = 3;
        }
        else if (month_name == "apr" || month_name == "april")
        {
            month = 4;
        }
        else if (month_name == "may")
        {
            month = 5;
        }
        else if (month_name == "june" || month_name == "jun")
        {
            month = 6;
        }
        else if (month_name == "july" || month_name == "jul")
        {
            month = 7;
        }
        else if (month_name == "aug" || month_name == "august")
        {
            month = 8;
        }
        else if (month_name == "sep" || month_name == "september")
        {
            month = 9;
        }
        else if (month_name == "oct" || month_name == "october")
        {
            month = 10;
        }
        else if (month_name == "nov" || month_name == "november")
        {
            month = 11;
        }
        else if (month_name == "dec" || month_name == "december")
        {
            month = 12;
        }
        else
        {
            throw runtime_error("The month is invalid!");
        }
        auto num1 = date_str.find_first_of(num, alpha2 + 1);
        auto num2_after = date_str.find_last_not_of(num + alpha);
        date = stoi(date_str.substr(num1, num2_after - 1 - num1));
        year = stoi(date_str.substr(num2_after+1));
    }
    else if (date_str.find_first_of('/')!=string::npos) // 6/28/1922
    {
        auto pos_slash = date_str.find('/');
        auto pos_slash2 = date_str.find('/', pos_slash + 1);
        if (pos_slash2 == string::npos)
        {
            throw runtime_error("There should be two slashes.");
        }
        month = stoi(date_str.substr(0, pos_slash));
        date = stoi(date_str.substr(pos_slash + 1, pos_slash2 - pos_slash));
        year = stoi(date_str.substr(pos_slash2 + 1));
    }
}

void printDate(MyDate date)
{
    cout << "Year: " << date.year << "\n";
    cout << "Month: " << date.month << "\n";
    cout << "Date: " << date.date << "\n";
}
#endif