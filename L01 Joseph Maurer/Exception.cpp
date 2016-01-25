#include "Exception.h"

/**********************************************************************
* Purpose: This function is a sijmple CTOR.
*
* Entry: This functions takes no arguments.
*
* Exit: This function returns nothing.
*
************************************************************************/
Exception::Exception() : m_msg(nullptr)
{
}

/**********************************************************************
* Purpose: This function is a one arg CTOR.
*
* Entry: This functions takes a message to be displayed.
*
* Exit: This function returns nothing.
*
************************************************************************/
Exception::Exception(char * msg)
{
	m_msg = new char[strlen(msg) + 1];
	strcpy(m_msg, msg);
}
/**********************************************************************
* Purpose: This function is a copy CTOR.
*
* Entry: This functions takes no arguments.
*
* Exit: This function returns nothing.
*
************************************************************************/
Exception::Exception(const Exception & copy)
{
	m_msg = new char[strlen(copy.m_msg) + 1];
	strcpy(m_msg, copy.m_msg);
}
/**********************************************************************
* Purpose: This function allows the user to do a1 = a2.
*
* Entry: This functions takes an Exception to copy.
*
* Exit: This function returns a new Exception object.
*
************************************************************************/
Exception & Exception::operator=(const Exception & rhs)
{
	if (this != &rhs) // Check for self assignment
	{ // check if the string lengths are the same
		if (strlen(m_msg) != strlen(rhs.m_msg)) 
		{
			delete[] m_msg;
			m_msg = new char[strlen(rhs.m_msg) + 1];
		}
		strcpy(m_msg, rhs.m_msg); 
		// copy over the data: shallow copy
	}
	return *this;
}
/**********************************************************************
* Purpose: This function gets a message.
*
* Entry: This functions takes nothing.
*
* Exit: This function returns m_msg.
*
************************************************************************/
const char * Exception::getMessage() const
{
	return m_msg;
}
/**********************************************************************
* Purpose: This function sets the message to whatever you pass it.
*
* Entry: This functions takes an char pointer.
*
* Exit: This function returns nothing.
*
************************************************************************/
void Exception::setMessage(char * msg)
{
	m_msg = new char[strlen(msg) + 1]; //Deep Copy 
	strcpy(m_msg, msg);
}
/**********************************************************************
* Purpose: This function allows the user to do cout an exception
*
* Entry: This functions takes an Exception object.
*
* Exit: This function returns a ostream.
*
************************************************************************/
ostream & operator<< (ostream & stream, const Exception & except)
{
	stream << except.m_msg;
	return stream;
}
/**********************************************************************
* Purpose: This function is a DTOR.
*
* Entry: This functions take nothing.
*
* Exit: This function returns nothing.
*
************************************************************************/
Exception::~Exception()
{
	delete[] m_msg;
	m_msg = nullptr;
}
