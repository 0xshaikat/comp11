//Shaikat Islam and Nora Li
//17-10-17
//Lab 5 (Arrays)
//CS11 Fall 2017 

#include <iostream>
using namespace std;

//int main()
//Purpose: Bamboozle the audience.
//Parameters: std output
//Return: std output
int main()
{
  //array of 16 cards 
  char* cards[16] = {"JD", "JC", "JH", "JS", "QD", "QC", "QH", "QS", "KD", "KC", "KH", "KS", "AD", "AC", "AH", "AS"};

  //user input 
  int row, col;

  //index of card 
  int index;

  //size of card array
  const int SIZE = 16;

  cout << "Prepare yourself for the greatest trick on earth...\n\n";

  //print array
  for(int i = 0; i < SIZE; i++)
    {
      if ((i == 3) || (i == 7) || (i == 11) || (i == 15)){
	cout << cards[i] << "\n";
      }//end if
      else {
	cout << cards[i] << " ";
      }//end else
    }//end for

  cout << endl;

  //ui
  cout << "Pick a card (any card) and tell me what row it's in: ";

  cin >> row;

  cout << "Excellent! Now I will shuffle the cards in a completely random way!\n";

  //print BAMBOOZELED ARRAY
 for(int i = 0; i < SIZE; i++)
    {
      if ( i % 4 == 3)
	{
	  cout << cards[i] << " ";
	}//end if
    }//end for

  cout << endl;

  for(int i = 0; i < SIZE; i++)
    {
      if ( i % 4 == 2)
	{
	  cout << cards[i] << " ";
	}//end if
    }//end for

  cout << endl;

  for(int i = 0; i < SIZE; i++)
    {
      if ( i % 4 == 1)
	{
	  cout << cards[i] << " ";
	}//end if
    }//end for

  cout << endl;

  for(int i = 0; i < SIZE; i++)
    {
      if ( i % 4 == 0)
	{
	  cout << cards[i] << " ";
	}//end if
    }//end for

  cout << endl;

  //ui
  cout << "Now tell me what row your card is in NOW: ";
  cin >> col;
  cout << endl;

  //find the position in the array
  index = (row * 4) - col; 

  //result
  cout << "Your card is " <<  cards[index] << "!" << endl;
  cout << endl;
  cout << "SHABAM!!!" << endl;

  //return statement
  return 0;

}//end main
