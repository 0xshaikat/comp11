/*COMP11 FALL 2017
 *Homework 6
 *Shaikat Islam
 *Signoff by Kelly Tattersall 11/14*/

#ifndef BOARD_H_
#define BOARD_H_

class Board
{
 private:
  //size of board
  int dimen;
  //2D representation of board
  char **board;

 public:
  //constructor prototype
  Board();
  //destructor prototype
  ~Board();
  
  //ACCESSORS AND MUTATORS
  int get_dimen();
  void set_dimen(int dimen);
  
  //prompt player for size of board
  void get_user_size();
  //begin the game/set up the board in game.cpp
  void play_game();
};
#endif
