/********************
 * COMP11
 * Homework 3
 * Problem 1
 * Shaikat Islam
 *********************/

#include<string>
#include<iostream>

using namespace std;

//int main()
//Purpose: Print out a specialized set-up of bowling balls.
//Parameters: none
//Output: 0, standard output.
int main()
{
    //variables
    //which pin
    int current_pin = 1;
    int running_total = 0;

    //for loop to calculate num of pins
    for (int i = 0; i < 73; i++)
    {
        cout << "Row " << i + 1 << ": " << current_pin << endl;
        current_pin += 2;
        running_total += current_pin;
    }//end for
    cout << "TOTAL PINS: " << running_total << endl;
}//end main
