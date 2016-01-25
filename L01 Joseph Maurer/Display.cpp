#include "Display.h"

HANDLE clean = GetStdHandle(STD_OUTPUT_HANDLE);

// All used for diplaying the board in startup
const int MAX_VERTICAL_HEIGHT = 27; 
const int MAX_DIVIDER = 29;
const int MAX_VERTICAL_SIZE = 10;
const int MAX_HORIZONTAL_HEIGHT = 53; 
const int MAX_HORIZONTAL_SIZE = 9;

/**********************************************************************
* Purpose: This function is a constructor for the display class that 
*		initilizes the class variables to null.
*
* Entry: none.
*
* Exit: Sets the backgroud color to white and black text.
*
************************************************************************/
Display::Display() : m_X(0), m_Y(0), m_color(0), 
		m_symbol(0), m_points(0), m_level(1)
{
	SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY 
		| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED );	
}
/**********************************************************************
* Purpose: Copy CTOR manager function.
*
* Entry: Display object to be copied.
*
* Exit: none.
*
************************************************************************/
Display::Display(const Display & copy)
{
	m_X = copy.m_X;
	m_Y = copy.m_Y;
	m_color = copy.m_color;
	m_symbol = copy.m_symbol;
	m_points = copy.m_points;
	m_level = copy.m_level;
}
/**********************************************************************
* Purpose: Manager function that does a copy of the information.
*
* Entry: Display object to be copied. 
*
* Exit: none.
*
************************************************************************/
Display & Display::operator=(const Display & rhs)
{
	if (this != &rhs)
	{
		m_X = rhs.m_X;
		m_Y = rhs.m_Y;
		m_color = rhs.m_color;
		m_symbol = rhs.m_symbol;
		m_points = rhs.m_points;
		m_level = rhs.m_level;
	}
	return *this;
}
/**********************************************************************
* Purpose: This function sets up the board when the game starts up. 
*
* Entry: none.
*
* Exit: A set up board and the wild card in the middle.
*
************************************************************************/
void Display::Startup()
{
	system("CLS"); // call here to make background white
	int left = 12;
	int right = 3;
	int top = 3;
	int bottom = 0;

		//Vertical Divider Line
		for (int i(0); i <= MAX_DIVIDER; i++)
		{
			XandY(left, i);
			cout << char(186);
		}
		
		XandY(20, 0);
		left = 20;
		// Vertical lines in playing board
		for (int j(0); j < MAX_VERTICAL_SIZE; j++)
		{
			if (j <= 8) // dislpays # before line
			{
				XandY((left+3), 2);
				cout << char(j + 65);
			}// prints out the lines
			for (int i(3); i <= MAX_VERTICAL_HEIGHT; i++) 
			{
				if (i > 0)
				{
					XandY((left), i);
					cout << char(179);
				}
			}
			left = left + 6;
		}

		XandY(20, 0);
		left = 20; // Horizontal lines in playing board
		for (int j(0); j < MAX_HORIZONTAL_SIZE; j++ )
		{
			XandY(left,top);
			if (j <= 7) // Displays the number next to the line
			{
				XandY((left - 3),(top+2));
				cout << j + 1;
				XandY(left, top);
			}

			for (int i(0); i <= MAX_HORIZONTAL_HEIGHT; i++)
				cout <<  char(196); // ─
			top = top + 3;
		}
		cout << endl;

		Colorsquare(8, 45, 13); // color the middle square
}
/**********************************************************************
* Purpose: This function is to set the x and y coordinates of the passed
*		arugments. 
*
* Entry: A valid x and y coordinate;
*
* Exit: A set cursor position.
*
************************************************************************/
void Display::XandY(int x, int y)
{
	COORD ord;
	ord.X = x;
	ord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ord);
}
/**********************************************************************
* Purpose: This function display the sidebar for a function that 
*			displays the sidebar.
*
* Entry: none.
*
* Exit: Sets the side bar in color with the caludren displayed.
*
************************************************************************/
void Display::SideBar(int passed)
{
	XandY(2, 0);
	SetConsoleTextAttribute(clean, 4 | BACKGROUND_INTENSITY 
		| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	cout << "ALCHEMY ";
	SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY 
		| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	XandY(2, 5);
	cout << "Score\n";
	SetConsoleTextAttribute(clean, 2 | BACKGROUND_INTENSITY 
		| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	// getscore
	cout << m_points;
	SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY 
		| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	XandY(2, 10);
	cout << "Level";
	cout << ' ' << m_level;

	XandY(2, 15);
	cout << "DISCARD\n";
	SetConsoleTextAttribute(clean, 2 | BACKGROUND_INTENSITY 
		| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	for (int i(0); i < 4; i++)
	{
		if ( i < passed)
			SetConsoleTextAttribute(clean, 4 | BACKGROUND_INTENSITY
			| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		cout << "  " << char(176) << char(176) 
			<< char(176) << char(176) << endl;
		SetConsoleTextAttribute(clean, 2 | BACKGROUND_INTENSITY 
			| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	}
	SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY 
		| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

}
/**********************************************************************
* Purpose: This function asks to the user for an X location. A - I
*
* Entry: none.
*
* Exit: Sets the m_X variable for the class.
*
************************************************************************/
char Display::GetXlocation()
{
	bool valid = false;
	while (valid == false )
	{
		XandY(45, 28);
		cout << "PLACE ";

		XandY(45, 29);
		cout << "X:                      ";
		XandY(47, 29);
		cin >> m_X;
		m_X = toupper(m_X);	// make the input upper;

		if (m_X > 'K' || m_X < 'A')
		{
			SetConsoleTextAttribute(clean, 4 | BACKGROUND_INTENSITY 
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			XandY(45, 28);
			cout << "Error:";
			valid = false;
		}
		else
		{
			SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY 
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			valid = true;
		}
		
	}
	return m_X; 
}
/**********************************************************************
* Purpose: This function asks to the user for an Y location. 1-8
*
* Entry: none.
*
* Exit: Sets the m_Y variable for the class.
*
************************************************************************/
int Display::GetYlocation()
{
	bool valid = false;
	while (valid == false)
	{
		XandY(50, 29);

		cout << "Y:       ";
		XandY(52, 29);
		cin >> m_Y;
		if (m_Y <= 0)
		{
			SetConsoleTextAttribute(clean, 4 | BACKGROUND_INTENSITY 
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			XandY(45, 28);
			cout << "Error:";
			valid = false;
		}
		else if (m_Y > 8)
		{
			SetConsoleTextAttribute(clean, 4 | BACKGROUND_INTENSITY
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			XandY(45, 28);
			cout << "Error:";
			valid = false;
		}
		else
		{
			SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY 
				| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
			valid = true;
			XandY(53, 29);
			cout << ' ';
			XandY(48, 29);
			cout << ' ';
		}

	}
	return m_Y; 
}
/**********************************************************************
* Purpose: This function colors in a square on the board
*
* Entry: A color for the sqaure to be, and a position. 
*
* Exit: A colored in square on the board.
*
************************************************************************/
void Display::Colorsquare(int color, int row, int column)
{
	int x = row;		
	int y = column;
	SetConsoleTextAttribute(clean, color | BACKGROUND_INTENSITY);
	for (int i(0); i < 2; i++)
	{
		for (int j(0); j < 5; j++)
		{
			XandY(x, y);
			cout << ' ';
			x++;
		}
		y++;
		x = row;
	}
	SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY 
		| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	XandY(0, 50);
}
/**********************************************************************

* Purpose: This function places a symbol on the board.
*
* Entry: A symbol to be displayed, a color of that symbol,
*		a position(row and column)
*
* Exit: A placed symbol on the board.
*
************************************************************************/
void Display::PlaceSymbol(int symbol, int color, int row, int column)
{
	if (symbol != WILD || symbol != EX)
	{
		XandY(row, column);

		Colorsquare(234, (row - 2), (column - 1));
		SetConsoleTextAttribute(clean, color | 233);
		XandY(row, column);
		cout << char(symbol);
		SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY
			| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		XandY(0, 31);
	}
	else if(symbol == WILD)
		Colorsquare(GREY, (row - 2), (column - 1));
	else
		Colorsquare(234, (row - 2), (column - 1));
}
/**********************************************************************
* Purpose: This function sets a symbol to the a value passed in.
*
* Entry: A valid integer.
*
* Exit: An updated symbol value.
*
************************************************************************/
void Display::setSymbol(int in)
{
	if (in < 0)
		throw "Error: Out of bounds";
	m_symbol = in;

}
/**********************************************************************
* Purpose: This function sets a valid color to the passed.
*
* Entry: A valid integer color.
*
* Exit: An updated symbol color.
*
************************************************************************/
void Display::setColor(int in)
{
	if (in < 0)
		throw "Error: Out of bounds";
	m_color = in;
}
/**********************************************************************
* Purpose: This function returns the score value for the function. 
*
* Entry: none.
*
* Exit: The score value for the class.
*
************************************************************************/
int Display::getScore()
{
	return m_points;
}
/**********************************************************************
* Purpose: This function sets the score.
*
* Entry: A valid integer score.
*
* Exit: An updated score value.
*
************************************************************************/
void Display::setScore(int score)
{
	if (score < 0)
		throw "Error: Score can't be negative";
	else
	{
		m_points = score;

		XandY(2, 5);
		cout << "Score\n";
		SetConsoleTextAttribute(clean, 2 | BACKGROUND_INTENSITY 
			| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		cout << m_points << ' ';
		SetConsoleTextAttribute(clean, 0 | BACKGROUND_INTENSITY 
			| BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	}
}
/**********************************************************************
* Purpose: This function sets the level.
*
* Entry: A valid integer level.
*
* Exit: An updated level.
*
************************************************************************/
void Display::setLevel(int level)
{
	m_level = level;
}
/**********************************************************************
* Purpose: This function is a DTOR.
*
* Entry: none.
*
* Exit: none.
*
************************************************************************/
Display::~Display()
{
}
