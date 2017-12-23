/*COMP11 FALL 2017
 *Homework 7
 *Shaikat Islam
 */

#include <iostream> //--Required for i/o
#include "board.h" //--Defines the board class
#include <stdlib.h> //--Used for rand()
#include <time.h> //--Seeds srand()
using namespace std;

//Attributes
int dimen;
int **board;

//constructor
Board::Board()
{
  board = NULL;
  get_user_size();
  board = new int *[dimen];
  
  for (int i = 0; i < dimen; i++)
    {
    board[i] = new int[dimen];
    }//end for
}//end constructor

//destructor
Board::~Board()
{
  for (int i = 0; i < dimen; ++i)
    {
      delete [] board[i];
    }//end for
  delete []board;
}//end destructor

//void Board::get_user_size()
//Purpose: Ask user for board size.
//Parameters: none
//Returns: void
void Board::get_user_size(){
  cout << "Please input a size for the"
       << "board that you would like to play on: ";
  
  //conditions for validation
  while(!(cin >> dimen) || (dimen < 2))
    {
      cin.clear();
      while (cin.get() != '\n') continue;
      cout << "This is an invalid value."
           <<"Please enter an integer input greater than 1.\n";
    }
}//end get_user_size

//void Board::get_dimen()
//Purpose: Get dimensions
//Parameters: none
//Returns: int
int Board::get_dimen()
{
  return dimen;
}//end get_dimen

//void Board::set_dimen(int n)
//Purpose: Set dimensions
//Parameters: int n
//Returns: void
void Board::set_dimen(int n)
{
  dimen = n;
}//end set_dimen

//void Board::display_board()
//Purpose: Displays the board for user enjoyment.
//Parameters: none
//Returns: void
void Board::display_board()
{
  for (int i = 0; i < dimen; ++i)
    {
      for (int j = 0; j < dimen; ++j)
        {
          cout << board[i][j] << ' ';
        }//end for
      cout << endl;
    }//end for
}//end display_board

//void Board::set_board()
//Purpose: Initializes board to 0 with random 2s.
//Parameters: none
//Returns: void
void Board::set_board(){
  for (int i = 0; i < dimen; i++)
    {
      for (int j = 0; j < dimen; j++)
        {
          board[i][j] = 0;
        }//end for
    }//end for

  //random 2's
  int a = get_rand();
  int b = get_rand();
  int c = get_rand();
  
  //while loops prevent duplicates
  while (c == a)
    {
      c = get_rand();
    }//end while
  int d = get_rand();
  while (d == b)
    {
      d = get_rand();
    }//end while
  board[a][b] = 2;
  board[c][d] = 2;
}//end set_board

//void Board::seed_rand()
//Purpose: Seed random number
//Parameters: none
//Returns: void
void Board::seed_rand()
{
  srand(time(NULL));
}//end seed_rand

//void Board::get_rand()
//Purpose: Generate random number.
//Parameters: none
//Returns: int
int Board::get_rand()
{
  return rand() % dimen;
}//end get_rand

//void Board::get_board()
//Purpose: Return the board
//Parameters: none
//Returns: int**
int** Board::get_board()
{
  return board;
}//end get_board




