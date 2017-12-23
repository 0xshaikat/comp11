/*COMP11 FALL 2017
 *Homework 7
 *Shaikat Islam
 */

#include <iostream> //--Required for file I/O.
#include "game.h" //--Framework for game.cpp
#include <stdlib.h> //--Required for rand()
#include <time.h> //--Required for seeding random nums
using namespace std;

//Attributes
//dimensions of board
int size;
//current score for game
int score;

//constructor
Game::Game()
{
  score = 0;
  size = 0;
  endgame = false;
}//end constructor

//empty destructor
Game::~Game()
{
}//end destructor

//FUNCTIONS
//GETTERS AND SETTERS

//void Game::get_score()
//Purpose: Get score.
//Parameters: none
//Returns: int
int Game::get_score()
{
  return score;
}//end get_score

//void Game::set_score(int s)
//Purpose: Set the score.
//Parameters: int s
//Returns: void
void Game::set_score(int s)
{
  score = s;
}//end set_score

//void Game::get_size()
//Purpose: Get size of board.
//Parameters: none
//Returns: int
int Game::get_size()
{
  return size;
}//end get_dimen

//void Game::set_size(int d)
//Purpose: Set size.
//Parameters: int d
//Returns: void
void Game::set_size(int d)
{
  size = d;
}//end set_dimen

//void Game::add_board(int **arr)
//Purpose: Add next value to board.
//Parameters: none
//Returns: int **arr
void Game::add_board(int **arr)
{
  int p = rand() % 100;
  int a, b;
  //do while loop to set probability
  do
    {
      a = get_rand();
      b = get_rand();

      //90 percent chance
      if (p <= 90)
        {
          if (arr[a][b] == 0)
            {
              arr[a][b] = 2;
              break;
            }//end if
        }//end if
      //10 percent chance
      else 
        {
          if (arr[a][b] == 0)
            {
              arr[a][b] = 4;
              break;
            }//end if
        }//end else
    }//end do
  while (arr[a][b] != 0);
}//end add_board

//void Game::seed_rand()
//Purpose: Seed random num
//Parameters: none
//Returns: void
void Game::seed_rand()
{
  srand(time(NULL));
}//end seed_rand

//void Game::get_rand()
//Purpose: Generate random number.
//Parameters: none
//Returns: int
int Game::get_rand()
{
  return rand() % size;
}//end get_rand

//void Game::move_up(int **arr)
//Purpose: Shift values upward.
//Parameters: int **arr
//Returns: none
void Game::move_up(int **arr)
{
  for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
        {
          //if value is zero
          if (arr[j][i] == 0)
            {
              for (int k = j+1; k < size; k++)
                {
                  // if value is not zero
                  if (arr[k][i] != 0)
                    {
                      arr[j][i] = arr[k][i];
                      arr[k][i] = 0;
                      break;
                    }//end if
                }//end for
            }//end if
        }//end for
    }//end for
}//end move_up

//void Game::move_down(int **arr)
//Purpose: Shift values downward.
//Parameters: int **arr
//Returns: none
void Game::move_down(int **arr)
{
  for (int i = 0; i < size; i++)
    {
      for (int j = size - 1; j >= 0; j--)
        {
          if (arr[j][i] == 0)
            {
              for (int k = j-1; k>=0; k--)
                {
                  if (arr[k][i] != 0)
                    {
                      arr[j][i] = arr[k][i];
                      arr[k][i] = 0;
                      break;
                    }//end if
                }//end for
            }//end if
        }//end for
    }//end for
}//end move_down

//void Game::move_up(int **arr)
//Purpose: Shift values right.
//Parameters: int **arr
//Returns: none
//essentially move_down rotated 90 degrees
void Game::move_right(int **arr)
{
  for (int i = 0; i < size; i++)
    {
      for (int j = size - 1; j >= 0; j--)
        {
          if (arr[i][j] == 0)
            {
              for (int k = j-1; k>=0; k--)
                {
                  if (arr[i][k] != 0)
                    {
                      arr[i][j] = arr[i][k];
                      arr[i][k] = 0;
                      break;
                    }//end if
                }//end for
            }//end if
        }//end for
    }//end for
}//end move_right

//void Game::move_left(int **arr)
//Purpose: Shift values left.
//Parameters: int **arr
//Returns: none
//essentially move_up rotated 90 degrees
void Game::move_left(int **arr)
{
  for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
        {
          if (arr[i][j] == 0)
            {
              for (int k = j+1; k < size; k++)
                {
                  if (arr[i][k] != 0)
                    {
                      arr[i][j] = arr[i][k];
                      arr[i][k] = 0;
                      break;
                    }//end if
                }//end for
            }//end if
        }//end for
    }//end for
}//end move_left

