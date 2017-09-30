#CHAPTER 3 NOTES - CS11
##3.1

**evaluating boolean expressions**
- boolean exprssion is an expression that is true or false
- boolean expression uses relational operations to produce 'true' or 'false' results
- eliminating parentheses from boolean expressions creates the following precedence: perform ! first, then relational operators, then evaulate &&, and then ||.
- use truth tables to determine truth
- ==precedence rules==:
>The unary operators +, −, ++, ––, and !
  The binary arithmetic operations *, /, %
  The binary arithmetic operations +, −
  The Boolean operations <, >, <= , >=
  The Boolean operations ==, ! =
  The Boolean operations &&
  The Boolean operations | |
  
- **short circuit evaluation** used by C++ to evaluate left-most operation; if that gives enough info to determine the truth of an expression without going to the next, C++ does this
- many other languages use **complete evaluation**'
> PITFALL:
assume you are writing a game where time is used in a boolean expression to determine if something happens.
//this code would not make sense
if (!time > limit)
//would evaluate to (!time) > limit, which makes no sense.
//instead use:
if (!(time > limit))
//or use
if (time <= limit)

**enumeration types**
- an enumeration type is a type whose values are defined by a list of constants of type int. 
- very much like a list of declared constants

	//example:
	enum MonthLength { JAN_LENGTH = 32, FEB_LENGTH = 28, ...}
	
-two or more named constants can have the same int value
- not specifiying the numeric values doesn't matter because they are assigned consecutive int values starting from 0
- C++ assigned new version of enumerations called strong enums/enum classes that avoid conventional enum problems
- for instance, enums may not act as integers always, and they are global in scope so you can't have the same enum value twice
- to define a strong enum, use the word class after enum
	
		//example
		enum class Days {Sun, Mon, Tue, Wed}
		enum class Weather {Rain, Sun};
		
		Days d = Days::Tue;
		Weather w =  Weather::Sun;
		//these vars aren't integers
		
##3.2
-dangling else problem created by nested if else statements (compiler cannot assign an if statement to an else)
- solution: use ==braces==

	//multiway if-statements use if-else
	//example:
	if (boolean exp)
	{
	//statement
	}
	else if (boolean exp)
	{
	//statement
	}
	else
	{
	//statement
	}

-the ==switch== statement is another kind that implementes multiway branches

	//example
	//variable 'grade' determines which branch is executed
	char grade;
	cout << "Enter your midterm grade and press Return: ";
	cin >> grade;
	switch (grade)
	{
	case 'A':
		cout << "Excellent. "
		<< "You need not take the final.\n";
		break;
	case 'B':
		cout << "Very good. ";
		grade = 'A';
		cout << "Your midterm grade is now "
		<< grade << endl;
		break;
	case 'C':
		cout << "Passing.\n";
		break;
	//same outcome for these two cases
	case 'D':
	case 'F':
		cout << "Not good. "
		<< "Go study.\n";
		break;
	default:
	cout << "That is not a possible grade.\n";
	}

-the choice of which branch is executed is determined by the **controlling expression** given in parentheses after the keyword **switch**
- **controlling expression** must always return a bool, an enum constant, an integer type, or a character
- when the computer reaches the **break** statement, the switch statement ends
- without the **break**, the computer would countinue evaluating other cases
- if no case has a constant that matches the controlling expression, the default label is executed. It is always safe to have a default section.

**using switch statements for menus**
- the multiway if-else is more versatile than the multiway switch
- but sometimes the switch statement is clearer for use in menus

**blocks**
- each branch of a switch or if-else statement is a sepearate subtask
- often best to make each action of a branch a specific function call
- a variable that is declared inside the a compound statement is **Local** and are destroyed when the compound statement is completed
- local variables only exist within the compound statement in which they are declared
- in a compound statement, you can use all the variables declared outside the compound statement and inside the statement
- a compound statement that contains variable declarations is called a **block** and variables declared within it are said to be **local to the block**
- call a block a **statement block** when it isn't the body of a function
- **statement blocks** can be nested within other **statement blocks** but we shouldn't do so because local variables are not inherited down the nest 
- instead, declare each of the **statement blocks** as **function calls**
- statement blocks should be used sparingly
##3.3
	
		int number = 2;
		int value_produced = 2 * (number++);
		cout << value_produced << endl;
		cout << number << endl;
		//produces 
		//4
		//3
		//the expressions uses the value that number has 
		//before it is incremented, so it number++ is seen as 2
		//before it is actually incremented
		
		int number = 2;
		int value_produced = 2 * (++number);
		cout << value_produced << endl;
		cout << number << endl;
		//produces
		//6
		//3
		//expression increments number first
		//if the ++ is
		//before the variable, then the incrementing is done before the 
		//value is returned; if the ++ is after the variable, then the
		//incrementing is done after the value is returned.
		
		//the same goes with decrement operators
		
####for loops

	for (Initialization_Action; Boolean_Expression; Update_Action)
	
	//ANSI C++ standard requires that any declaration in a for loop
	//is local to the loop
	
	//don't add an extra semicolon in a for loop
	//a semicolon itself is a statement in C++; it is known
	//as the empty/null statement
	

####<i>break</i> statement
-exits a loop before it ends in a normal way
-**break** statement only ends innermost loop that contains it

##3.4
####Designing Loops
- designing a loop requires designing three things:
- i. the body of the loop
- ii. the initializing statements
- iii. conditions for ending the loop	

-for loops can be used to produce a loop that repeats the loop bodya predetermined number of times

####ending a loop
- four common ways to terminate an **input** loop
- i. list headed by size
-ask a loop to read input exactly n times, where n is the size of a list 
- ii. ask before iterating
- just ask the user if they want to continue iterating 
- iii. list ended with a sentinel value
- a sentinel value is one that is somehow distinct from all the possible values on the list being read so it can signal the end of the list
-for example: a negative value in a list of all positive values can signal the loop to end
- must be certain that sentinel value actually exists in a loop
- iiii. running out of input

 - three general techniques:
 -i. count-controlled loops
 -ii. ask before iterating
 -iii. exit on a flag condition
 
	