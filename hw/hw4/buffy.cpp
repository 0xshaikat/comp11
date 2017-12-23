/********************
 * COMP11
 * Homework 4
 * Problem 3
 * Shaikat Islam
 *********************/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//prototypes
int valid();
//do not need to PbR for end_game
bool end_game(int stakes, int vamps, bool buffy_alive);
//for these you do
void encounter(int &attack, int &attacker);
void stake(int attacker, int &num_stakes, int &vamps, bool &buffy_alive);
void spell(int attacker, int &num_stakes, int &vamps, bool &buffy_alive);
void run(int &num_stakes, bool &buffy_alive);
void choice(int attack, int attacker, int &num_stakes,int &vamps, bool &buffy_alive);
void print_result(int &vamps, int &num_stakes, int &buffy_alive);

/*===========================FUNCTIONS===============================*/
/*==============================ARE==================================*/
/*==============================FUN==================================*/

//int valid()
//Purpose: validate integer inputs.
//Parameters: none
//Returns: int
int valid()
{
  int x;
  cin >> x;
  //user validation
  while(cin.fail() || ((x < 0)||(x > 2)))
    {
      cout << "We're trying to slay vamps here! No funny business!\n";
      cout << "Enter a totally valid user input, DUDE! (0, 1, or 2)\n";
      cin.clear();
      cin.ignore(256, '\n');
      cin >> x;
    }//end while
  return x;
}//end valid

//void encounter(&attack, &attacker)
//Purpose: store reference to user input
//Parameters: (&attack, &attacker)
//Returns: void
void encounter (int &attack, int &attacker)
{
  cout << "Enter 0 to attack with a stake, "
       << "1 to cast a spell, or 2 to run away.\n";
  attack = valid();
  cout << "Enter 0 for Buffy, 1 for Willow, or 2 for Xander.\n";
  attacker = valid();
}//end encounter

//bool end_game(int stakes, int vamps, bool buffy_alive)
//Purpose: return a bool based on if the simulation has ended
//Parameters: (int &stakes, int &vamps, bool &buffy_alive);
//Returns: bool
bool end_game(int num_stakes, int vamps, bool buffy_alive)
{
  if ((num_stakes == 0) || (vamps == 0) || (buffy_alive == false))
    {
      return false;
    }
  else if ( ! buffy_alive)
    {
      cout << "BUFFY IS DEAD\n";
      return true;
    }
  else
    {
    return true;
    }
}//end end_game

//void stake(int attacker, int &num_stakes, int &vamps, bool &buffy_alive)
//Purpose: Stake a vampire.
//Parameters: (int attacker, int &num_stakes, int &vamps, bool &buffy_alive);
//Returns: void
void stake(int attacker, int &num_stakes, int &vamps, bool &buffy_alive)
{
  //seed srand
  srand(time(NULL));
  
  //attacker is Buffy
  if (attacker == 0)
    {
      bool buffy = (rand() % 100) < 20;
      bool kill = (rand() % 100) < 80;
      if (buffy)
        {
          buffy_alive = false;
        }//end if
      if (kill)
        {
          vamps--;
          cout << "Vamp killed!\n";
        }//end if
      else
        {
          cout << "Vamp not killed!\n";
        }//end else
      //reduce the stakes (haha)
      num_stakes-=3;
      
    }//end if
  
  //attacker is Willow
  else if (attacker == 1)
    {
      bool buffy = (rand() % 100) < 20;
      bool kill = (rand() % 100) < 60;
      if (buffy)
        {
          buffy_alive = false;
        }//end if
      if (kill)
        {
          vamps--;
          cout << "Vamp killed!\n";
        }//end if
      else
        {
          cout << "Vamp not killed!\n";
        }//end else
    }//end else if
  
  //attacker is Xander
  else if (attacker == 2)
    {
      bool buffy = (rand() % 100) < 10;
      bool kill = (rand() % 100) < 30;
      if (buffy)
        {
          buffy_alive = false;
        }//end if
      if (kill)
        {
          vamps--;
          cout << "Vamp killed!\n";
        }//end if
      else
        {
          cout << "Vamp not killed!\n";
        }//end else
      //reduce the stakes (haha)
      num_stakes--;
    }//end else if
}//end stake

