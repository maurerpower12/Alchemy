/************************************************************************
* Class: Cauldren
*
* Purpose: This class is used to control the discard pile on the 
*		left side of the screen during the game. It manages and
*		controls the variables involved.
*
* Manager functions:
*	Cauldren()
*		Defaults the values of the class variables.
*	Cauldren(const Cauldren & copy);
*		Copy CTOR .
*	Cauldren & operator=(const Cauldren & rhs);
*		Allows you to be like d1 = d2
*	~Cauldren();
*		Deallocates memory back to the operating system.
*
* Methods:
* 	
*************************************************************************/
#ifndef CAULDREN_H
#define CAULDREN_H
#include <iostream>
#include "Display.h"
#include "Exception.h"
class Cauldren
{
public:
	//manager things
	Cauldren();
	Cauldren(const Cauldren & copy);
	Cauldren & operator=(const Cauldren & rhs);
	~Cauldren();

	void EndGameCheck(char x, int y);
	void setDiscard(int passed);
	int getDiscard();
	
private:
	Display d1;
	int m_discard;
};

#endif