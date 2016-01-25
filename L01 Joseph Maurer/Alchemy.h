/************************************************************************
* Class: Alchmey
*
* Purpose: This class is used to control the game logic involoved with
*		Playing the game. For example, upon start up, the game will
*		setup everything involved with the array. 
*
* Manager functions:
*	Alchemy()
*		Defaults the values of the class variables.
*	~Alchemy()
*		Deallocates memory back to the operating system.
*
* Methods:
*	void RunGame()
*		makes the wheels turn and keeps the lights on, calls everything.
* 	bool isValid(int col, int row, Symbol & s1)
*		This function either returns true or false based off if the 
*		move passed in was a valid move.
* 	bool Check(Symbol s1, int row, int col)
*		Used in conjunction with is valid. Finds if valid.	
*	int scoreboard(int col, int row, Symbol & s1)
*		Used in calulating the score.
*	int scoreboard_counter(int col, int row, Symbol & s1)
*		Used in calulating the score.
*	void checkgold()
*		Checks for a row or column to be gold
*	bool checkallzero(int col, int row)
*		Checks for all zeros around a tile.
*	bool checkwingame();
*		Checks for gold board.
*	int getScore();
*		returns m_points for the class variable.
*	void wingame();
*		gets you to the next level of the game.
*	void testlevelup();
*		fills the board so all you have to do is place one symbol.
*************************************************************************/
#ifndef ALCHEMY_H
#define ALCHEMY_H

#include "Array2D.h"
#include "Display.h"
#include "Board.h"
#include "Symbol.h"
#include "Cauldren.h"
class Board; // forward declaration
class Alchemy
{
public:
	//manager functions
	Alchemy();
	Alchemy(const Alchemy & copy);
	Alchemy & operator=(const Alchemy & rhs);
	~Alchemy();


	void RunGame();
	bool isValid(int col, int row, Symbol & s1);
	bool Check(Symbol s1, int row, int col);
	void NextUp();
	void scoreboard(int col, int row, Symbol  s1);
	void scoreboard_counter(int col, int row, Symbol s1);
	bool checkgold(int row, char col);
	bool checkallzero(int col, int row);
	bool checkwingame();
	int getScore();
	void wingame();
	void testlevelup();
	
private:
	Display d1;
	Board b1;
	Cauldren c1;
	Symbol s1;

	int m_row;
	char m_col;

	bool m_valid;
	int m_points;
	bool m_start;
};
#endif
