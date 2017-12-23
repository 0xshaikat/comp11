//COMP11 FALL 2017
//Shaikat Islam
//Homework 7

#include <iostream> //--Required for i/o
#include <vector> //--Used to hold high scores and usernames
#include <string> //--Used to hold usernames
#include <fstream> //--File I/O
#include <sstream> //--Convert integers to strings
#include "board.h" //--Functions inherited from class Board
#include "game.h" //--Functions inheritied from class Game
#include <cctype>
using namespace std;


//FUNCTION PROTOTYPES FOR FILE I/O

//bool does_it_exist()
//Purpose: Returns true if high score file exists
//Parameters: None
//Return type: bool
bool does_it_exist();

//void initialize_hs()
//Purpose: initialize high score file
//Parameters: none
//Return type: void
void initialize_hs();

//int get_lines();
//Purpose: Returns number of lines in file
//Parameters: none
//Return type: int
int get_lines();

//string max_score(vector<string> name, vector<int> score);
//Purpose: returns string interpretation of max score
//Paremeters: vector<string> name, vector<int> score
//Returns: string
string max_score(vector<string> name, vector<int> score);

//void pop_scores(vector<string>& name, vector<int>& score);
//Purpose: populate vectors with scores from highscore file
//Parameters: vector<string>& name, vector<int>& score, int numlines
//Returns: void
void pop_scores(vector<string>& name, vector<int>& score);

//void insertion (vector<int>& score, vector<string>& name, int n);
//Purpose: Implement insertion sort on two vectors, simultaneously.
//Parameters: vector<int>& score, vector<string>& name, int n
//Returns: void
void insertion (vector<int>& score, vector<string>& name, int n);

//void write_hs(vector<string> name, vector<int> score, int numlines);
//Purpose: write scores to file
//Parameters: vector<string> name, vector<int> score, int numlines
//Returns: void
void write_hs(vector<string> name, vector<int> score, int numlines);

//bool does_it_exist()
//Purpose: Returns true if high score file exists
//Parameters: None
//Return type: bool
bool does_it_exist()
{
  ifstream infile;
  infile.open("highscore.txt");
  return infile.good();
}//end does_it_exist()

//void initialize_hs()
//Purpose: initialize high score file
//Parameters: none
//Return type: void
void initialize_hs()
{
  ofstream output ("highscore.txt");
  output << "Shaikat";
  output << "\n";
  output << 12344;
  output << "\n";
  output << "Thor";
  output << "\n";
  output << 1234;
  output << "\n";
  output.close();
}//end initialize_hs

//int get_lines();
//Purpose: Returns number of lines in file
//Parameters: none
//Return type: int
int get_lines()
{
  int num_lines = 0;
  string line;
  ifstream hsfile("highscore.txt");
  //parse file
  while (getline(hsfile, line))
    {
      ++num_lines;
    }//end while
  return num_lines;
}//end get_lines

//string max_score(vector<string> name, vector<int> score);
//Purpose: returns string interpretation of max score
//Paremeters: vector<string> name, vector<int> score
//Returns: string
string max_score(vector<string> name, vector<int> score)
{
  int bf_int = score.back();
  stringstream ss;
  ss << bf_int;
  //convert int to string
  string hi_score = ss.str();
  string s = name.back() + ": " + hi_score + "\n";
  return s;
}//end max_score

//void pop_scores(vector<string>& name, vector<int>& score, int numlines);
//Purpose: populate vectors with scores from highscore file
//Parameters: vector<string>& name, vector<int>& score, int numlines
//Returns: void
void pop_scores(vector<string>& name, vector<int>& score)
{
  string line;
  vector<string> vfile;
  ifstream infile("highscore.txt");
  
  //parse file and add to vector
  while (getline(infile, line))
    {
      vfile.push_back(line);
    }//end while
  int vsize = vfile.size();
  
  //add to two other vectors to be used for file io
  for (int i = 0; i < vsize; i++)
    {
      if(i%2 == 0)
        {
          name.push_back(vfile[i]);
        }
      else
        {
          int x = 0;
          istringstream (vfile[i]) >> x;
          score.push_back(x);
        }//end else
    }//end for
}//end pop_scores

//void insertion (vector<int>& score, vector<string>& name, int n);
//Purpose: Implement insertion sort on two vectors, simultaneously.
//Parameters: vector<int>& score, vector<string>& name, int n
//Returns: void
void insertion (vector<int>& score, vector<string>& name, int n)
{
  int i, k, j;
  //sort
  for (i = 1; i<n; i++)
    {
      j = i - 1;
      //insert
      while ( j>=0 && score[j] > k)
        {
          score[j+1] = score[j];
          name[j+1] = name[j];
          j--;
        }//end while
      score[j+1] = k;
    }//end for
}//end insertion

