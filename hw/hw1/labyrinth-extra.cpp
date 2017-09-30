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
//Purpose:
//Parameters:
//Returns:

int main()
{
    //======VARIABLES======

    //Game mechanics. Includes point system as well as choice
    //mechanism.
    int points = 0; //stores total no. of points
    int choice;
    //comparison operator for user input
    const int plus_one = 1;
    const int plus_two = 2;
    const int plus_three = 3;
    const int plus_ten = 10;

    //User input
    string user_query = "What's yo name?\n";
    string name; //for username
    string directions = "(Enter 1, 2, or 3. Do it twice to lock in your choice.)\n";
    string final_points_a = "You've got ";
    string final_points_b = " points!\n";

    //Welcome (for the beginning of the game, once the user has entered)
    string welcome_one = "Bienvenidos. Welcome. Wilkommen. This is the labyrinth, You have entered it. By it, I mean \"labyrinth\". Your name is ";

    string welcome_two = ". That is good. Please enjoy your visit.\n";
    string welcome_three = "Your cousin's niece's uncle's dad Luke is sobbing...\n";

    //Questions
    string q_one = " Oh no! Or, oh yes! A Young Thugger Girl has taken Luke.\nIn order to defeat the YTG, you have the choice of rap battling (ENTER 1), a good ol' fashioned fist fight (ENTER 2), or you could go back where you came from (ENTER 3).\n";

    string q_two = "You've gained the THUGGER POWER! But you only have 3 hours to find Luke, which can only be done with SOSA.\nSosa is waiting for you. Do you stalk Sosa to get back Luke (ENTER 1)? Or do you ambush Sosa, and interrogate him (ENTER 2)? Or do you give up and do nothing (ENTER 3)? \n";

    string q_three = "UH...Do you NOT sacrifice the features to save Luke (ENTER 1)? Or do you challenge SOSA to a dance competition (ENTER 2)? Perhaps you are finished with the labyrinth and wish to have a cup of tea with SOSA and discuss the challenges of globalization in the modern world (ENTER 3). \n";

    //Question responses, once the user has answered

    //Q1
    // rap battling sosa
    string c1_q_one = "What a brave soul. The power of thugger is now second nature to you.\n";
    //fist fight w/ sosa
    string c2_q_one = "The Young Thugger Girl overpowers you and you are injured. Some of YTG's essence rubs off on you.\n";
    //do nothing
    string c3_q_one = "Wrong answer. You die. Luke dies. Everyone...just dies!\n";

    //Q2
    //stalking SOSA
    string c1_q_two = "Good job! SOSA is appreciative and gives you forty new features on his latest album.\n You can sacrifice the features to save Luke.\n";
    //ambush and interrogate
    string c2_q_two = "What the heck! SOSA doesn't really like being ambushed off guard! But he relents, and tells you where Luke is. In the corner of your eye, you see 40 features in his pocket, which you take. SOSA doesn't like this. He says he'll give you Luke if you give them back.\n";
    //do nothing
    string c3_q_two = "SOSA thinks you're weird for doing nothing. Sosa removes you from the lair and transports you to Medford/Sommerville.\n" ;

    //Q3
    //not sacrificing the features
    string c1_q_three = "AYYY! You good. NO ONE likes Luke. You are now. A. Rapper!\n Go win some grammys. Maybe save your hometown from overzealous yuppies.\n";
    //dance battling SOSA
    string c2_q_three = "He can't dance. You got no moves, either. This was unfruitful.\n And uneventful. He takes the feautures from you anyway, and you are sad. Luke is with you, but he's sobbing hysterical.\n See what happened? Now you gotta take care of Luke.\n";
    //having tea and globalization
    string c3_q_three = "SOSA appreciates your deep, informed, conversation on the topic of globalization and invites you to his home, where he serves you Oolong tea and continues his discussion, which has taken a turn to overfishing in the Bering Strait. Life is good. Life is great. And you found Luke too! He's the one serving the tea. He finds that his kidnapping has opened up his eyes to the fabulous world of tea brewing. Good for Luke. Good for you. Good for SOSA.\n";

    //FINAL OUTCOMES (based on points)
    string outcome_one = "You're wack. Go home and listen to some LOGIC.\n";
    string outcome_two = "Ayy. You're mediocre. UH...You like JCole?\n" ;
    string outcome_three = "You're perffffff. Good stuff. Keep on keepin' on.\n";
    string game_winner = "You are amazing. Perfect flawless. The rap god. You have WON.\n";


    //CODE

    //user interaction
    cout << user_query;
    getline(cin, name);
    cout << endl;

    //negative/positive criticisms that involve the user's name
    //(must be declared after "getline(cin, name)")
    string criticism = "Wow. Really. Did you just do that " + name + "?\n";
    string compliment = "Woah! You're rocking it here, " + name + "!\n";

    //=========================CODE=====================

    //welcome
    cout << welcome_one << name << welcome_two << welcome_three;

    //FIRST QUESTION
    cout << q_one << directions;
    cin >> choice;

    //check type
    while (!(cin >> choice))
    {     cout << "I said give me an integer! Try again: ";
        //clear input stream
        cin.clear();
        // skip past the next newline, or 1000 chars
        cin.ignore(1000,'\n');
    }
    //tell em what they entered
    cout << "You entered " << choice << "." << endl;

    //conditional for first q
    if (choice == 1)
    {
        //increase points by one
        points += plus_one;

        //first outcome
        cout << c1_q_one;
        cout << compliment;

        //SECOND QUESTION
        cout << q_two << directions;
        cin >> choice;

        //check type
        while (!(cin >> choice))
        {
            cout << "I said give me an integer! Try again: ";
            //clear input stream
            cin.clear();
            // skip past the next newline, or 1000 chars
            cin.ignore(1000,'\n');
        }
        //tell em what they entered
        cout << "You entered " << choice << "." << endl;

        //conditional for second q
        if (choice == 1)
        {
            //increase points by two
            points += plus_two;

            //second outcome
            cout << c1_q_two;

            //THIRD QUESTION
            cout << q_three << directions;
            cin >> choice;

            //check type

            while (!(cin >> choice))
            {
                cout << "I said give me an integer! ";
                //clear input stream
                cin.clear();
                // skip past the next newline, or 1000 chars
                cin.ignore(1000,'\n');
            }
            //tell em what they entered
            cout << "You entered " << choice << "." << endl;

            //conditional for third q
            if (choice == 1)
            {
                //increase points by three
                points += plus_three;
                cout << c1_q_three;

                //print points for the user
                cout << final_points_a << points << final_points_b;

                //final outcome
                cout << outcome_three;
                cout << compliment;

                //return statement
                return 0; //end game
            }//end if

            //second choice for question three
            else if (choice == 2)
            {
                //print result of choice
                cout <<  c2_q_three;

                //add points
                points += plus_two;

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

            //positive outcome for question three
            else if (choice == 3)
            {
                //print neg. outcome
                cout << compliment;
                cout << c3_q_three;

                //since this is the best outcome, add 10 points
                points += plus_ten;

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
                else if (points < 13)
                {
                    cout << outcome_three;
                }
                else{
                    cout << game_winner;
                }//end else

                //return statement
                return 0;
            }//end else if
        }//end if

        //2nd choice for question two
        else if (choice == 2)
        {

            //print criticism
            cout << criticism;
            cout << c2_q_two;
            cout << q_three;

            //increase points by 1
            points += plus_one;

            //QUESTION 3
            cin >> choice;

            //check type
            while (!(cin >> choice))
            {
                cout << "I said give me an integer! Try again: ";
                //clear input stream
                cin.clear();
                // skip past the next newline, or 1000 chars
                cin.ignore(1000,'\n');
            }
            //tell em what they entered
            cout << "You entered " << choice << "." << endl;

            //conditional for q3
            if (choice == 1)
            {
                //increase points by three
                points += plus_three;
                cout << c1_q_three;

                //print points for the user
                cout << final_points_a << points << final_points_b;

                //final outcome
                cout << outcome_three;
                cout << compliment;

                //return statement
                return 0; //end game
            }//end if

            //second choice for question three
            else if (choice == 2)
            {
                //print result of choice
                cout << c2_q_three;

                //add points
                points += plus_two;

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

            //positive outcome for question three
            else if (choice == 3)
            {
                //print results of decision
                cout << compliment;
                cout << c3_q_three;

                //add points (10 since this is the best CHOICE)
                points += plus_ten;

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
                else if (points < 13)
                {
                    cout << outcome_three;
                }// end else if
                else
                {
                    cout << game_winner;
                }// end else

                //return statement
                return 0;
            }//end else if


        }
        //negative outcome for question two
        else if (choice == 3)
        {
            //print neg. outcome
            cout << criticism;
            cout << c3_q_two;

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
        }//end else if
    }//end if

    //choice 2 for question one
    else if (choice == 2)
    {
        //print neg. outcome
        cout << criticism;
        cout << c2_q_one;

        //increase points by one
        points += plus_one;

        //SECOND QUESTION
        cout << q_two << directions;
        cin >> choice;

        //check type
        while (!(cin >> choice))
        {
            cout << "I said give me an integer! Try again: ";
            //clear input stream
            cin.clear();
            // skip past the next newline, or 1000 chars
            cin.ignore(1000,'\n');
        }
        //tell em what they entered
        cout << "You entered " << choice << "." << endl;

        //conditional for q2
        if (choice == 1)
        {
            //increase points by two
            points += plus_two;

            //second outcome
            cout << c1_q_two;

            //THIRD QUESTION
            cout << q_three << directions;
            cin >> choice;

            //check type
            while (!(cin >> choice))
            {
                cout << "I said give me an integer! Try again: ";
                //clear input stream
                cin.clear();
                // skip past the next newline, or 1000 chars
                cin.ignore(1000,'\n');
            }
            //tell em what they entered
            cout << "You entered " << choice << "." << endl;

            //conditional for third q
            if (choice == 1)
            {
                //increase points by three
                points += plus_three;
                cout << c1_q_three;

                //print points for the user
                cout << final_points_a << points << final_points_b;

                //final outcome
                cout << outcome_three;
                cout << compliment;

                //return statement
                return 0; //end game
            }//end if

            //second choice for question three
            else if (choice == 2)
            {
                //print result of choice
                cout << c2_q_three;

                //add points
                points += plus_two;

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

            //positive outcome for question three
            else if (choice == 3)
            {
                //print result of choice
                cout << compliment;
                cout << c3_q_three;

                //add points (10 since this is the best CHOICE)
                points += plus_ten;

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
                else if (points < 13)
                {
                    cout << outcome_three;
                }
                else
                {
                    cout << game_winner;
                }

                //return statement
                return 0;
            }//end else if
        }//end if

        //2nd choice for question two
        else if (choice == 2)
        {

            //print criticism
            cout << criticism;
            cout << c2_q_two;
            cout << q_three;

            //increase points by 1
            points += plus_one;

            //QUESTION 3
            cin >> choice;

            //check type
            while (!(cin >> choice))
            {     cout << "I said give me an integer! Try again: ";


                cin.clear();
                // skip past the next newline, or 1000 chars
                cin.ignore(1000,'\n');
            }
            //tell em what they entered
            cout << "You entered " << choice << "." << endl;

            //conditional for q3
            if (choice == 1)
            {
                //increase points by three
                points += plus_three;
                cout << c1_q_three;

                //print points for the user
                cout << final_points_a << points << final_points_b;

                //final outcome
                cout << outcome_three;
                cout << compliment;

                //return statement
                return 0; //end game
            }//end if

            //second choice for question three
            else if (choice == 2)
            {
                //print result of choice
                cout << c2_q_three;

                //add points
                points += plus_two;

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

            //positive outcome for question three
            else if (choice == 3)
            {
                //print results of decision
                cout << compliment;
                cout << c3_q_three;

                //add points (10 since this is the best CHOICE)
                points += plus_ten;

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
                else if (points < 13)
                {
                    cout << outcome_three;
                }// end else if
                else
                {
                    cout << game_winner;
                }

                //return statement
                return 0;
            }//end else if
        }//end else if
        //negative outcome for question two
        else if (choice == 3)
        {
            //print neg. outcome
            cout << criticism;
            cout << c3_q_two;

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
        }//end else if
    }// end else if

    //third option for Q1
    else if (choice == 3)
    {
        //print neg. outcome
        cout << criticism;

        //print points
        cout << final_points_a << points << final_points_b;

        //print final outcome
        cout << outcome_one;

        //return statement
        return 0;
    }//end else if

}// end main
