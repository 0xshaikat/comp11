/********************
 * COMP11
 * Homework 4
 * Problem 1
 * Shaikat Islam
 *********************/
#include <iostream>
#include <tgmath.h>

using namespace std;

//prototype
string feet_and_inches(int feet, int inches);

//void feet_and_inches(double feet, double inches)
//Purpose: Convert feet and inches to meters and centimeters.
//Parameters: (double feet, double inches)
//Returns: "", standard output
string feet_and_inches(double feet, double inches)
{
  //constants
  const double METERS_IN_FOOT = .3048;
  const double CENTI_IN_METER = 100;
  
  //const double inches_in_foot = 12;
  const double CENTI_IN_INCHES = 2.54;
  float centi;
  float meters;

  //convert from feet and inches into meters and feet
  double total_cem;
  
  //all centimeters
  total_cem = (feet * METERS_IN_FOOT * CENTI_IN_METER) + (inches * CENTI_IN_INCHES);

  //convert centimeters to meters - the remainder
  //convert remainder to centimeters
  meters = (total_cem / CENTI_IN_METER) - (fmod(total_cem, CENTI_IN_METER)/CENTI_IN_METER);
  centi = fmod(total_cem,  CENTI_IN_METER);
  cout << "There are " << meters << " meters and " << round(centi) << " centimeters in "
       << feet << " feet and " << inches << " inches." << endl;
  
  //return statement
  return "";
}//end feet_and_inches

//int main()
//Purpose: Return standard output of feet_and_inches(double feet, double inches)
//Parameters: none
//Returns: 0, standard output
int main()
{
  //char for user to continue
  char choice = 'Y';
  //variables for user input
  double feet, inches;
  //vars for output
  float meters;
  float centi;
  
  //ask user
  cout << "Hello user! Please input a length in feet an inches:\n";

  //do while to continue program
  do {  
  //feet
  cout << "Feet: ";
  cin >> feet;
  
  //user validation
  while((cin.fail()) || (feet < 0))
    {
      cout << "Please input a valid input.\n";
      cin.clear();
      cin.ignore(256, '\n');
      cin >> feet;
    }//end while

  //inches
  cout << "Inches: ";
  cin >> inches;
  
  //user validation
  while(cin.fail() || (inches < 0) || (inches >= 12))
    {
      cout << "Please input a valid input.\n";
      cin.clear();
      cin.ignore(256, '\n');
      cin >> inches;
    }//end while
 
  //output
  cout << feet_and_inches(feet, inches) << endl;

  //user chooses if they want to continue
  cout << "Do you wish to continue?\n";
  cin >> choice;
  }//end do
  //continue so long as user inputs a variation of yes
  while ((choice == 'Y') || (choice == 'y') || (choice == 'yes') || (choice == 'YES'));
 
  //return 0
  return 0;     
}//end main

