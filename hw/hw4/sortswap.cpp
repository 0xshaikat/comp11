/********************
 * COMP11 Fall 2017
 * Homework 4
 * Problem 2
 * Shaikat Islam 
 *********************/

#include <iostream>
using namespace std;

//prototypes
void swap(int &a, int &b);
int valid();

//int swap(int &a, int &b)
//Purpose: Swap two numbers, a and b, if a is bigger than b.
//Parameters: (int &a, int &b)
//Returns: void
void swap(int &a, int &b)
{
  if (a  >  b)
    {
      int tmp = b;
      b = a;
      a = tmp;
    }//end if
}

//int valid()
//Purpose: validate integer inputs.
//Parameters: none
//Returns: int
int valid()
{
  int x;
  cin >> x;
  //user validation
  while(cin.fail())
    {
      cout << "I sure am sorry pal! That's not a valid order!\n";
      cin.clear();
      cin.ignore(256, '\n');
      cin >> x;
    }//end while
  return x;
}

//int main()
//Purpose: Sort four integers in ascending order.
//Parameters: Standard input
//Returns: 0, standard output
int main()
{
  //storing the integers
  int a,b,c,d;

  //user friendly customer service
  cout << "Welcome to the sort 'n swap, where we sort...And swap! TM (ALL RIGHTS RESERVED.)\n\n"
       << "Please enter your order, and by order, we mean four integers!\n\n";

  //validating input to ensure they are integers
  cout << "Enter the first integer!\n";
  a = valid();
  cout << "Integer #2!\n";
  b = valid();
  cout << "Integer #3!\n";
  c = valid();
  cout << "And the last one!\n";
  d = valid();

  //if anything is in descending order, SWAP!
  while( (a > b)  || (b > c) || (c > d))
    {
      swap(a,b);
      swap(b,c);
      swap(c,d);
    }//end while
  
  //some more friendly ui
  cout << "Why, thank you for coming to swap n' swap! We hope y'all come back soon!\n\n";
  cout << "Oh my, I almost forgot your order! Here they are, in sorted order!\n";

  //the product
  cout << a << " " << b << " " << c << " " << d << endl;

  //return statement
  return 0;
}//end main
