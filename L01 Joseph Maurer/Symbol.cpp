#include "Symbol.h"


/**********************************************************************
* Purpose: This function is a constructor for the display class that
*		initilizes the class variables to null.
*
* Entry: none.
*
* Exit: none.
*
************************************************************************/
Symbol::Symbol() : symbol_amount(7), color_amount(5),
				m_symbol(0), m_color(0), m_gold(false)
{}
/**********************************************************************
* Purpose: Copy CTOR manager function.
*
* Entry: Symbol object to be copied.
*
* Exit: none.
*
************************************************************************/
Symbol::Symbol(const Symbol & copy)
{
	// copy over everything
	symbol_amount = copy.symbol_amount;
	color_amount = copy.color_amount;
	m_symbol = copy.m_symbol;
	m_color = copy.m_color;
	m_gold = copy.m_gold;
}
/**********************************************************************
* Purpose: Operator = allows consumer to do s1 = s2
*
* Entry: Symbol object to be copied.
*
* Exit: none.
*
************************************************************************/
Symbol & Symbol::operator=(const Symbol & rhs)
{
	if (this != &rhs)
	{
		symbol_amount = rhs.symbol_amount;
		color_amount = rhs.color_amount;
		m_symbol = rhs.m_symbol;
		m_color = rhs.m_color;
		m_gold = rhs.m_gold;
	}
	return *this;
}
/**********************************************************************
* Purpose: This function generates a symbol for the board.
*
* Entry: none.
*
* Exit: A symbol.
*
************************************************************************/
int Symbol::generateSymbol()
{
	// get a number between 0 and the amount of symbols
	int number = r1.GetRandom(symbol_amount); 

	// case to determine which symbol the random returned
	switch(number)
	{
	case 0:
		m_symbol = THETA;
		m_gold = true;
		break;
	case 1:
		m_symbol = SIGMA;
		m_gold = true;
		break;
	case 2:
		m_symbol = BETA;
		m_gold = true;
		break;
	case 3:
		m_symbol = INFINITY_S;
		m_gold = true;
		break;
	case 4:
		m_symbol = FORTE;
		m_gold = true;
		break;
	case 5: 
		number = r1.GetRandom(symbol_amount);
		// make if less likely to get an X
		if (number < (symbol_amount / 2))
		{
			m_symbol = EX;
			m_gold = true;
		}
		else
		{
			m_symbol = FORTE;
			m_gold = true;
		}
		break;
	case 6:
		number = r1.GetRandom(symbol_amount);
		// make if less likely to get an wild
		if (number > (symbol_amount / 2))
		{
			m_symbol = WILD;
			m_gold = true;
		}
		else
		{
			m_symbol = BETA;
			m_gold = true;
		}
		break;
	case 7: // Level 2 Symbol
		m_symbol = AE;
		m_gold = true;
		break;
	default : 
		m_symbol = THETA;
		m_gold = true;
		break;
	}

	return m_symbol;
}

/**********************************************************************
* Purpose: This function generates a color for the given symbol.
*
* Entry: none.
*
* Exit: A color value.
*
************************************************************************/
int Symbol::generateColor()
{
	// get a number between 0 and the amount of symbols
	int number = r1.GetRandom(color_amount);

	// case to determine which symbol color the random returned
	switch (number)
	{
	case 0:
		m_color = BLUE;
		break;
	case 1:
		m_color = GREEN;
		break;
	case 2:
		m_color = RED;
		break;
	case 3:
		m_color = LIGHT_BLUE;
		break;
	case 4:
		m_color = AQUA;
		break;
	case 5: // Level 2 Color
		m_color = PURPLE;
		break;
	default:
		m_color = BLACK;
		break;
	}

	return m_color;
}
/**********************************************************************
* Purpose: This function sets the symbol passed to the passed value.
*
* Entry: none.
*
* Exit: new symbol value.
*
************************************************************************/
void Symbol::setSymbol(int symbol)
{
	m_symbol = symbol;
	m_gold = true;
}
/**********************************************************************
* Purpose: This function sets the symbol color passed to the passed value.
*
* Entry: none.
*
* Exit: new symbol color value.
*
************************************************************************/
void Symbol::setColor(int color)
{
	m_color = color;
}
/**********************************************************************
* Purpose: This function gets the symbol passed.
*
* Entry: none.
*
* Exit: returned color value.
*
************************************************************************/
int & Symbol::getSymbol()
{
	return m_symbol;
}
/**********************************************************************
* Purpose: This function sets color of the Symbol
*
* Entry: none.
*
* Exit: Returned color value for the passed symbol.
*
************************************************************************/
int & Symbol::getColor()
{
	return m_color;
}
/**********************************************************************
* Purpose: This function sets the amount of symbols in the game
*
* Entry: Valid number of symbols.
*
* Exit: Fixed number of symbols in the game.
*
************************************************************************/
void Symbol::setSymbolAmount(int amount)
{
	symbol_amount = amount;
}
/**********************************************************************
* Purpose: This function sets the amount of colors in the game
*
* Entry: Valid number of colors
*
* Exit: Fixed number of colors in the game.
*
************************************************************************/
void Symbol::setcolorAmount(int amount)
{
	color_amount = amount;
}
/**********************************************************************
* Purpose: This function returns the number of symbols in the level.
*
* Entry: none
*
* Exit: none
*
************************************************************************/
int Symbol::getSymbolAmount()
{
	return symbol_amount;
}
/**********************************************************************
* Purpose: This function returns the number of colors in the level.
*
* Entry: none
*
* Exit: none.
*
************************************************************************/
int Symbol::getcolorAmount()
{
	return color_amount;
}
/**********************************************************************
* Purpose: This function sets the gold attribute of a symbol.
*
* Entry: If you want it set, or not.
*
* Exit: none.
*
************************************************************************/
void Symbol::setGold(bool passed)
{
	m_gold = passed;
}
/**********************************************************************
* Purpose: This function gets the gold attribute of a symbol.
*
* Entry: none.
*
* Exit: m_gold attribute for passed symbol.
*
************************************************************************/
bool Symbol::getifGold()
{
	return m_gold;
}
/**********************************************************************
* Purpose: This function is a DTOR.
*
* Entry: none.
*
* Exit: none.
*
************************************************************************/
Symbol::~Symbol()
{ }
