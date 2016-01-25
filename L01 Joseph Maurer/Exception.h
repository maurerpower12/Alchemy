/************************************************************************
* Class: Exception
*
* Purpose: This class was created to handle the methods and transfere
*		of data with regards to exception handleing. For example,
*		when an exception is found, an exception object is created
*		and passed the string that needs to be displayed. This object
*		is then used in the catch block.
*
* Manager functions:
* 	Exception ( )
* 		The default message to nullptr.
*	Exception (char * msg)
*		Creates a dynamically allocated message with passed string.
*	Exception (const Exception & copy)
*		Creates a dynamically allocated message with passed string.
*	operator=(const Exception & rhs)
*		Transferes the elements of one array into anthor via a deep
*			copy.
*	~Exception()
*		Destructor. This manager function deallocates the memory back
*				to the operating system, and resets to nullptr or 0;
*
*
* Methods:
*	const char * getMessage()const
*		Returns the message of the passed Exception object.
*	void setMessage(char * msg);
*		Sets the message of the calling object to the passed message.
*	ostream & operator << (ostream & stream, const Exception & except)
*		This allows the user to do cout << exception_object.
*************************************************************************/
#ifndef EXCEPTION_H
#define EXCEPTION_H

#define _CRT_SECURE_NO_WARNINGS 
#include <ostream>
using std::ostream;

class Exception
{
public:
	friend ostream & operator << (ostream & stream, const Exception & except);
	Exception();
	Exception(char * msg);
	Exception(const Exception & copy);
	~Exception();
	Exception & operator=(const Exception & rhs);
	const char * getMessage()const;
	void setMessage(char * msg);
private:
	char * m_msg;
};
#endif



