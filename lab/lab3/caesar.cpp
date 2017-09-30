//Shaikat Islam and Nora Li
//26-09-17
//lab3
//COMP11


#include <iostream>
#include <string>

using namespace std;
//void main()
//Purpose: return string with caesar cypher encryption
//Parameters: standard input
//Returns: 0, standard output
int main() 
{
  string message;
  int shift;
  int cipher_choice;
  string v_shift;

  //user continue?
  char choice = 'Y';

  do{
  //user input
  cout << "What secrets do you have to share? No spaces. No capitals.\n";
  cin >> message;
  cout << "How do you want to encrypt your string? (0 for caesar, 1 for vigenere)\n";
  cin >> cipher_choice;
  if (cipher_choice == 0)
    {
      cout << "How much do you want to shift your secret? Positive integers only.\n";
      cin >> shift;

      //Get your loop on!
      //Each char of the string has an ASCII value. If shifted value greater than
      //122(Z), do SHIFTED VALUE % 122 and return ASCII of 122 - (remainder + 96), 
      //as 96 is before 'a' in the ASCII table. Else return shifted value ASCII.

      //length of string
      int len = message.length();
      //change shift value
      shift %= 26;
  
      //encrypt string
      for (int i = 0; i < len; i++)
	{

	  //if SHIFTED VALUE > 122
	  if (message[i] + shift > 'z')
	    {
	      //96 is b/f 'a'
	      message[i] = ((message[i] + shift) - 'z') + 96;
	    }  //end if
	  else
	    {
	      message[i] = message[i] + shift;
	    }//end else
	}//end for

      //output message
      cout << "Here is your secret!\n";
      cout << message << endl;

      //if the user decides to continue
      cout << "Do you wish to continue? (Y/N only)\n";
      cin >> choice;
    }//end if
  //vigenere

  //EXTRA CREDIT ATTEMPT
  else
    {
      cout << "Please input your string to encrypt your secret message.\n";
      cin >> v_shift;
      //length of string
      int len = message.length();
      int len_two = v_shift.length();
      for (int i = 0; i < len; i++)
	{

	  //location in vigenere string cipher
	  int loc = len_two - (i % len_two); //prevent EOL in a list
	  //if value doesnt exist (message is longer than vigenere string)

	  //change the shift
	  shift = v_shift[loc];
	  //mod it
	  shift %= 26;

	  //if SHIFTED VALUE > 122
	  if (message[i] + shift > 'z')
	    {
	  //96 is b/f 'a'
	      message[i] = ((message[i] + shift) - 'z') + 96;
	    }  //end if
	  else
	    {
	      message[i] = message[i] + shift;
	    }//end else
	  
	}//end for

      //output message
      cout << "Here is your secret!\n";
      cout << message << endl;

      //if the user decides to continue
      cout << "Do you wish to continue? (Y/N only)\n";
      cin >> choice;
	    
    }//end else
    }//end do
  while (choice == 'Y');
  

  //return statement
  return 0;

}//end main