//void spell(int attacker, int &num_stakes, int &vamps, bool &buffy_alive)
//Purpose: Cast a spell.
//Parameters: (int attacker, int &num_stakes, int &vamps, bool &buffy_alive);
//Returns: void
void spell(int attacker, int &num_stakes, int &vamps, bool &buffy_alive)
{
  //seed srand()
  srand(time(NULL));
  
  //attacker is Buffy
  if (attacker == 0)
    {
      bool buffy = (rand() % 100) < 30;
      bool kill = (rand() % 100) < 20;
      if (buffy)
        {
          buffy_alive = false;
        }//end if
      if (kill)
        {
          vamps--;
          cout << "Vamp killed!\n";
        }//end if
      else
        {
          cout << "Vamp not killed!\n";
        }//end else
      //reduce the stakes (haha)
      num_stakes--;
    }//end if
  
  //attacker is Willow
  else if (attacker == 1)
    {
      bool buffy = (rand() % 100) < 40;
      bool kill = (rand() % 100) < 70;
      if (buffy)
        {
          buffy_alive = false;
        }//end if
      if (kill)
        {
          vamps--;
          cout << "Vamp killed!\n";
        }//end if
      else
        {
          cout << "Vamp not killed!\n";
        }//end else
      //reduce the stakes (haha)
      num_stakes--;
    }//end else if
  
  //attacker is Xander
  else if (attacker == 2)
    {
      bool buffy = (rand() % 100) < 20;
      bool kill = (rand() % 100) < 10;
      if (buffy)
        {
          buffy_alive = false;
        }//end if
      if (kill)
        {
          vamps--;
          cout << "Vamp killed!\n";
        }//end if
      else
        {
          cout << "Vamp not killed!\n";
        }//end else
      //reduce the stakes (haha)
      num_stakes--;
    }//end else if
}//end spell

//void run(int &stakes, bool &buffy_alive)
//Purpose: Run away.
//Parameters: (int &stakes, bool &buffy_alive);
//Returns: void
void run(int &num_stakes, bool &buffy_alive)
{
  bool buffy = (rand() % 100) < 10;  
  if (buffy)
    {
      buffy_alive = false;
    }//end if
  cout << "OK, everyone runs! Vamp is still out there!\n";
  
  //increase the stakes (haha)
  num_stakes++;
}//end run

//void choice(int attack, int attacker, int &num_stakes,int &vamps, bool &buffy_alive)
//Purpose: Makes the choice.
//Parameters: (int attack, int attacker, int &num_stakes,int &vamps, bool &buffy_alive)
//Returns: void
void choice(int attack, int attacker, int &num_stakes,int &vamps, bool &buffy_alive)
{
  //STAKE!
  if (attack == 0)
    {
      stake(attacker, num_stakes, vamps, buffy_alive);
    }//end if
  
  //SPELL!
  else if (attack == 1)
    {
      spell(attacker, num_stakes, vamps, buffy_alive);
    }//end else if
  
  //RUN!
  else
    {
      run(num_stakes, buffy_alive);
    }//end else
}//end choice

//void print_result(&vamps, &stakes, &buffy_alive)
//Purpose: Prints result of encounter.
//Parameters: (&vamps, &num_stakes, &buffy_alive)
//Returns: void
void print_result(int &vamps, int &num_stakes, bool &buffy_alive)
{
  cout << "\nThere are " << vamps << " vampires left.\n";
  cout << "There are " << num_stakes << " stakes left.\n";
  
  //is buffy alive
  if (buffy_alive)
    {
      cout << "And buffy is alive\n";
    }//end if
  else
    {
      cout << "BUT BUFFY IS DEAD\n";
    }//end else
}//end print_result

/*===========================M==================================*/
/*===========================A==================================*/
/*===========================I==================================*/
/*===========================N==================================*/

//int main()
//Purpose: Run a simulation of Buffy out on patrol with the Scooby gang,
//Willow, and Xander.
//Parameters: std input
//Returns: 0, std output
int main()
{
  //predefined game states
  int num_stakes = 10;
  int vamps = 3;
  bool buffy_alive = true;
  
  //store game states
  int attack;
  int attacker;

  //GAME!
  while(end_game(num_stakes, vamps, buffy_alive))
    {
      //pick an encounter
      encounter(attack, attacker);
      //make the choice
      choice(attack, attacker, num_stakes, vamps, buffy_alive);
      //print the result
      print_result(vamps, num_stakes, buffy_alive);
    }//end while for end_game


  //return statement
  return 0;
}//end main
