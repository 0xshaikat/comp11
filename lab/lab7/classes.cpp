//Shaikat Islam and Nora Li
//11-28-17
//Lab 7 (Classes)
//COMP11

#include <iostream>

using namespace std;

//The Towers Class
class Towers{

public:
  void play_automatic(int num_disks, int start_tower, int end_tower);
  bool move_disk(int from_tower, int to_tower);
  int third_tower(int tower_a, int tower_b);
  int tower_size(int tower);
  int top_disk(int tower);
  int move_helper(int tower, int &index);
  bool check_for_win(int end_tower);
  char get_style();
  void initialize_towers(int start_tower);
  void print_towers();
  int get_height();

private:
  const static int empty = 10;
  const static int height = 4;
  int towers[height][3];

};//end Towers class


/*
 * This is the function that you must implement to play the game automatically
 * It takes three parameters:
 * num_disks: The number of disks that you're trying to move
 * start_tower: The tower that you're moving them from
 * end_tower: The tower that you're moving them to
 */
void Towers::play_automatic(int num_disks, int start_tower, int end_tower)
{
	if(num_disks == 1)
	{
	  Towers::move_disk(start_tower, end_tower);
	}else{
	  Towers::play_automatic(num_disks - 1, start_tower, third_tower(start_tower, end_tower));
	  Towers::move_disk(start_tower, end_tower);
	  Towers::play_automatic(num_disks - 1, third_tower(start_tower, end_tower), end_tower);
	}
}

/*----------------------------------------------------------------------------------------*/

/*
 * This function moves the top disk from from_tower to to_tower.
 * It also performs all the necessary checks to unsure that the move is valid
 */
bool Towers::move_disk(int from_tower, int to_tower)
{
	// Make sure that valid tower numbers have been entered.
	if((from_tower < 0 || from_tower > 2) || (to_tower < 0 || to_tower > 2))
	{
		cout << "\n";
		cout << "** INVALID Tower Value: The towers are numbered 0, 1, and 2.\n";
		cout << "** To tower: " << to_tower << endl;
		cout << "** From tower: " << from_tower << endl;
		return false;
	}

	// Make sure that an actual move is being specified
	if(from_tower == to_tower)
	{
		cout << "\n";
		cout << "** INVALID Move: to_tower and from_tower are the same.\n";
		cout << "** To tower: " << to_tower << endl;
		cout << "** From tower: " << from_tower << endl;
		return  false;
	}

	// Make sure that there is something to move
	if(towers[0][from_tower] == empty)
	{
		cout << "\n";
		cout << "** INVALID Move: There are no disks in tower " << from_tower << ".\n";
		return  false;
	}

	int move_index;
	int move_disk = Towers::move_helper(from_tower,  move_index);
	int onto_index;
	int onto_disk = Towers::move_helper(to_tower, onto_index);

	// Make sure that a bigger disk is not being placed on a smaller disk
	if(move_disk > onto_disk)
	{
		cout << "\n";
		cout << "** INVALID Move: You may not put a bigger disk on top of a smaller disk.\n";
		cout << "** To tower: " << to_tower << endl;
		cout << "** From tower: " << from_tower << endl;
		return false;
	}

	towers[move_index][from_tower] = empty;
	towers[onto_index + 1][to_tower] = move_disk;

	Towers::print_towers();
	return true;
}

/*
 * This function returns the the index of the tower that is not specified as one of the parameters.
 * If you call this function with tower_a = 1 and tower_b = 2, it will return 0.
 * If you call this function with tower_a = 0 and tower_b = 2, it will return 1.
 * If you call this function with tower_a = 0 and tower_b = 1, it will return 2.
 */
int Towers::third_tower(int tower_a, int tower_b)
{
	int tower_nums[3] = {0, 1, 2};
	int mask[3] = {1, 1, 1};

	mask[tower_a] = 0;
	mask[tower_b] = 0;

	return tower_nums[0] * mask[0] + tower_nums[1] * mask[1] + tower_nums[2] * mask[2]; 
}

/*
 * This function returns the size of the disk at the top of the specified tower.
 * This number will be 1, 3, 5, or 7 if there is a disk in the tower.
 * It will return empty = 10 if there are no disks in the tower.
 */
int Towers::top_disk(int tower)
{
	int disk = empty;

	for(int i = height - 1; i >= 0; i--)
	{
		if(towers[i][tower] != empty)
		{
			disk = towers[i][tower];
			break;
		}
	}

	return disk;
}

