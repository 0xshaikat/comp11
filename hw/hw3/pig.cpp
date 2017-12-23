/* COMP11
 * Fall 2017
 * HW3 (PIG game)
 * Shaikat Islam */

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
const int THRESHOLD = 20;
// Players
const int P_ONE = 1;
const int P_TWO= 2;

//int main()
//Purpose; Emulate the game PIG.
//Parameters: Standard input.
//Returns: Standard output.
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
        int current;
        //So long as round_over is false, continue
        while (!round_over)
        {
            //ask user to input
            cout << "Player " << turn << ": Enter 0 to roll or 1 to hold\n";
            cin >> choice;
            do
            {
                if (choice == BANK)
                {
                    current = (rand()%6) + 1;
                    //lose the round
                    if (current == 1)
                    {
                        cout << "Player " << turn << " rolled a 1\n";
                        round_points = 0;
                        cout << "Round over, no points\n";
                        //ANNOUNCE POINTS
                        announce_points(pone_points, ptwo_points);
                        //check for pone win
                        if (check_for_win(pone_points, ptwo_points) == P_ONE)
                        {
                            cout << "Player " << turn << " won the game with "
                                 << pone_points << " points" << endl;
                            game_over = true;
                        }
                        //check for ptwo win
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
                    }//end if current = 1
                    //user chooses to hold
                    else
                    {
                        cout << "Player " << turn << " rolled "
                             << current  << "\n";
                        round_points += current;
                        cout << "Player " << turn
                             << ": Enter 0 to roll or 1 to hold\n";
                        cin >> choice;
                    }//end else for current = 1
                }//end if choice = bank
            }//end do
            while (choice == BANK);
            //print current total
            if (choice == HOLD)
            {
                if (turn == P_ONE)
                {
                    pone_points += round_points;
                }
                else
                {
                    ptwo_points += round_points;
                }
                cout << "Player " << turn << " scored " << round_points
                     << " this round\n" << endl;
                //ANNOUNCE POINTS
                announce_points(pone_points, ptwo_points);
                //CHECK FOR WIN
                if ( check_for_win(pone_points, ptwo_points) == P_ONE )
                {
                    cout << "Player " << turn << " won the game with " <<
                        pone_points << " points" << endl;
                    game_over = true;
                }
                else if ( check_for_win(pone_points, ptwo_points) == P_TWO )
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
    // Check the players' current points against the threshold
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
