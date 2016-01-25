#include "Alchemy.h"
#include "Rank.h"
const int NUMERIC_OFFSET = 65;
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

/**********************************************************************
* Purpose: This function is a constructor for the display class that
*		initilizes the class variables to null.
*
* Entry: This function does not take any arguments.
*
* Exit: This function does not have a return. 
*
************************************************************************/
Alchemy::Alchemy() : b1(Board()), m_valid(false), 
					m_points(0), m_start(true)
{
}


void Alchemy::RunGame()
{
	// uncomment below comments to test level up 
	//testlevelup();
	bool gameover = false;
	
	while (!gameover)
	{
		bool valid = true;
		
		do
		{
			if (valid == true)
				NextUp();

			 //uncomment below comments to test level up 
			//s1.setSymbol(WILD);
			//s1.setColor(0);
			//m_col = 'E';
			//m_row = 3;

			d1.XandY(20, 0);
			cout << ' '; // move cursor back to top of screen
			// get x and y locations from user
			m_col = d1.GetXlocation(); 
			m_row = d1.GetYlocation();

			try// End of Game check to see if discarded
			{
				c1.EndGameCheck(m_col, m_row);
			}
			catch (Exception msg)
			{
				cout << msg.getMessage();
				gameover = true;
			}

			// Check to make sure not discard
			if (m_col != char('J'))
			{	
				//reshow score to user
				d1.XandY(0, 6);
				cout << d1.getScore();
				try
				{
					valid = isValid((m_col - 65), (m_row - 1), s1);
					// decrement cauldren if valid move
					if (valid == true && c1.getDiscard() > 0)
					{
						c1.setDiscard((c1.getDiscard() - 1));
						//redraw the sidebar with updated info
						d1.SideBar(c1.getDiscard());
					}
					//calculate the new score with the valid move
					scoreboard((m_col - 65), (m_row - 1), s1);
				}
				catch (Exception msg)
				{
					// print out error message
					d1.XandY(20, 30);
					cout << msg.getMessage();
					valid = false;
				}
				if (valid == true)
				{
					// set the symbol to gold
					s1.setGold(true);
					//place everything into the array
					b1.PlaceArray(m_row, m_col, s1);

					//set the score to the new value
					d1.setScore(getScore());

					int real_x = int(m_col) - NUMERIC_OFFSET;

					// Get coordinates to place on the screen
					real_x = ((real_x * 6) + 23);

					int rows  = ((m_row * 3) + 2);
					//Place it on the board
				 d1.PlaceSymbol(s1.getSymbol(), s1.getColor(), real_x, rows);

					//check win cases
					checkgold(m_row, m_col);
					gameover = checkwingame();
					if (gameover == true)
						wingame();

					d1.XandY(20, 30); // Clear the bottom line
					cout << "                                    ";


				}

			}
			else if (m_col == char('J') && m_row == 1) // Case for discard
				valid = true;	
		} while (c1.getDiscard()< 4);
	}
}



/**********************************************************************
* Purpose: This function is used to check if a symbol placement is valid.
*
* Entry: Either the location of the element on the board.
*
* Exit: If a Symbol placement is valid.
*
************************************************************************/
bool Alchemy::isValid(int col, int row, Symbol & s1)
{
	bool pass = false;
	bool success = false;
	// check to make sure there isnt a symbol there
	// OR the symbol your trying to place is an EX
	if (b1.getSymbol(col, row).getSymbol() != BLANK || s1.getSymbol() == EX)
	{
		//pass = false;
		if (s1.getSymbol() == EX)
		{
			// make sure it can only be put on other symbols
			if (b1.getSymbol(col, row).getSymbol() != 0)
			{
				pass = true;
				s1.setSymbol(EX); 
				s1.setColor(0);
			}
		}
		// case for valid when placing symbol on skull and cross bones
		else if (b1.getSymbol(col, row).getSymbol() == EX)
			pass = true;
		else
		{
			pass = false;
			throw 
				Exception("A title is already there!                      ");
		}
	}
	else if (s1.getSymbol() == WILD) //case for placing wilds
	{
		s1.setSymbol(WILD);
		s1.setColor(0);
		success = true;
	}
	else
	{
		// check upper of placed
		bool upper = Check(s1, row - 1, col);
		bool lower = Check(s1, row + 1, col);
		bool left = Check(s1, row, col - 1);
		bool right = Check(s1, row, col + 1);
		bool stranded = !checkallzero(col, row);
		success = (upper && lower && left && right && stranded);
		if (success == false)
			throw 
			Exception("Incorrect Placement                                ");
	}
	return (pass || success);
}
/**********************************************************************
* Purpose: This function is used in conjunction with the isValid function
*		To see if an element is valid
*
* Entry: Either the location of the element above, below, right or left 
*		of the passed element.
*
* Exit: Either true of false based on placement.
*
************************************************************************/
bool  Alchemy::Check(Symbol s1, int col, int row)
{
	m_valid = false; // default to false 
	if (!(col >= 8 || row >= 9 || col < 0 || row < 0))// check if in bounds 
	{
		if (s1.getSymbol() == b1.getSymbol(row, col).getSymbol()) //same symbol
			m_valid = true;
		else if (s1.getColor() == b1.getSymbol(row, col).getColor()) // same color
			m_valid = true;
		else if (b1.getSymbol(row, col).getSymbol() == WILD) // If next to wild
			m_valid = true;
		else if (b1.getSymbol(row, col).getSymbol() == EX) // If next to skull
			m_valid = true;
		else if (b1.getSymbol(row, col).getSymbol() == BLANK)
			m_valid = true;
	}
	else // for wall case
		m_valid = true;
	return m_valid;
}


