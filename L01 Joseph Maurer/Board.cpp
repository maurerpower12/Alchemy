#include "Board.h"
HANDLE windex = GetStdHandle(STD_OUTPUT_HANDLE);

/**********************************************************************
* Purpose: This function is a constructor for the display class that
*		initilizes the class variables to null.
*
* Entry: none.
*
* Exit: A symbol placed in the Array at the center location.
*
************************************************************************/
Board::Board() : m_array(Array2D<Symbol>(8, 9)),
		m_symbol(0), m_color(0), m_discard(0)
{
	s1.setSymbol(168); // set the symbol to a WILD
	PlaceArray(4, 'E', s1); // place in the middle of the board
}

/**********************************************************************
* Purpose: This function is places any element into the array. It acts a 
*		driver calling the nessassary functions at the correct times.
*
* Entry: none.
*
* Exit: Am element placed into the array at the correct location.
*
************************************************************************/
void Board::PlaceSymbol(char row, int col, Symbol symbol)
{
	int rows = row - 65;
	col--;
	m_array[col][rows] = symbol;

}

/**********************************************************************
* Purpose: This function is gets an element at a specific location.
*
* Entry: A valid location to place an element.
*
* Exit: Symbol at a location.
*
************************************************************************/
Symbol & Board::getSymbol(int row, int col)
{
	return m_array[col][row];
}

/**********************************************************************
* Purpose: This function places an element in memory at a location.
*
* Entry: The location in memory of an element.
*
* Exit: Elements in memory.
*
************************************************************************/
void Board::PlaceArray(int col, char row, Symbol symbol)
{
	int rows = row - 65;				
	col--;
	m_array[col][rows] = symbol;
}

/**********************************************************************
* Purpose: This function copies over data when constructing a new 
*			Board
*
* Entry: The location of the data to copy.
*
* Exit: This functions returns a new board witht the copied data.
*
************************************************************************/
Board::Board(const Board & copy)
{
	m_array = copy.m_array;
	m_symbol = copy.m_symbol;
	m_color = copy.m_color;
	m_discard = copy.m_discard;
}

/**********************************************************************
* Purpose: This function copies over data when constructing a new
*			Board
*
* Entry: The location of the data to copy.
*
* Exit: This functions returns a new board witht the copied data.
*
************************************************************************/
Board & Board::operator=(const Board & rhs)
{
	if (this != &rhs)
	{
		m_symbol = rhs.m_symbol;
		m_color = rhs.m_color;
		m_discard = rhs.m_discard;
	}
	return *this;
}
/**********************************************************************
* Purpose: This function deallocates memory back to the OS>
*
* Entry: This functions takes nothing.
*
* Exit: This functions returns nothing.
*
************************************************************************/
Board::~Board()
{}
