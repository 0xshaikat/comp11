/********************
 * COMP11 Fall 2017
 * Homework 2
 * Problem 2
 * Shaikat Islam
 *
 * Test input: a, b, c
 * Expected output: a, b, c
 *
 * Test input: Hi, HELLO, hey
 * Expected output: cat, dog, elephant
 *
 * Test input: wHaT, Is, uP
 * Expected output: abba, jellyfish, xanadu
 *********************/
#include <iostream>
#include <locale>
#include <string>
using namespace std;

//Why define a function for this when I can use string::compare?
//string::compare sorts strings in ASCII order, but I didn't know if
//it would treat CAPITALS in the MIDDLE, or END of a string as
//more alphabetical/greater than the same character, as a lowercase
//character. As a result, it was necessary to entirely convert
//the strings to lowercase.

// string lowercase(string s)
// Purpose: Convert a string to lowercase.
// Parameters: string s
// Returns: string
string lowercase(string s)
{
    for(int i = 0; i < s[i]; i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

// bool isAlpha(string a, string b)
// Purpose: Return true if the first string is more alphabetical than the second
//         ; false otherwise.
// Parameters: string a, string b
// Returns: bool
bool isAlpha(string a, string b)
{
    //if the result of a.compare(b) is negative, a comes before b alphabetically
    if (a.compare(b) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}//end isAlpha

// void main()
// Purpose: Return three strings in alphabetical order
// Parameters: standard input
// Returns: 0, standard output
int main()
{
    //strings to store the users info
    string string_one, string_two, string_three;
    //lowercase versions of the strings
    string lower_one, lower_two, lower_three;

    cout << "Enter a word:\n";
    cin >> string_one;
    lower_one = lowercase(string_one);
    cout << "Enter another word:\n";
    cin >> string_two;
    lower_two = lowercase(string_two);
    // do-while to check for duplicity within the two strings
    do
    {
        if (lower_one == lower_two)
        {
            cout << "You've already entered that. Please try again.\n";
            cin >> string_two;
            lower_two = lowercase(string_two);
        }
    }
    while (lower_one == lower_two);

    cout << "And finally, enter your final word.\n";
    cin >> string_three;
    lower_three = lowercase(string_three);

    //do-while to check for duplicity within all the strings
    do
    {
        //conditional checks for duplicity within all three strings
        if (lower_three == lower_two || lower_three == lower_one)
        {
            cout << "C'mon now. You've entered that already. Try again.\n";
            cin >> string_three;
            lower_three = lowercase(string_three);
        }
    }
    while (lower_three == lower_two || lower_three == lower_one);

    cout << "\nIn alphabetical order:\n";
    //alphabetizing using string::compare and isAlpha function
    //this would be easier using an array and the sort function

    //string_one is most alpha
    if (isAlpha(lower_one, lower_two) && isAlpha(lower_one, lower_three))
    {
        cout << string_one << endl;
        if (isAlpha(lower_two, lower_three))
        {
            cout << string_two << endl;
            cout << string_three << endl;
        }
        else
        {
            cout << string_three << endl;
            cout << string_two << endl;
        }
    }// end case string_one

    //string two is most alpha
    else if (isAlpha(lower_two, lower_one) && isAlpha(lower_two, lower_three))
    {
        cout << string_two << endl;

        if (isAlpha(lower_one, lower_three))
        {
            cout << string_one << endl;
            cout << string_three << endl;
        }

        else
        {
            cout << string_three << endl;
            cout << string_one << endl;
        }
    }//end case string_two

    //string three is most alpha
    else
    {
        cout << string_three << endl;

        if (isAlpha(lower_one, lower_two))
        {
            cout << string_one << endl;
            cout << string_two << endl;
        }

        else
        {
            cout << string_two << endl;
            cout << string_one << endl;
        }
    }//end case string_three

    //return statement
    return 0;

}//end main
