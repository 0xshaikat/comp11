/********************
 * COMP11
 * Homework 5
 * Problem 1
 * Shaikat Islam
 *********************/
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include "print.h"
using namespace std;

/*=================FUNCTION PROTOYPES=================*/
//file io
string get_string();
//array stuff
void populate(string* words);
void print_array(char *xstr, string word);
void blankify(char *xstr, string word);
void modify_array(char *cstr, char *xstr, char g, string word);
//game functions
bool a_win(char *cstr, char *xstr, string word);
bool check_letter(string word, string g);
bool end_game(int n_guess);
//random num gen
void my_init();
int get_random();

//void my_init()
//Purpose: Seed a random value using srand().
//Parameters: none
//Returns: void
void my_init()
{
  srand(time(NULL));
}//end my_init

//int get_random()
//Purpose: Return a random value from range 0 to 19912.
//Parameters: none
//Returns: int num
int get_random()
{ 
  int rand_num = rand() % 19912;
  return rand_num;
}//end get_random

//string get_string()
//Purpose: Gets a 'random' string from a file of 19912 words.
//Parameters: none
//Returns: string
string get_string()
{
  //file IO
  ifstream infile;
  infile.open("dictionary.txt");

  //error check
  if (!infile.is_open())
    {
      cerr << "Error with file!\n";
      exit(EXIT_FAILURE);
    }
  
  //get random string
  int line_no = get_random();
  int line_count = 0;
  string line;
  
  //parse through file, once line_no matches line_count, return that string
  while (getline(infile, line)) {
    ++line_count;
    //once the two vals match, return line
    if (line_count == line_no) {
      return line;
    }//end if
  }//end while

  //close file
  infile.close();
}//end get_string

//void blankify(char *xstr, string word)
//Purpose: Fill a char array of size word.length() - 1 with blanks.
//Parameters: (char *xstr, string word)
//Returns: void
void blankify(char *xstr, string word)
{
  for (int i = 0; i < word.length(); i++)
    {
      xstr[i] = '_';
    }//end for
}//end blankify

//void print_array(char *xstr, string word)
//Purpose: Print a char array.
//Parameters: (char *xstr, string word)
//Returns: void
void print_array(char *xstr, string word)
{
  for (int i = 0; i < word.length(); i++)
    {
      cout << xstr[i] << " ";
    }//end for
}//end print_array

//void modify_array(char *cstr, char *xstr, char g, string word)
//Purpose: Check for a character in cstr, and if it matches, add that character
//to xstr.
//Parameters: void modify_array(char *cstr, char *xstr, char g, string word)
//Returns: void
void modify_array(char *cstr, char *xstr, char g, string word)
{
  //use word.length() to traverse both arrays
  for (int i = 0; i < word.length(); i++)
    {
      //so long as the char g is in cstr, and xstr[i] is a blank
      if ((g == cstr[i]) && (xstr[i] == '_'))
        {
          //change the element         
          xstr[i] = g;
        }//end if
    }//end for
}//end modify_array

//bool end_game(int n_guess)
//Purpose: Return a bool based on the conditions for
//an end game in hangman.
//Parameters: (int n_guess)
//Returns: bool
bool end_game(int n_guess)
{
  if (n_guess >= 9)
    {
      return true;
    }
  return false;
}//end end_game

//void populate(string* words)
//Purpose: Populate an array defined in main with words from get_string().
//Parameters: (string* words)
//Returns: void
void populate(string* words)
{
      for (int i = 0; i < 5; i++)
        {
          words[i] = get_string();
        }//end for
}//end repopulate

//bool a_win(char *cstr, char *xstr, string word)
//Purpose: Check for a winning game within hangman.
//Parameters: (char *cstr, char *xstr, string word)
//Returns: bool
bool a_win(char *cstr, char *xstr, string word)
{
  int counter = 0;
  //once counter matches the word.length(), the two arrays are
  //essentially the same and there is a win
  for (int i = 0; i < word.length(); i++)
    {
      if (cstr[i] == xstr[i])
        {
          counter++;
        }//end if
    }//end for
  if (counter == word.length())
    {
      return true;
    }//end if
  return false;
}//end a_win

