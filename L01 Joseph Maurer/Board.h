/************************************************************************
* Class: Board
*
* Purpose: This class is used to control the Alchemy board and the 
*		varaiables associated with it.
*
* Manager functions:
*	Board()
*		Sets the default values for the class.
*	~Board()
*		Deallocates the memory back to operating system.
*	Board(const Board & copy);
*		Copy CTOR that will instantiate another array and
*		copy over the data involved with the passed Board.
*	Board & operator=(const Board & rhs);
*		Copy over data. Allows for b1 = b2.
* Methods:
*  	void PlaceSymbol();
*		Places a symbol on the board.		
*	Symbol & getSymbol(int row, int col);
*		Gets a symbol at a position in the array.
*	void PlaceArray(int col, char row, Symbol symbol);
*		Places an element in the array.
*************************************************************************/
#ifndef BOARD_H
#define BOARD_H

#include "Display.h"
#include "Symbol.h"
#include "Array2D.h"
#include "Exception.h"

class Board
{
public:
	//Manager Functions
	Board();
	Board(const Board & copy);
	Board & operator=(const Board & rhs);
	~Board();

	void PlaceSymbol(char row, int col, Symbol symbol);
	Symbol & getSymbol(int row, int col);
	void PlaceArray(int col, char row, Symbol symbol);
	

private:
	Display d1;
	Symbol s1;
	Array2D<Symbol> m_array;

	int m_symbol;
	int m_color;
	int m_discard;
};
#endif
