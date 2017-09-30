/********************
 * COMP11
 * Homework 1
 * Problem 3
 * Shaikat Islam
 *********************/

#include <iostream>
#include <string>
using namespace std;

//int main()
//Purpose: emulate the film The Labyrinth in C++, with a few changes
//Parameters: none
//Returns: 0, standard output
int main()
{
    //======VARIABLES======

    //Game mechanics. Includes point system as well as choice
    //mechanism.
    int points = 0; //stores total no. of points
    char choice;
    //comparison operator for user input
    char positive = 'Y';
    const int plus_one = 1;
    const int plus_two = 2;
    const int plus_three = 3;

    //User input
    string user_query = "What's yo name?\n";
    string name; //for username
    string directions = "\t(Y = Yes/N= No (Characters are case sensitive))\n";
    string final_points_a = "You've got ";
    string final_points_b = " points!\n";

    //Welcome (for the beginning of the game, once the user has entered)
    string welcome_one = "Bienvenidos. Welcome. Wilkommen. This is the labyrinth, You have entered it. By it, I mean \"labyrinth\". Your name is ";

    string welcome_two = ". That is good. Please enjoy your visit.\n";
    string welcome_three = "Your cousin's niece's uncle's dad Luke is sobbing...\n";

    //Questions
    string q_one = " Oh no! Or, oh yes! A Young Thugger Girl has taken Luke. \nDo you fight YTG?";

    string q_two = "You've gained the THUGGER POWER! But you only have 3 hours to find Luke, which can only be done with SOSA. \nSosa is waiting for you. Do you stalk Sosa to get back Luke?\n";

    string q_three = "UH...Do you NOT sacrifice the features to save Luke?\n";

    //Question responses, once the user has answered

    //Q1
    //yes
    string y_q_one = "What a brave soul. The power of thugger is now second nature to you.\n";
    //no
    string n_q_one = "Wrong answer. You die. Luke dies. Everyone...just dies!\n";

    //Q2
    //yes
    string y_q_two = "Good job! SOSA is appreciative and gives you forty new features on his latest album.\n You can sacrifice the features to save Luke.\n";
    //no
    string n_q_two = "SOSA removes you from the lair and transports you to Medford/Sommerville.\n" ;

    //Q3
    //yes
    string y_q_three = "AYYY! You good. NO ONE likes Luke. You are now. A. Rapper!\n Go win some grammys. Maybe save your hometown from overzealous yuppies.\n";
    //no
    string n_q_three = "Why would you do that? Luke is crying and has soiled himself and you're outta luck with those features. Poor decision making.\n";

    //FINAL OUTCOMES (based on points)
    string outcome_one = "You're wack. Go home and listen to some LOGIC.\n";
    string outcome_two = "Ayy. You're mediocre. UH...You like JCole?\n" ;
    string outcome_three = "You're perffffff. Good stuff. Keep on keepin' on.\n";


    //=========================CODE===========================

    //user interaction
    cout << user_query;
    getline(cin, name);
    cout << endl;

    //negative/positive criticisms that involve the user's name
    //(must be declared after "getline(cin, name)")
    string criticism = "Wow. Really. Did you just do that " + name + "?\n";
    string compliment = "Woah! You're rocking it here, " + name + "!\n";


    //welcome
    cout << welcome_one << name << welcome_two << welcome_three;

    //FIRST QUESTION
    cout << q_one << directions;
    cin >> choice;

    //conditional for first q
    if (choice == positive)
    {
        //increase points by one
        points += plus_one;

        //first outcome
        cout << y_q_one;
        cout << compliment;

        //SECOND QUESTION
        cout << q_two << directions;
        cin >> choice;

        //conditional for second q
        if (choice == positive)
        {
            //increase points by two
            points += plus_two;

            //second outcome
            cout << y_q_two;

            //THIRD QUESTION
            cout << q_three << directions;
            cin >> choice;

            //conditional for third q
            if (choice == positive)
            {
                //increase points by three
                points += plus_three;
                cout << y_q_three;

                //print points for the user
                cout << final_points_a << points << final_points_b;

                //final outcome
                cout << outcome_three;
                cout << compliment;

                //return statement
                return 0; //end game
            }//end if

            //'no' choice for question three
            else
            {
                //print result of choice
                cout <<  n_q_three;

                //print points
                cout << final_points_a << points << final_points_b;

                //final outcome
                //conditional to determine what outcome the player gets
                if (points < 4)
                {
                    cout << outcome_one;
                }
                else if (points < 7)
                {
                    cout << outcome_two;
                }//end else
                else
                {
                    cout << outcome_three;
                }

                //return statement
                return 0;
            }//end else if
        }//end if

        //'no' choice for question two
        else
        {
            //print criticism
            cout << criticism;
            cout << n_q_two;

            //print points
            cout << final_points_a << points << final_points_b;

            //conditional to determine what outcome the player gets
            if (points < 4)
            {
                cout << outcome_one;
            }
            else if (points < 8)
            {
                cout << outcome_two;
            }//end else
            else
            {
                cout << outcome_three;
            }

            //return statement
            return 0;
        }
    }//end if

    //'no' choice for question one
    else
    {
        //result of decision
        cout << criticism;
        cout << n_q_three;

        //print out points
        cout << final_points_a << points << final_points_b;

        //print final outcome
        cout << outcome_one;

        //return statement
        return 0;

    }//end else

}// end main