//bool check_letter(string word, char g)
//Purpose: Check for a letter in a string.
//Parameters: (string word, char g)
//Returns: bool
bool check_letter(string word, char g)
{
  int correct = 0;
  for (int i = 0; i < word.length(); i++)
    {
      if (g == word[i])
        {
          correct++;
        }   
    }//end for
  if (correct > 0)
    {
      return true;
    }//end if
  return false;
}//end check_letter

//int main()
//Purpose: Hang an innocent man based on a user's attempts to guess letters
//in random English words.
//Parameters: none, standard input
//Returns: 0, standard output
int main()
{
  //REFERENCES
  int p_guess = 0;
  int n_guess = 0;
  //which game is it (to repopulate array)
  int game_no = 1;
  //dictionary array (populate with function repop)
  string words[5];

  //USER INPUT
  char choice = 'y';
  char guess;
  
  //STRINGS make the game work and look pretty
 
  string word;
  string intro = "\nA long time ago, in a galaxy, far, far, away...\n";
  string intro_a = "\nWelcome to the game Hangman. It's the 19th century,";
  string intro_b = " and the city ";
  string intro_c = "of Bestine on Tatooine has to punish a reckless maraude";
  string intro_d = "r. The Empire reigns here.\n";
  string intro_e = "On this city, justice is barbaric and innocent people are";
  string intro_f = " sentenced to death ";
  string intro_g = "on the basis of guessing random letters of a word in the ";
  string intro_h = "english dictionary.\n";
  string intro_i = "It is your job to save or decimate this marauder. The pow";
  string intro_j = "er is in your hands.\n";
  string enter_letter = "\n\nEnter a letter, judge:\n";
  
  /*======================GAME========================*/
  cout << intro
       << intro_a << intro_b << intro_c << intro_d << intro_e
       << intro_f << intro_g << intro_h << intro_i << intro_j;
  do{    
    
    //populate that array!
    if ((game_no % 5 == 0) || (game_no == 1))
      {
        populate(words);
      }//end if

    //check for win within a round
    bool ya_win = false;
    
    //current word
    word = words[game_no % 5];
    
    //copy string to char array, and make a blank array
    //of that size
    char *cstr = new char[word.length() + 1];
    char *xstr = new char[word.length() + 1];
    strcpy(cstr, word.c_str());
    
    //add blanks to xstr
    blankify(xstr, word);
    
    cout << "Marauder no: " << game_no << endl;
    
    //let the user guess!
    while ((! end_game(n_guess)) && (!ya_win) )
      {
        //print the innocent civilian
        print_body_parts(n_guess);

        cout << "\nYou've made " << n_guess << " incorrect guesses"
             << ". Save the marauder!\n";
        
        //print the array of blanks
        print_array(xstr, word);
        cout << enter_letter  << endl;
        
        //validate guess
        do
          {
            cin >> guess;
            if (!isalpha(guess))
              {
                cin.clear();
                cout << "Please enter a valid alphabetical character."
                     << "Don't mess with this man's life!" << endl;
                cin >> guess;
              }
          }
        while (!isalpha(guess));
        
        //change user input to lowercase
        guess = tolower(guess, locale());

        
        //check for guess in the world
        if (check_letter(word, guess))
          {
            modify_array(cstr, xstr, guess, word);
            print_array(xstr, word);
            p_guess++;
          }//end if
        else
          {
            print_array(xstr, word);
            n_guess++;
          }//end else
        
        //if there's a win, end round
        if (a_win(cstr, xstr, word))
          {
            cout << "\n\nYou have won. So did the marauder."
                 << " And Bestine. And the rebellion." << endl;
            ya_win = true;
          }//end if
        else
          {
            cout << "\n\nThe word was " << word << ".\n";
            cout << "\n\nYou've lost. As did the marauder. The Empire is still"
                 << " strong.\n";
          }//end else
      }//end while

    //would the user like to play again
    cout << "\nWould you like to save more lives? (y/n)\n";
    cin >> choice;
    
    if (choice == 'y')
      {
        game_no++;
        n_guess = 0;
        p_guess = 0;
      }//end if
  }
  while(choice == 'y' );

  //return statement
  return 0;
}//end main
