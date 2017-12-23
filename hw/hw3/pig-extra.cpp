/* COMP11
 * Fall 2017
 * HW3 -- PIG EXTRA (BIG PIG)
 * Shaikat Islam */

// I implemented BIG PIG from the Wikipedia page and modified the code by adding
//another dice variable. This also required changing other code, as well as
//increasing the threshold to 100. Furthermore, there are three other test cases
//that also were implemented, including checking for a dice roll of one and a
//non-one number, a double dice roll of 1, as well as a double dice roll. When
//there is a double dice roll, the player is required to roll again, so I got
//around this by changing the choice variable to a 0, outright.

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

// Function prototype: check_for_win
int check_for_win(int, int);
// Function prototype: switch_turn
int switch_turn(int);
// Function prototype: announce_points
void announce_points(int, int);

// Number of points needed to win
const int THRESHOLD = 100;
// Players
const int P_ONE = 1;
const int P_TWO = 2;

//int main()
//Purpose: Implement the BIG PIG game.
//Parameters: Standard input.
//Output: 0, standard output.
int main ()
{
    // Seed the random variable
    srand(time(NULL));

    // Total number of points for each player.
    int pone_points = 0, ptwo_points = 0;

    //bank or hold
    const int BANK = 0;
    const int HOLD = 1;

    // Whose turn it is. Player One always starts.
    int turn = P_ONE;

    // Is the game over yet
    bool game_over = false;

    // While loop for the game. A game comprises several rounds.
    while (!game_over)
    {
        // Announce whose turn it is
        cout << "Player " << turn << " is up!\n";

        // Round-specific variables
        bool round_over = false;
        int round_points = 0;

        //bank or roll
        int choice;
        //two dice
        int dice_one;
        int dice_two;
        //round runs so long as the round_over variable is false
        while (!round_over)
        {
            //ask user to choose a variables
            cout << "Player " << turn << ": Enter 0 to roll or 1 to hold\n";
            cin >> choice;
            //so long as the choice variable is equal to BANK
            do
            {
                //if choice is BANK, roll
                if (choice == BANK)
                {
                    dice_one = (rand()%6) + 1;
                    dice_two = (rand()%6) + 1;
                    //lose the round
                    if (((dice_one == 1) && (dice_two != 1))
                        || ((dice_one != 1) && (dice_two == 1)))
                    {
                        cout << "Player " << turn << " rolled a " << dice_one
                             << " and " << dice_two << ".\n";
                        round_points = 0;
                        cout << "Round over, no points\n";
                        //ANNOUNCE POINTS
                        announce_points(pone_points, ptwo_points);

                        //CHECK FOR P1 win
                        if (check_for_win(pone_points, ptwo_points) == P_ONE)
                        {
                            cout << "Player " << turn << " won the game with "
                                 << pone_points << " points" << endl;
                            game_over = true;
                        }
                        //CHECK FOR P2 win
                        else if (check_for_win(pone_points, ptwo_points)
                                 == P_TWO)
                        {
                            cout << "Player " << turn << " won the game with "
                                 << ptwo_points << " points" << endl;
                            game_over = true;
                        }
                        //switch turn
                        turn = switch_turn(turn);
                        //round over
                        round_over = true;
                    }//end if dice_one = 1

                    //two 1s
                    //add 25 points to players score
                    else if ((dice_one == 1) && (dice_two == 1))
                    {
                        //announce points
                        cout << "Player " << turn << "rolled " << dice_one
                             << " and " << dice_two << "." << endl;
                        //add 25 points to the players score
                        round_points += 25;
                        cout << "Player " << turn
                             << ": Enter 0 to roll or 1 to hold\n";
                        cin >> choice;
                    }

                    //two doubles
                    else if (dice_one == dice_two)
                    {
                        //announce points
                        cout << "Player " << turn << "rolled " << dice_one
                             << " and " << dice_two << "." << endl;
                        //add twice the score of the points to the players score
                        round_points += (4 * dice_one);
                        cout << "Player " << turn
                             << ": Enter 0 to roll or 1 to hold\n";
                        //PLAYER IS OBLIGATED TO ROLL
                        cout << "Since you rolled a double, "
                             << "you must roll again.\n";
                        choice = 0;
                    }
                    //regular roll
                    else
                    {
                        cout << "Player " << turn << " rolled " << dice_one
                             << " and " << dice_two << ".\n";
                        round_points += (dice_one + dice_two);
                        cout << "Player " << turn
                             << ": Enter 0 to roll or 1 to hold\n";
                        cin >> choice;
                    }//end else for dice_one = 1
                }//end if choice = bank
            }//end do
            while (choice == BANK);

            //if user decides to HOLD
            if (choice == HOLD)
            {
                //add points
                if (turn == P_ONE)
                {
                    pone_points += round_points;
                }//end if

                else
                {
                    ptwo_points += round_points;
                }//end else

                cout << "Player " << turn << " scored " << round_points
                     << " this round\n" << endl;

                //ANNOUNCE POINTS
                announce_points(pone_points, ptwo_points);

                //CHECK FOR WIN
                if (check_for_win(pone_points, ptwo_points) == P_ONE)
                {
                    cout << "Player " << turn << " won the game with " <<
                        pone_points << " points" << endl;
                    game_over = true;
                }
                else if (check_for_win(pone_points, ptwo_points) == P_TWO)
                {
                    cout << "Player " << turn << " won the game with " <<
                        pone_points << " points" << endl;
                    game_over = true;
                }

                //SWITCH TURN
                turn = switch_turn(turn);
                //round over
                round_over = true;

            }//end else
        }//end while round over
    } // end game while loop

    // Game is over. End the program.
    cout << "Thanks for playing!\n";
    return 0;
}//end main

/****************************************
 * NO NEED TO MODIFY CODE BELOW THIS POINT    *
 ****************************************/

// FUNCTION DEFINITION
// Function check_for_win
// Arguments:
//  Player 1 and 2's points (ints)
// Returns:
//  0 is game is not over
//  1 if player one won
//  2 if player two won
// Does:
//  Compares each score to the threshold
int check_for_win(int pone_points, int ptwo_points)
{
    // Check the players' dice_one points against the threshold
    if (pone_points >= THRESHOLD)
    {
        return P_ONE;
    }
    else if (ptwo_points >= THRESHOLD)
    {
        return P_TWO;
    }

    // If we didn't meet either condition,
    // then nobody won
    return 0;
}

// FUNCTION DEFINITION
// Function switch_turn
// Arguments:
//  1. whose turn it is (int)
// Returns:
//  # of updated turn
// Does:
//  Switches whose turn it is
int switch_turn(int turn)
{
    if (turn == P_ONE)
    {
        return P_TWO;
    }
    else {
        return P_ONE;
    }

}

// FUNCTION DEFINITION
// Function announce_points
/// Arguments:
//      1. Player one's points (int)
//      2. Player two's points (int)
// Returns:
//      void
// Does:
//      Announces both players total points
void announce_points(int pone, int ptwo)
{
    cout << "Player One total points: " << pone << endl;
    cout << "Player Two total points: " << ptwo << endl;
}
