/********************
 * COMP11
 * Homework 2
 * Problem 1
 * Shaikat Islam
 *********************/

#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

// void main()
// Purpose: emulate a basic guessing game.
// Parameters: standard input
// Returns: 0, standard output
int main()
{
    //user reads into this int
    int guess;
    //pseudo-random num generation based on the current time
    srand(time (0));
    //the random num
    int r;
    //range from 5 to 35, inclusive
    r = (rand() % 35) + 5;

    cout << "Your mission is to guess a number, 007, if you choose to accept it."
         << endl;

    //do-while loop that continues to run as long as the guess is not equal to
    //the randomly generated int r
        do
        {
            cin >> guess;
            if (guess < r)
            {
                cout << "Too low, 007! Try again. The fate of the world depends on it.\n";
            }
            else if (guess > r)
            {
                cout << "Too high, 007! Try again. The fate of the world depends on it.\n";
            }
            else
            {
                cout << "Correct. Good work, Bond.\n";
            }
        }
        while ( guess != r);

         //return statement
        return 0;
}//end main
