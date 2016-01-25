/************************************************************************
* Class: Symbol
*
* Purpose: This class is used to control the generation of the symbols
*		used to place on the board.
*
* Manager functions:
*	Symbol()
*		Defaults the values of the class variables.
*	~Symbol();
*		Deallocates memory back to the operating system.
*
* Methods:
*  	int generateSymbol();
*		Generate a symbol for a given class
*	int generateColor();
*		Generate a Color for a symbol.
*	int & getSymbol();
*		Gets a symbol integer value.
*	int & getColor();
*		Gets a color integer value.
*	void setSymbol(int symbol);
*		Sets the symbol to a certain value.
*	void setColor(int color);
*		Sets the color of the symbol.
*************************************************************************/
#ifndef SYMBOL_H
#define SYMBOL_H
#include "Rank.h"

#include "Random.h"
class Symbol
{
public:
	Symbol();
	Symbol(const Symbol & copy);
	Symbol & operator=(const Symbol & rhs);
	~Symbol();


	int generateSymbol();
	int generateColor();
	int & getSymbol();
	int & getColor();
	void setSymbol(int symbol);
	void setColor(int color);
	void setSymbolAmount(int amount);
	void setcolorAmount(int amount);
	int getSymbolAmount();
	int getcolorAmount();
	void setGold(bool passed);
	bool getifGold();
	
private: 
	Random r1;
	bool m_gold;
	int symbol_amount;
	int color_amount;
	int m_symbol;
	int m_color;
};
#endif