/*
 * This function returns the number of disks in the specified tower.
 * This number will be between 0 and 4.
 */
int Towers::tower_size(int tower)
{
	int count = 0;

	for(int i = 0; i < height; i++)
	{
		if(towers[i][tower] != empty)
		{
			count++;
		}
	}

	return count;
}

/*
 * Gets input from the user for whether they want to play manually or automatically.
 */
char Towers::get_style() 
{
	char input;

	do{
		cout << "Would you like to play manually or automatically? (m / a)\n";
		cin >> input;
	}while(input != 'm' && input != 'a');

	return input;
}

/*
 * Checks to see if the game has been won
 */
bool Towers::check_for_win(int end_tower){
	int full_tower[height] = {7, 5, 3, 1};

	for(int i = 0; i < height; i++)
	{
		if(towers[i][end_tower] != full_tower[i])
		{
			return false;
		}
	}

	return true;
}

/*
 * Helper to the move_disk function.
 * Returns the value of the disk at the top of the specified tower.
 * Also updates the index variable, indication the first empty index in the specified tower.
 */
int Towers::move_helper(int tower, int &index)
{

	if(towers[0][tower] == empty)
	{
		index = -1;
		return towers[0][tower];
	}

	for(int i = 0; i < height-1; i++){
		if(towers[i + 1][tower] == empty){
			index = i;
			return towers[i][tower];
		}
	}

	index = height-1;
	return towers[height-1][tower];
}

/*
 * Sets up the initial configuration of the game.
 */
void Towers::initialize_towers(int start_tower)
{
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(j == start_tower){
				towers[i][j] = (2 * (3 - i)) + 1;
			}else{
				towers[i][j] = empty;
			}
		}
	}
}

/*
 * Prints the current configuration of the towers.
 */
void Towers::print_towers()
{
	cout << endl;
	for(int i = height - 1; i >= 0; i--)
	{
		for(int j = 0; j < 3; j++)
		{
			string tower_line = "";

			switch(towers[i][j]) 
			{
    			case empty : 	
    				tower_line = "   |   ";
             		break;       
    			case 1 : 
    				tower_line = "   X   ";
             		break;
             	case 3 : 
    				tower_line = "  XXX  ";
             		break;
             	case 5 : 
    				tower_line = " XXXXX ";
             		break;
             	case 7 : 
    				tower_line = "XXXXXXX";
             		break;
             	default :
             		cout << towers[i][j] << endl;
             		cout << "You have broken the starter code. Goodbye!\n";
             		return;
			}

			cout << tower_line << " ";
		}
		cout << endl;
	}
	cout << "_______________________" << endl;
	cout << "   0       1       2" << endl;
	cout << endl;
}

//this returns the value of height in main()
int Towers::get_height(){
  return height;
}//end Towers:get_height()


int main () 
{
  //initialize Towers object
  Towers t;

  // Initialize the game
  int start_tower = 0;
  int end_tower = 2;
  int height = t.get_height();
  t.initialize_towers(start_tower);

  // Get the user PUMPED to play
  cout << "\n";
  cout << "Welcome to the Tower of Hanoi!\n";
  cout << "Your goal is to move the disks from tower " << start_tower;
  cout << " to tower " << end_tower << ".\n";
  cout << "BUT.....\n";
  cout << "You may move only one disk at a time.\n";
  cout << "You may not put a larger disk on top of a smaller one.\n";
  t.print_towers();
  char game_style = t.get_style();

  // If the user wants to play the game manually
  if(game_style == 'm')
    {
      int from_tower, to_tower;
      bool game_over = false;

      do{
	cout << "Please enter your move.\n";
	cout << "From tower: ";
	cin >> from_tower;
	cout << "To tower: ";
	cin >> to_tower;

	t.move_disk(from_tower, to_tower);
	game_over = t.check_for_win(end_tower);
      }while(!game_over);

      cout << "You have completed the Tower of Hanoi!!!\n";

      // If the user wants to run their automatic solution
    }else{
    t.play_automatic(height, start_tower, end_tower);

    if(t.check_for_win(end_tower))
      {
	cout << "You have completed the Tower of Hanoi!!!\n";
      }else{
      cout << "Unfortunately you were not successful.\n";
      cout << ":( :( :( :( :( :(\n";
    }
  }

  return 0;
}//end main
