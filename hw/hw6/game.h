/*COMP11 FALL 217
 *Homework 6
 *Shaikat Islam
 *Signoff by Kelly Tattersall 11/14*/

#ifndef GAME_H_
#define GAME_H_

class Game
{
 private:
  //current score for game
  int score;
  //next random value to be added to board
  int next_val;
  //is true when game is over
  bool end_game;
  
 public:
  //GETTERS AND SETTERS
  //get the current score
  int get_score();
  //set score
  void set_score(int score);
  //get next_val
  int get_next_val();
  //set next_val
  void set_next_val();

  //GAME FUNCTIONS
  //initialize 2D array to start game
  void set_board();
  //ask user for move and validate user input
  void what_move();
  //updates 2d array to represent the user's moves
  void update_board();
  //moves value to the left and adds to (x-1, y) position in 2d array
  void move_left();
  //moves value to the right and adds to (x+1, y) position in 2d array
  void move_right();
  //moves value up and adds to (x y+1) position in 2d array
  void move_up();
  //moves value down and adds to (x, y-1) position in 2d array
  void move_down();
  //based on value of bool end_game, the function ends the game
  void end_game(end_game);
  };
#endif
