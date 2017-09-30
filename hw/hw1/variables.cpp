/********************
 * COMP11
 * Homework 1
 * Problem 1
 * Shaikat Islam
 *********************/

#include <iostream>
using namespace std;

//int main()
//Purpose: compute the sum of eight integers.
//Parameters: none
//Returns: 0, standard output
int main()
{
    //add value to sum, while value constantly varies with each user
    //inputted integer
    int value, sum = 0;

    //std output
    cout << "Please input eight integers, separated by a space." << endl;

    //at first, the thought of repeating the same cin statement and adding to
    //the var 'sum' seemed appealing, but a bit redundant, so the use of a
    //for loop seemed more efficient and 'elegant'

    //adds 'value' to sum until no. of integers reaches 0
    for (int i = 0; i < 8; i++)
    {
        cin >> value;
        sum += value;
    }

    //std output
    cout << "The sum of these values is " << sum << "." << endl;

    //return statement
    return 0;
}
