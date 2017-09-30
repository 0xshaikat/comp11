/********************
 * COMP11
 * Homework 2
 * Problem 3
 * Shaikat Islam
 *********************/

#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;
//TODO FIX W_PEG
//bool exist(char a[], char q)
//Parameters: char a[] and char q
//Purpose: Check if a given value exists in an array of size 4.
//Returns: bool
bool exist (char a[], char q)
{
    for (int i = 0; i < 4; i++)
    {
        if (q == a[i])
        {
            //prevent duplication on next run
            a[i] = '.';
            return true;
            break;
        }//end if
    }//end for
    return false;
}////end exist

//int main()
//Parameters: standard input
//Purpose: Emulate the game Mastermind.
//Returns: 0, standard output
int main()
{
    //==============================GAME MECHANICS==============================
    //user's guesses
    char g_1, g_2, g_3, g_4;
    //an array of the users guesses
    char user_guesses[4];
    //the actual colors
    char colors[] = {'r', 'o', 'y', 'g', 'b', 'v'};
    //solution array
    char solution[4];
    //answer to yes/no
    char choice = 'Y';

    //num black/white_pegs
    int b_peg = 0, w_peg = 0;
    //pseudo-random num generation based on the current time
    srand(time (0));
    //the random num
    int ran;

    //populate solution array
    for (int i = 0; i < 4; i++)
    {
        //random number from 1 to 5, inclusive
        ran = rand() % 5 + 1;
        //assign chars from color[]  to indices of solution[]
        solution[i] = colors[ran];
    }

    //==============================STRINGS=====================================
    string enter_guess = "Enter your guesses!\n";
    string invalid = "Invalid choice; try again!\n";
    string peg_one = "Peg one? Enter r, o, y, g, b, or v.\n";
    string peg_two = "Peg two? Enter r, o, y, g, b, or v.\n";
    string peg_three = "Peg three? Enter r, o, y, g, b, or v.\n";
    string peg_four = "Peg four? Enter r, o, y, g, b, or v.\n";
    string result_a = "Result: ";
    string result_b = " black pegs and ";
    string result_c = " white pegs\n";
    string guess_again = "Guess again? Enter Y/N\n";
    string congrats = "!!!!!!!!!!!!!!!!!!!!!!!!!\ncongrats\n!!!!!!!!!!!!!!!!!!!!!!!!!\n";
    string secret_code = "Secret code was: ";

    //============================GAME==========================================
    //as long as choice remains 'Y', the while loop will run
    while (choice == 'Y')
    {
        //GUESS 1
        cout << enter_guess;
        cout << peg_one;
        cin >> g_1;
        //check for proper user input
        do
        {
            if (!(g_1 == 'r' || g_1 == 'o' || g_1 == 'y' || g_1 == 'g' || g_1 == 'b' || g_1 == 'v'))
            {
                cout << invalid;
                cin >> g_1;
            }//end if

        }//end do
        while (!(g_1 == 'r' || g_1 == 'o' || g_1 == 'y' || g_1 == 'g' || g_1 == 'b' || g_1 == 'v'));
        //populate user_guess array with user's guesses
        user_guesses[0] = g_1;

        //GUESS 2
        cout << peg_two;
        cin >> g_2;
        //check for proper user input
        do
        {
            if (!(g_2 == 'r' || g_2 == 'o' || g_2 == 'y' || g_2 == 'g' || g_2 == 'b' || g_2 == 'v'))
            {
                cout << invalid;
                cin >> g_2;
            }//end if

        }//end do
        while (!(g_2 == 'r' || g_2 == 'o' || g_2 == 'y' || g_2 == 'g' || g_2 == 'b' || g_2 == 'v'));
        //populate user_guess array with user's guesses
        user_guesses[1] = g_2;

        //GUESS 3
        cout << peg_three;
        cin>> g_3;
        //check for proper user input
        do
        {
            if (!(g_3 == 'r' || g_3 == 'o' || g_3 == 'y' || g_3 == 'g' || g_3 == 'b' || g_3 == 'v'))
            {
                cout << invalid;
                cin >> g_3;
            }// end if

        }//end do
        while (!(g_3 == 'r' || g_3 == 'o' || g_3 == 'y' || g_3 == 'g' || g_3 == 'b' || g_3 == 'v'));
        //populate user_guess array with user's guesses
        user_guesses[2] = g_3;

        //GUESS 4
        cout << peg_four;
        cin >> g_4;
        //check for proper user input
        do
        {
            if (!(g_4 == 'r' || g_4 == 'o' || g_4 == 'y' || g_4 == 'g' || g_4 == 'b' || g_4 == 'v'))
            {
                cout << invalid;
                cin >> g_4;
            }//end if

        }//end do
        while (!(g_4 == 'r' || g_4 == 'o' || g_4 == 'y' || g_4 == 'g' || g_4 == 'b' || g_4 == 'v'));
        //populate user_guess array with user's guesses
        user_guesses[3] = g_4;

        //outside of while loop, solution is shared
        cout << secret_code << solution[0] << " " << solution[1] << " "
             << solution[2] << " " << solution[3] << endl;


        //GUESS CORRECT?
        //black pegs
        for (int i = 0; i < 4; i++)
        {

            if (user_guesses[i] == solution[i])
            {
                b_peg++;
            }//end if
        }//end for

        char solution_copy[4];
        //populate copy array
        for (int i = 0; i < 4; i++)
        {
            solution_copy[i] = solution[i];
        }

        //white pegs
        for (int i = 0; i < 4; i++)
        {
            //does not require the function exists defined in this file
            /*==============================C++11===============================
            //iterator looks through vector for user_guess
            bool exists = std::find(std::begin(solution), std::end(solution), user_guesses[i]) != std::end(solution);
            //if it exists, add one to w_peg
            if (exists)
            {
                w_peg++;
            }
            }//end for
            ========================================*/
            //if the  value exists in the user_guesses array, add one to w_peg
            //use a copy to not change orig. solution array
            if (exist(solution_copy, user_guesses[i]))
            {
                w_peg++;
                //prevent duplication by changing the value to a non-color char
                user_guesses[i] = '.';
            }//end if
        }//end for

        //result (if won)
        if (b_peg >= 4)
        {
            cout << congrats << endl;
            choice = 'N';
            //return statement
            return 0;
        }//end if

        //print results and ask user if they want to play again
        else
        {
            cout << result_a << b_peg << result_b << w_peg << result_c;
            cout << guess_again;
            cin >> choice;
            do
            {

                if (!(choice == 'Y' || choice == 'N'))
                {
                    cout << invalid;
                    cin >> choice;
                }//end if
            }//end do
            while (!(choice == 'Y' || choice == 'N'));
        }//end else
    }//end while

    //outside of while loop, solution is shared
    cout << secret_code << solution[0] << " " << solution[1] << " "
         << solution[2] << " " << solution[3] << endl;

    //return statement
    return 0;

}//end main
