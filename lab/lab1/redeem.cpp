// Nora Li and Shaikat Islam
// COMP 11
// Lab 1
// September 12, 2017

#include <iostream>
#include <string>

// The line below allows us to use cout and cin for input and output
// instead of std::cout and std::cin
using namespace std;

// int main()
// Purpose: emulate the winning of tickets and prize allocation at an arcade.
// Parameters: none
// Returns: 0
int main()
{
  const int MINION = 3;
  //const int SPIDER = 1;

  //extra credit 1
  const double PRICE = 1.75;

  //part 3 addition
  string name = "";
  int tickets_won;

  //code snippet to ensure two decimal places for outputted price
  //(for extra credit 2 )
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(2);

  cout << "Welcome to The Arcade!" << endl;

  //part 1
  cout << "What's your name, ticket-winner?" << endl;

  //extra credit 2
  //use GETLINE to read entire line of input from user w/ whitespace
  getline(cin, name);

  cout << "How many tickets did you win, "
       << name << "?" << endl;
  cin >> tickets_won;
  cout << "Woah, " << name << "! You have won "
  //part 2 addition
       << ((tickets_won / MINION) + (tickets_won % MINION))
       << " prizes:"  << endl;
  cout << tickets_won / MINION << " Minions" << endl;
  cout << tickets_won % MINION << " spider rings" << endl;

  //extra credit 1
  cout << "LMAO u w4st3d $" << (tickets_won * PRICE)
       << " on this dumb game" << endl;

  return 0;
}
