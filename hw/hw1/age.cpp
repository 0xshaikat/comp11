/********************
 * COMP11
 * Homework 1
 * Problem 2
 * Shaikat Islam
 *
 * Test input: 2 years
 * Expected output: 12 months, 730 days, 17520 hours
 *
 * Test input: 42 years
 * Expected output: 504 months, 15330 days, 367920 hours
 *
 * Test input: 114 years
 * Expected output: 1368 months, 41610 days, 998640 hours
 *********************/

#include <iostream>
using namespace std;

//int main()
//Purpose: return user's age in hours, minutes, and months
//Parameters: none
//Returns: 0, standard output
int main()
{
    //vars of type int to keep track of the user's age in various increments
    //constant integers to keep track of all the intervals
    int age, months, days, hours;
    const int months_in_year = 12;
    const int days_in_year = 365;
    const int hours_in_year = 8760;

    //std output
    cout << "Wow! You look so young! How old are you really? (in years)" << endl;

    //std input
    cin >> age;

    //multiplying it out
    months = age * months_in_year;
    days = age * days_in_year;
    hours = age * hours_in_year;

    //std output
    cout << "Wow! That's incredible! You are " << months << " months, " << days
         << " days, " << "and " << hours << " hours old!" << endl;

    //return statement
    return 0;
}
