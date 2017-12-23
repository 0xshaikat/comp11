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
  int **board;

 public:
  //constructor prototype
  Board();
  //destructor prototype
  ~Board();
  
  //ACCESSORS AND MUTATORS
  int get_dimen();
  void set_dimen(int n);
  
  //prompt player for size of board
  void get_user_size();

  //set up iniital board
  void set_board();
  
  //display board
  void display_board();

  //seed random num
  void seed_rand();

  //get a random num
  int get_rand();

  //return reference to board
  int** get_board();

};
#endif
