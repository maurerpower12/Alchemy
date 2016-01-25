/************************************************************************
* Class: Display
*
* Purpose: This class is used to control the display aspect of the program.
*		Upon startup this class takes over and controls where things are 
*		placed by setting the cursor position.
*
* Manager functions:
*	Display()
*		Defaults the values of the class variables.
*	Display(const Display & copy);
*		Copy CTOR .
*	Display & operator=(const Display & rhs);
*		Allows you to be like d1 = d2
*	~Display();
*		Deallocates memory back to the operating system.
*
* Methods:
* 	void Startup();
*		Function that diplays the board to start game.
*	void XandY(int x, int y);
*		Sets the cursor position.
*	void SideBar(int passed);
*		Displays the side bar of the program.
*	char GetXlocation();
*		Gets input from the user.
*	int GetYlocation();
*		Gets input from the user.
*	void Colorsquare(int color, int row, int column)
*		Colors in a square on the board.
*	void PlaceSymbol(int symbol, int color, int row, int column);
*		Places a symbol on the board.
*	void setSymbol(int in);
*		Sets a symbol.
*	void setColor(int in);
*		Sets the color of a symbol
*	int getScore();
*		Gets the score of the game.
*	void setScore(int score);
*		Sets the score. 
*************************************************************************/
#ifndef DISPLAY_H
#define DISPLAY_H

#include "Symbol.h"
#include <windows.h> // needed to display symbols color
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <conio.h>
	using std::cout;
	using std::cin;
	using std::endl;

class Display
{
public:
	//Manager Functions
	Display();
	Display(const Display & copy);
	Display & operator=(const Display & rhs);
	~Display();

	void Startup();
	void XandY(int x, int y);
	void SideBar(int passed);
	char GetXlocation();
	int GetYlocation();
	void Colorsquare(int color, int row, int column);
	void PlaceSymbol(int symbol, int color, int row, int column);
	void setSymbol(int in);
	void setColor(int in);
	int getScore();
	void setScore(int score);
	void setLevel(int level);
	
private:

	Symbol s1;
	char m_X;
	int m_Y;
	int m_symbol;
	int m_color;
	int m_points;
	int m_level;
};
#endif