//void write_hs(vector<string> name, vector<int> score, int numlines);
//Purpose: write scores to file
//Parameters: vector<string> name, vector<int> score, int numlines
//Returns: void
void write_hs(vector<string> name, vector<int> score, int numlines)
{
  ofstream myfile;
  myfile.open("highscore.txt");
  
  //write to file
  for (int i = 0; i < numlines; i++)
    {
      myfile << name[i];
      myfile << "\n";
      myfile << score[i];
      myfile << "\n";
    }//end for
  myfile.close();
}//end write_hs

//int main()
//Purpose: Implement the game 2048.
//Parameters: none
//Returns : 0
int main()
{
  //preliminary attributes
  bool endgame = false;
  char choice;
  string user;
  
  //instantiation
  Board b;
  Game g;
  b.seed_rand();
  b.set_board();
  g.set_size(b.get_dimen());
  
  //HIGH SCORE AND FILE IO
  //initialize high score file
  if (!does_it_exist())
    {
      initialize_hs();
    }//end if
  
  //initialize vectors
  vector<string> name;
  vector<int> score;
  
  int no_lines = get_lines();
  
  //populate vectors
  if (no_lines > 1)
    {
      pop_scores(name, score);
    }
  
  //show high score if applicable
  if (no_lines == 0)
    {
      cout << "You're the first to play! Go get 'em!\n";
      cout << endl;
    }//end if
  else
    {
      cout << endl;
      cout << "This is the current high score:\n";
      string s = max_score(name, score);
      cout << s;
      cout << endl;
    }
  
  cout << "Here is the initial board! Good luck!\n";
  b.display_board();
  
  //GAME PLAY
  while (!endgame)
    {
      cout << "Next turn. Please enter w,a,s,d,q, or h: ";
      cin >> choice;
      choice = toupper(choice);
      
      //VALIDATE INPUT
      while (choice != 'W' && choice != 'A' && choice != 'S' &&
             choice != 'D' && choice != 'H' && choice != 'Q')
        {
          cout << "Error. Invalid input.\nPlease enter w, a, s, d, q, or h: ";
          cin >> choice;
          choice = toupper(choice);
        }//end while
      if (choice == 'W')
        {
          g.up(b.get_board());
        }//end elif
      else if (choice == 'A')
        {
          g.left(b.get_board());
        }//end elif
      else if (choice == 'S')
        {
          g.down(b.get_board());
        }//end elif
      else if (choice == 'D')
        {
          g.right(b.get_board());
        }//end elif
      else if (choice == 'H')
        {
          cout << endl;
          cout << "The top high scores are:\n";
          int nsize = name.size();
          for (int i = 0; i < nsize; i++)
            {
              if ( i < 5)
                {
                  cout << endl;
                  cout << name[i] << ": " << score[i] << endl;
                }//end if
            }//end for
          cout << endl;
        }//end elif
      else if (choice == 'Q')
        {
          endgame = true;
          break;
        }//end elif
      //add to board, display it, and display score
      g.add_board(b.get_board());
      b.display_board();
      cout << endl << "Current Score: "
           << g.get_score() << endl;
      
      //Lose
      if (g.end_game(b.get_board()))
        {
          cout << "You've lost. What a shame.\n";
          endgame = true;
          break;
        }//end if
      
      //Win
      if (g.win_game(b.get_board()))
        {
          cout << "You've won. What a dude!\n";
          endgame = true;
          break;
        }//end if
    }//end while
  
  //ask user what their name is
  cout << "Tell me your name so history shall remember your valiant effort."
       << endl;
  cin >> user;

  //add scores to vectors
  name.push_back(user);
  score.push_back(g.get_score());

  //add 2 to number of lines
  no_lines += 2;
  int v_size = name.size();
  
  //sort new scores
  insertion(score, name, v_size);
  //write them to the file
  write_hs(name, score, name.size());

  //end of game high score
  cout << "The top high scores are:\n";
  int nsize = name.size();
  for (int i = 0; i < nsize; i++)
    {
      if ( i < 5)
        {
          cout << endl;
          cout << name[i] << ": " << score[i] << endl;
        }//end if
    }//end for
  
  //return statement
  return 0;
}//end main