/**********************************************************************
* Purpose: This function is calulate the score of a move.
*
* Entry: An already validated move.
*
* Exit: Number of sides that it touches.
*
************************************************************************/
void Alchemy::scoreboard(int col, int row, Symbol s1)
{

	scoreboard_counter(row - 1,col,  s1 );
	scoreboard_counter(row + 1,col,  s1 );
	scoreboard_counter(row, col - 1,  s1 );
	scoreboard_counter(row, col + 1, s1 );
}
/**********************************************************************
* Purpose: This function increments the variable for the total score.
*
* Entry: An already validated move and position.
*
* Exit: An incremented score count.
*
************************************************************************/
void Alchemy::scoreboard_counter(int col, int row, Symbol s1)
{
	// local points counter that takes valid move and increments it
	if ((col >= 8 || row >= 9 || col < 0 || row < 0)) // check if in bounds
		m_valid = false;
	else// make sure there is no way they will cause a exception
	{
		if (!(col < 0) || !(row < 0)) 
			if (b1.getSymbol(row, col).getSymbol() != BLANK)
				m_points += 5;//if the neighboring tile is NOT blank
	}
}
/**********************************************************************
* Purpose: This function looks to see if the board is gold.
*
* Entry: none.
*
* Exit: Bool with either a true or false saying if the board
*		is blank or not.
*
************************************************************************/
bool Alchemy::checkgold(int row, char col)
{
	//check both col and row to see if everything in that row != 0
	//need to check if symbol or if the tile is gold.
	bool valid_row = true;
	bool valid_col = true;

	for (int i(0); i < 8 && valid_row == true; ++i) // Column  check
	{

		if (b1.getSymbol((int(col) - 65), i).getifGold() == false 
			|| b1.getSymbol((int(col) - 65), i).getSymbol() == BLANK)
			valid_row = false;
	}
	for (int i(0); i < 9 && valid_col == true; ++i) // Row check
	{
		if (b1.getSymbol(i, (row - 1)).getifGold() == false 
			|| b1.getSymbol(i, (row - 1)).getSymbol() == BLANK)
			valid_col = false;
	}

	if (valid_col == true)
	{
		int real_x = int(col) - NUMERIC_OFFSET;

		for (int i(0); i <= 8; ++i) // colors in the row
		{

			// Get coordinates to place on the screen
			int real_col = ((i * 6) + 21);

			int rows = (((row - 1) * 3) + 4);

			d1.Colorsquare(GOLD, real_col, rows);

			s1.setSymbol(BLANK);
			s1.setColor(0);

			b1.getSymbol(i, (row - 1)) = s1;
		}
	}
	else if (valid_row == true)
	{
		int real_x = int(col) - NUMERIC_OFFSET;
		for (int i(0); i <= 7; ++i) // colors in the column
		{
			// Get coordinates to place on the screen
			int real_row = ((real_x * 6) + 21);

			int rows = ((i * 3) + 4);

			d1.Colorsquare(GOLD, real_row, rows);

			s1.setSymbol(BLANK);
			s1.setColor(0);

			b1.getSymbol((int(col) - 65), i) = s1;
		}
	}
	return (valid_col || valid_row);
}
/**********************************************************************
* Purpose: This function is to see if a function is surreounded by 
*		nothing.
*
* Entry: A valid location for an element on the board.
*
* Exit: Number of sides that it touches.
*
************************************************************************/
bool Alchemy::checkallzero(int col, int row)
{
	bool upper(true);
	bool lower(true);
	bool left(true);
	bool right(true);
		if (row > 0)//(row-1 > 0)
			upper = b1.getSymbol( col ,row- 1).getSymbol() == 0 
			? true : false;
		if (row < 7)//(row + 1 < 9)
			lower = b1.getSymbol(col ,row+ 1 ).getSymbol() == 0 
			? true : false;
		if (col > 0)//(col - 1 > 0)
			left = b1.getSymbol(col- 1, row ).getSymbol() == 0 
			? true : false;
		if (col < 8) //(col + 1 < 9)
			right = b1.getSymbol(col + 1, row).getSymbol() == 0 
			? true : false;
	return (upper && lower && left && right);
}
/**********************************************************************
* Purpose: This function gets the next symbol and displays it.
*
* Entry: This functions takes no arguments.
*
* Exit: This function returns a new symbol to the screen. 
*		NOT in the array.. that's your job.
*
************************************************************************/
void Alchemy::NextUp()
{
	// Generate the symbols
	s1.generateSymbol();
	s1.generateColor();

	//Display
	d1.XandY(20, 28);
	cout << "SYMBOL: ";
	SetConsoleTextAttribute(handle, s1.getColor() | BACKGROUND_INTENSITY
		| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	cout << char(s1.getSymbol());
	SetConsoleTextAttribute(handle, 0 | BACKGROUND_INTENSITY
		| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}
/**********************************************************************
* Purpose: This function gets the score m_points.
*
* Entry: none.
*
* Exit: This function returns m_points and doesn't motify anything.
*
************************************************************************/
int Alchemy::getScore()
{
	return m_points;
}
/**********************************************************************
* Purpose: This function checks to see if board is all gold.
*
* Entry: None.
*
* Exit: This function returns a bool if it is full or not.
*
************************************************************************/
bool Alchemy::checkwingame()
{
	bool winner(true);
	for (int i = 0; i < 8 && winner; ++i)
	{
		for (int j = 0; j < 9 && winner; ++j)
		{
			if (b1.getSymbol(j, i).getifGold() == false )
					winner = false;
		}
	}
	return winner;
}
/**********************************************************************
* Purpose: This function gets called only when a win case has been 
*			detected and it is time to level up.
*
* Entry: None.
*
* Exit: None.
*
************************************************************************/
void Alchemy::wingame()
{
	system("CLS");
	cout << "You have bet the level! Level up\n";
	system("pause");
	// increase symbol amount by 1
	s1.setSymbolAmount(s1.getSymbolAmount() + 1);
	// increasecolor amount by 1
	s1.setcolorAmount(s1.getcolorAmount() + 1);

	d1.setLevel(2);
	d1.Startup();
	d1.setScore(0);

	// make a new clean board
	s1.setSymbol(BLANK);
	s1.setColor(0);
	for (int i(0); i < 8; i++)
	{
		for (int j(0); j < 9; j++)
			if (i != 0 || (j + 65) != 65)
				b1.PlaceArray((i + 1), (j + 65), s1);
	}
	b1 = Board();

	d1.setScore(m_points);
	d1.SideBar(0);
	RunGame();
}
/**********************************************************************
* Purpose: This function was made for testing purposes. Basically it 
*		loads up the board with the ƒ symbol except for at A 1.
*		Uncomment the stuff in main to simply place the last symbol
*		and watch the level up happen.
*
* Entry: none
*
* Exit: none.
*
************************************************************************/
void Alchemy::testlevelup()
{
	if (m_start)
	{
		s1.setSymbol(FORTE);
		s1.setColor(BLUE);
		for (int i(0); i < 8; i++)
		{
			for (int j(0); j < 9; j++)
				if (i != 0 || (j + 65) != 65)
					b1.PlaceArray((i + 1), (j + 65), s1);
		}
		m_start = false;
	}
}
/**********************************************************************
* Purpose: This function copys data from one Alchemy object to the 
*			other.
*
* Entry: Alchemy object to be copied.
*
* Exit: none.
*
************************************************************************/
Alchemy::Alchemy(const Alchemy & copy)
{
	m_row = copy.m_row;
	m_col = copy.m_col;

	m_valid = copy.m_valid;
	m_points = copy.m_points;
	m_start = copy.m_start;
}
/**********************************************************************
* Purpose: This function deallocates memory to the OS.
*
* Entry: none.
*
* Exit: none.
*
************************************************************************/
Alchemy & Alchemy::operator=(const Alchemy & rhs)
{
	if (this != &rhs)
	{
		m_row = rhs.m_row;
		m_col = rhs.m_col;

		m_valid = rhs.m_valid;
		m_points = rhs.m_points;
		m_start = rhs.m_start;
	}
	return *this;
}
/**********************************************************************
* Purpose: This function deallocates memory to the OS.
*
* Entry: none.
*
* Exit: none.
*
************************************************************************/
Alchemy::~Alchemy()
{
}