//void Game::add_up(int **arr)
//Purpose: Add values upward.
//Parameters: int **arr
//Returns: none
void Game::add_up(int **arr)
{
  for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size - 1; j++)
        {
          if ((arr[j][i] != 0) && (arr[j][i] == arr[j+1][i]))
            {
              arr[j][i] = arr[j][i] + arr[j+1][i];
              arr[j+1][i] = 0;
              score+=arr[j][i];
            }//end if
        }//end for
    }//end for
}//end add_up

//void Game::add_down(int **arr)
//Purpose: Shift values downward.
//Parameters: int **arr
//Returns: none
void Game::add_down(int **arr)
{
  for (int i = 0; i < size; i++)
    {
      for (int j = size - 1; j > 0; j--)
        {
          if ((arr[j][i] != 0) && (arr[j][i] == arr[j-1][i]))
            {
              arr[j][i] = arr[j][i] + arr[j-1][i];
              arr[j-1][i] = 0;
              score+=arr[j][i];
            }//end if
        }//end for
    }//end for
}//end add_down

//void Game::add_right(int **arr)
//Purpose: Add values right.
//Parameters: int **arr
//Returns: none
void Game::add_right(int **arr)
{
  for (int i = 0; i < size; i++)
    {
      for (int j = size - 1; j > 0; j--)
        {
          if ((arr[i][j] != 0) && (arr[i][j] == arr[i][j-1]))
            {
              arr[i][j] = arr[i][j] + arr[i][j-1];
              arr[i][j-1] = 0;
              score+=arr[i][j];
            }//end if
        }//end for
    }//end for
}//end add_right

//void Game::add_left(int **arr)
//Purpose: Add values left.
//Parameters: int **arr
//Returns: none
void Game::add_left(int **arr)
{
  for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size - 1; j++)
        {
          if ((arr[i][j] != 0) && (arr[i][j] == arr[i][j+1]))
            {
              arr[i][j] = arr[i][j] + arr[i][j+1];
              arr[i][j+1] = 0;
              score+=arr[i][j];
            }//end if
        }//end for
    }//end for
}//end add_left

//void Game::up(int **arr)
//Purpose: Shift and values upward.
//Parameters: int **arr
//Returns: none
void Game::up(int **arr)
{
  move_up(arr);
  add_up(arr);
  move_up(arr);
}//end up

//void Game::down(int **arr)
//Purpose: Shift and add values downward.
//Parameters: int **arr
//Returns: none
void Game::down(int **arr)
{
  move_down(arr);
  add_down(arr);
  move_down(arr);
}//end down

//void Game::right(int **arr)
//Purpose: Shift and add values right.
//Parameters: int **arr
//Returns: none
void Game::right(int **arr)
{
  move_right(arr);
  add_right(arr);
  move_right(arr);
}//end right

//void Game::left(int **arr)
//Purpose: Shift values left.
//Parameters: int **arr
//Returns: none
void Game::left(int **arr)
{
  move_left(arr);
  add_left(arr);
  move_left(arr);
}//end left

//void Game::end_game(int **arr)
//Purpose: End the game 2048.
//Parameters: int **arr
//Returns: none
bool Game::end_game(int **arr)
{
  //if these conditions are not met, the user has not lost yet
  for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
        {
          //cells with zeroes
          if (arr[i][j] == 0)
            {
              return false;
            }//end if
          //left adjacency
          if ( (j != 0) && arr[i][j] == arr[i][j-1])
            {
              return false;
            }//end if
          //right adjacency
          if ( (j != size-1) && arr[i][j] == arr[i][j+1])
            {
              return false;
            }//end if
          //up adjacent
          if ( (i != 0) && arr[i][j] == arr[i-1][j])
            {
              return false;
            }//end if
          //down adjacent
          if ( (i != size - 1) && arr[i][j] == arr[i+1][j])
            {
              return false;
            }//end if
        }//end for
    }//end for
  return true;
}//end end_game

//void Game::win_game(int **arr)
//Purpose: Wins the game 2048 if conditions are met.
//Parameters: int **arr
//Returns: none
bool Game::win_game(int** arr)
{
  for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
        {
          //if array contains 2048, winner!
          if (arr[i][j] == 2048)
            {
              return true;
            }//end if
        }//end for
    }//end for
  return false;
}//end if



