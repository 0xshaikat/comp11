/********************
 * COMP11 Fall 2017
 * Homework 2
 * Extra Credit
 * Shaikat Islam
 *********************/

#include <iostream>
#include <locale>
#include <string>
#include <vector>
using namespace std;

// void quicksort()
// Purpose: Implement quicksort for vectors of type string
// Parameters: vector<string>& vec, int left, int right;
// Returns: void
void quicksort (vector<string>& vec, int left, int right)
{

    int i = left;
    int j = right;
    string temp;
    string pivot = vec[(left + right) / 2];

    //partition
    while (i <= j)
    {
        while (vec[i] < pivot)
        {
            i++;
        }
        while (vec[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            i++;
            j--;
        }//end if
    }//end while

    //recursion
    if (left < j)
    {
        quicksort(vec, left, j);
    }//end if
    if (i < right)
    {
        quicksort(vec, i, right);
    }//end if
}//end quicksort

// void main()
// Purpose: Return n strings in alphabetical order
// Parameters: standard input
// Returns: 0, standard output
int main()
{
    //number of elements in array
    int n;
    //input
    string input;
    //user chooses if they want to continue
    char choice = 'Y';
    do
    {
        cout << "How many words would you like to sort?\n";
        cin >> n;
        //integer validation
        while ((cin.fail()) || (n <= 0))
        {
            cout << "Error! Not a positive int! Please enter a positive int! \n";
            cin.clear();
            cin.ignore(256, '\n');
            cin >> n;
        }



        //words
        vector<string> v;

        //populate vectors
        for (int i = 0; i < n; i++)
        {
            int j = i;
            cout << "Enter string no. " << j + 1  << ":" << endl;
            cin >> input;
            v.push_back(input);
        }

        //quicksort
        quicksort(v, 0, n - 1);
        cout << "\nAlphabetized:\n";

        //print out sorted strings
        for (int i = 0; i < n; i++)
        {
            int j = i;
            cout << "Word no. " << j + 1 << ": " <<  v[i] << endl;
        }

        cout << endl;
        cout << "Would you like to continue?\n (Y/N)\n";

        cin >> choice;
        //choice validation
        do
        {
            if (! (choice == 'n' || choice == 'N' || choice == 'Y' || choice == 'y'))
            {
                cout << "Not a valid response! Please try again.\n";
                cin >> choice;
            }//end if
        }//end do
        while (! (choice == 'n' || choice == 'N' || choice == 'Y' || choice == 'y'));
    }
    while (choice == 'Y' || choice == 'y');

    //return statement
    return 0;

}//end main
