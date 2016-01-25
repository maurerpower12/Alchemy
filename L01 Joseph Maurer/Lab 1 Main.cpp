/***********************************************************
* Author:			Joseph Maurer
* Lab Number:		CST 211 Lab 01
* Filename:			Lab 1 Main.cpp
* Date Created:		04/10/15
* Modifications:
*
* Overview:
*	This program's purpose is play the game Alchemy. Which
*	generates a random symbol and color. Your job is to match 
*	up symbols and colors on the board by entering x and y 
*	coordinates. To discard enter J and 1. After 4 discards,
*	the game is over. There are two levels.
*
*
* Input:
*	The input should consist of an X and Y coordinate.
*	X being A - I and Y being 1 - 8
*
* Output:
*	The output of this program will be a board in which
*	the user needs to input values to place symbols in 
*	valid squares. For output examples, please look in the 
*	project file.
************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <iostream>
using std::cout;

#include <windows.h>
#include <mmsystem.h>
#include "Display.h"
#include "Rank.h"
#include "Cauldren.h"
#include "Board.h"
#include "Alchemy.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	HWND console = GetConsoleWindow();
	RECT r;
	//gets the console's dimensions
	GetWindowRect(console, &r); 
	//moves window to full screen-ish
	MoveWindow(console, 0, 0, 1000, 600, TRUE); 

	Display d1;
	Alchemy a1;
	d1.Startup();
	d1.SideBar(0);
	a1.RunGame();

	return 0;
}
