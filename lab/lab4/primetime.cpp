//Shaikat Islam and Nora Li
//10-10-17
//Lab 4 (FUNctions)
//CS11

#include <iostream>
using namespace std;

//prototypes
int prime_factor(int x);
bool not_prime(int x);

//int prime_factor(int x)
//Purpose: Return the first prime factor of an integer.
//Parameters: int x
//Returns: int 
int prime_factor(int x){
  //check for prime factors
  for(int i = 2; i < x; i++)
  {
    //if the number is not prime:
    if(x % i == 0)
      {
	cout << i << " ";
	return i;
      }//end if
  }//end for
  cout << x << endl;
  return x;
}//end prime_factor

//bool not_prime(int x)
//Purpose: Check if a number is prime.
//Parameters: int x
//Returns: bool
bool not_prime(int x){
  //check for prime factors
  for(int i = 2; i < x; i++)
  {
    //if the number is not prime:
    if(x % i == 0)
      {
	return true;
      }//end if
  }//end for
  return false;
}//end not_prime

//int main()
//Purpose: Return the prime factorization of a number.
//Parameters: standard input
//Returns: 0, standard output
int main()
{
  char choice = 'Y';
  int input;
  //Explain what the prime factorization of a number is
  cout << "Hello friends. Welcome to the the Prime Time Club," 
       << " where you're always at your prime.\nThe prime factorization"
       << " of a number the set of numbers, that when multiplied together,"
       << " equal that number.\n" << endl;

  //validate input
  do
    {
      cout << "Please enter the number you would like to factorize: ";
      cin >> input;

      //do while loop to check if input is still prime
      while(not_prime(input))
	{
	  //print out the prime factors
	  input /= prime_factor(input);

	}//end while
      
      //cout input because the last number is not prime
      cout << input << endl;


      cout << "Would you like to keep factorizing (Y/N)?\n";
      cin >> choice;
    }
  while(choice == 'Y' || choice == 'y');

  //return statement
  return 0;
}//end main
