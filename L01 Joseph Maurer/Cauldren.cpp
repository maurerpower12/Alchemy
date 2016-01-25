#include "Cauldren.h"
HANDLE clear = GetStdHandle(STD_OUTPUT_HANDLE);

/**********************************************************************
* Purpose: This function is the default CTOR
*
* Entry: This functions takes no arguments.
*
* Exit: This function returns nothing.
*
************************************************************************/
Cauldren::Cauldren() : m_discard(0)
{
}
/**********************************************************************
* Purpose: This function checks for an overflow in the cauldren or
*		discard portion of the game.
*
* Entry: This functions takes an Row and Column insert by the user.
*
* Exit: This function returns an updated Cauldren.
*
************************************************************************/
void Cauldren::EndGameCheck(char x, int y)
{
	if (x == int('J') && y == 1)
	{
		m_discard++;
		// Clear error message
		d1.XandY(20, 30);
		cout << "                            ";
		// update side bar
		d1.SideBar(m_discard);
	}
	if (m_discard == 4)
	{
		system("CLS");
		SetConsoleTextAttribute(clear, 4 | BACKGROUND_INTENSITY |
			BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
		d1.XandY(30, 10);
		throw Exception("Cauldren is full! Game Over!\n\n\n\n");
		system("pause");
	}
	else if (m_discard < 0)
		throw Exception("Caludren can NOT be negative!");
}
/**********************************************************************
* Purpose: This function sets the discard amount of the class.
*
* Entry: This functions takes an integer amount to discard;
*
* Exit: This function returns nothing.
*
************************************************************************/
void Cauldren::setDiscard(int passed)
{
	if (passed < 0) // throw an exception is out of bounds
		throw "Exception: Discard can not be negative!";
	else
		m_discard = passed;
}
/**********************************************************************
* Purpose: This function gets the dicard amount. 
*
* Entry: This functions takes no arguments.
*
* Exit: This function returns the discard amount.
*
************************************************************************/
int Cauldren::getDiscard()
{
	return m_discard;
}
/**********************************************************************
* Purpose: This function is the copy ctor. 
*
* Entry: This functions takes a copy Cauldren object.
*
* Exit: This function returns nothing.
*
************************************************************************/
Cauldren::Cauldren(const Cauldren & copy)
{
	m_discard = copy.m_discard;
}
/**********************************************************************
* Purpose: This function is an operator=. Aloows the user to do a1= b1;
*
* Entry: This functions takes an object on the right hand side.
*
* Exit: This function returns a new Caludren object.
*
************************************************************************/
Cauldren & Cauldren::operator=(const Cauldren & rhs)
{
	if (this != & rhs)
		m_discard = rhs.m_discard;
	return *this;
}
/**********************************************************************
* Purpose: This function is a DTOR. 
*
* Entry: This functions takes no arguments.
*
* Exit: This function returns nothing.
*
************************************************************************/
Cauldren::~Cauldren()
{
}
