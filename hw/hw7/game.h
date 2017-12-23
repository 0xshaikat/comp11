/*COMP11 FALL 217
 *Homework 6
 *Shaikat Islam
 *Signoff by Kelly Tattersall 11/14*/

#ifndef GAME_H_
#define GAME_H_
#include <string>
#include <vector>
class Game
{
 private:
  //dimensions of board
  int size;
  //current score for game
  int score;
  //is true when game is over
  bool endgame;
  
 public:
  //constructor prototype
  Game();
  //destructor prototype
  ~Game();
  //GETTERS AND SETTERS
  //get the current score
  int get_score();
  //set score
  void set_score(int score);
  //get dimensions
  int get_size();
  //set dimensions
  void set_size(int d);
  //GAME FUNCTIONS
  //ask user for move and validate user input
  void what_move();
  //adds next value to array
  void add_board(int **arr);
  //THE MOVERS
  //moves value to the left (x-1, y) position in 2d array
  void move_left(int **arr);
  //moves value to the right (x+1, y) position in 2d array
  void move_right(int **arr);
  //moves value up to (x, y+1) position in 2d array
  void move_up(int **arr);
  //moves value down to (x, y-1) position in 2d array
  void move_down(int **arr);
  //THE ADDERS
  //adds value to the left (x-1, y) position in 2d array
  void add_left(int **arr);
  //adds value to the right (x+1, y) position in 2d array
  void add_right(int **arr);
  //adds value up to (x, y+1) position in 2d array
  void add_up(int **arr);
  //moves value down to (x, y-1) position in 2d array
  void add_down(int **arr);
  //THE COMBINERS
  //moves and adds value to the left (x-1, y) position in 2d array
  void left(int **arr);
  //moves and adds value to the right (x+1, y) position in 2d array
  void right(int **arr);
  //moves and adds value up to (x, y+1) position in 2d array
  void up(int **arr);
  //moves and adds value down to (x, y-1) position in 2d array
  void down(int **arr);
  //based on value of bool end_game, the function ends the game
  bool end_game(int **arr);
  //if 2048 within array, game is won
  bool win_game(int **arr);
  //seed random num
  void seed_rand();
  //get random num
  int get_rand();
  };
#endif

