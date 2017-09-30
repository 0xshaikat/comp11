// Shaikat Islam and Nora Li
// COMP11
// Lab 2
// September 19, 2017
/*******************BUGS**********************
 *So initially there were one warning and twelve errors initially. 
 *These are the errors we fixed, numbered in order.
 *1. In this file, L38 ("Have you been to the gym?)  required a semi-colon.
 * In the previous file, this would be L36.
 *2. In L43, the boolean expression '(been_to_the_gym == 'y') originally used 
 * an '=' operator instead of an '==' operator. This would have been L39.
 *3. In L57, the else statement after the if conditional with the 
 * '(hours_of_sleep > 6)' expression did not have opening and closing braces.
 * This would have been L57 in the original file.
 *4. In the first conditional with the expression '(hours_of_sleep > 6)', the 
 * operator was originally in the reverse direction.
 *5. In L72, the 'cin >> pocketChange' statement originally had the operands 
 * in reverse direction. This was originally L56.
 *6. In L71, the local variable 'pocketChange' had the type of int, when
 * when the program asked for a double. This is not type compatible. This
 * was originally L55.
 *7. In L88 (originally L64), there was an extraneous closing brace, which 
 * terminated the main function, not allowing the next 'cout' statements to 
 * print, or the function to return an integer.
 *8. The second 'cout' statement had a repeat of show3 as the printed value.
 *9. The pocketChange conditional was outside of any if statement, and would've
 * run without any execution of a boolean expression, so we added it to the else 
 * statement on L74.
 ***************HOW WE FIXED THEM*************
 *1. We added a semi-colon to this statement.
 *2. We changed the boolean operator to '=='.
 *3. We added opening and closing braces.
 *4. We changed the operator direction.
 *5. We changed the operator direction 
 *6. We changed the type to double.
 *7. We removed the extraneous closing brace.
 *8. We changed the variable to 'show2' instead of 'show3'.
 *9. We added the pocketChange conditional to the else statement on L74,
 * which runs if the user has had more than 6 hours of sleep.
 */
#include <iostream>
#include <string>

using namespace std;

int main() 
{
  string below_deck = "Below Deck";
  string american_horror = "American Horror Story";
  string the_challenge = "MTV's: The Challenge";

  string show1;
  string show2;
  string show3;

  int hours_of_sleep;
  cout << "How many hours of sleep did you get?" << endl;
  cin >> hours_of_sleep;

  if (hours_of_sleep > 6) { //if user got more than 6 hours of sleep,
    // below_deck should be first
    show1 = below_deck;

    char been_to_gym;
    cout << "Have you been to the gym (y/n)?" << endl; //L36 required a semi-colon.
    cin >> been_to_gym;

    if (been_to_gym == 'y') { // L39: operator should be '==' instead of '='
      show2 = the_challenge; 
      show3 = american_horror;
      //printing out stuff to check if it runs
      //cout << "\nL39 RAN!";
    }//end if
    else { 
      show2 = american_horror;
      show3 = the_challenge;
      //printing out stuff to check if it runs
      //cout << "\nL45 RAN!";
    }//end else
  }//end if 

  else { //L52 required opening and closing braces
    show1 = american_horror;
    //cout << "\nL52 RAN!";
    
    //the following lines of code before the end brace were outside the else 
    //statement, so they ran regardless of any conditional
    cout << "How much change is in your pocket?" << endl;
    double pocketChange;  //L55: pocketChange was an int
    cin >> pocketChange; //L56: '<<' operator is in the wrong direction for the cin

    if (pocketChange > .5)
    {
      show2 = the_challenge;
      show3 = below_deck;
      //cout << "\nL61 RAN!";
    }//end if
    else {
      show2 = below_deck;
      show3 = the_challenge;
      //cout << "\nL67 RAN!";
    }//end else
    //L64  had an extraneous closing brace.

  }//end else

    cout << "You should watch your shows in the following order:" << endl;
    cout << "1.) " << show1 << endl;
    cout << "2.) " << show2 << endl; //there was a DUPLICATE show3 here
    cout << "3.) " << show3 << endl;

    return 0;

}//end main
