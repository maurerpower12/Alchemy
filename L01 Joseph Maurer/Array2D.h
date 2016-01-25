/************************************************************************
* Class: Array2D
*
* Purpose: The purpose of this class is to act as a wrapper class for
*		the Array class built earlier in the term. Essentially this
*		class allows the additional functionality to render a 2D Array.
*
* Manager functions:
* 	Array2D();
*		Default contructor, everything to default values
*	Array2D(int row, int column = 0);
*		Two arg ctor that sets to values passed in.
*	Array2D(const Array2D & copy);
*		Copy constructor
*	~Array2D();
*		DTOR
*	Array2D & operator=(const Array2D & rhs);
*		Op = to allow consumer to do a1 = a2.
*
* Methods:
*	Row<T> operator[](int index);
*		overloaded bracket operators so you can do this ra[9][11]
*	const Row<T> operator[](int index) const;
*		const method for the overloaded breacket operators
*	int getRow() const;
*		returns the number of rows in the array.
*	void setRow(int rows);
*		sets the number of rows in the array.
*	int getColumn() const;
*		gets the number of columns in the array.
*	void setColumn(int columns);
*		sets the number of columns in the array.
*	T & Select(int row, int column);
*		Preforms an algorithm in order to deduce the array position
*		in a 1D array versus a 2D array.
*	T & Select(int row, int column) const;
*		Const method that preforms an algorithm in order to deduce the
*		array position in a 1D array versus a 2D array.
*************************************************************************/
#ifndef ARRAY2D
#define ARRAY2D
#include "Array.h"
#include "Exception.h"
#include "Row.h"

template <typename T>
class Array2D
{
public:
	// Canonical Methods
	Array2D();
	Array2D(int row, int column = 0);
	Array2D(const Array2D & copy);
	~Array2D();
	Array2D & operator=(const Array2D & rhs);

	//Other Methods
	Row<T> operator[](int index);
	const Row<T> operator[](int index) const;
	int getRow() const;
	void setRow(int rows);
	int getColumn() const;
	void setColumn(int columns);
	T & Select(int row, int column);
	T & Select(int row, int column) const;

private:
	Array<T> m_array;
	int m_row;
	int m_col;
};

/**********************************************************************
* Purpose: This function is the default CTOR.
*
* Entry: This functions takes no arguments.
*
* Exit: This function returns nothing.
*
************************************************************************/
template <typename T>
Array2D<T>::Array2D() : m_array(Array<T>()), m_row(0), m_col(0)
{

}
/**********************************************************************
* Purpose: This function is the two arg CTOR.
*
* Entry: This functions takes a row and column.
*
* Exit: This function returns nothing.
*
************************************************************************/
template <typename T>
Array2D<T>::Array2D(int row, int column)
	: m_array(Array<T>()), m_row(row), m_col(column)
{
	if (row < 0 || column < 0)
		throw Exception("Can't have a negative row or column ~CTOR");
	m_array = Array<T>((row*column));
}
/**********************************************************************
* Purpose: This function is a copy CTOR.
*
* Entry: This functions takes an Array2D obj to copy.
*
* Exit: This function returns a new Array2D object with the copied data.
*
************************************************************************/
template <typename T>
Array2D<T>::Array2D(const Array2D & copy)
{
	*this = copy; // call op =
}
/**********************************************************************
* Purpose: This function is a DTOR.
*
* Entry: This functions takes no arguments.
*
* Exit: This function returns nothing.
*
************************************************************************/
template <typename T>
Array2D<T>:: ~Array2D()
{
	m_row = 0;
	m_col = 0;
}
/**********************************************************************
* Purpose: This function is the operator=. manager function.
*
* Entry: This functions takes an Array2D to copy.
*
* Exit: This function returns a new Array2D object.
*
************************************************************************/
template <typename T>
Array2D<T> & Array2D<T>::operator=(const Array2D<T> & rhs)
{
	if (this != &rhs) // check for self assignment
	{
		m_row = rhs.m_row;	// reassign everything over
		m_col = rhs.m_col;
		m_array = rhs.m_array; // No need for a deep copy
	}
	return *this;
}
/**********************************************************************
* Purpose: This function allows for m_array[] to return a value.
*
* Entry: This functions takes an index.
*
* Exit: This function returns a row by reference.
*
************************************************************************/
template <typename T>
Row<T> Array2D<T>::operator[](int index)
{
	if (index < 0) // negative start index
		throw Exception("Exception: Can't be negative: ~op[]");
	else if (index > m_row)
		throw Exception("Exception: Out of Bounds: ~op[]");
	else
		return Row<T>(*this, index);
}
/**********************************************************************
* Purpose: This function allows for m_array[] to return a value.
*
* Entry: This functions takes an index.
*
* Exit: This function returns a row by reference.
*
************************************************************************/
template <typename T>
const Row<T> Array2D<T>::operator[](int index) const
{
	if (index < 0) // negative start index
		throw Exception("Exception: Can't be negative: ~op[]const ");
	else if (index > m_row)
		throw Exception("Exception: Out of Bounds: ~op[] const ");
	else
		return Row<T>(*this, index);
}
/**********************************************************************
* Purpose: This function gets a row value.
*
* Entry: This functions takes nothing.
*
* Exit: This function returns a row.
*
************************************************************************/
template <typename T>
int Array2D<T>::getRow() const
{
	return m_row;
}
/**********************************************************************
* Purpose: This function sets a row value.
*
* Entry: This functions takes new row value.
*
* Exit: This function returns nothing.
*
************************************************************************/
template <typename T>
void Array2D<T>::setRow(int rows)
{
	if (rows < 0)
		throw Exception("Exception: Can't have a negative ROW! ~ setRow");
	m_array.setLength(rows * m_col); // resize the array, chop off the end
	m_row = rows; // assign it
}
/**********************************************************************
* Purpose: This function gets a column value.
*
* Entry: This functions takes nothing.
*
* Exit: This function returns a column.
*
************************************************************************/
template <typename T>
int Array2D<T>::getColumn() const
{
	return m_col;
}
/**********************************************************************
* Purpose: This function sets a column value.
*
* Entry: This functions takes new column value.
*
* Exit: This function returns nothing.
*
************************************************************************/
template <typename T>
void Array2D<T>::setColumn(int columns)
{
	if (columns < 0) //negative start index
		throw
		Exception("Exception: Can't set column length to a negative");
	else
	{
		Array<T> temp((columns * m_row));
		if (columns > m_col)
		{
			for (int i(0); i < m_row; i++)
			{
				for (int a(0); a < m_col; a++)
				{
					temp[((columns * i) + a)] = m_array[((m_col * i) + a)];
				}
			}
		}
		else
		{
			for (int i(0); i < m_row; i++)
			{// only iterate to the new column length
				for (int a(0); a < columns; a++)
				{
					temp[((columns * i) + a)] = m_array[((columns * i) + a)];
				}
			}
		}
		m_array = temp;			//point to the temp you just made
		m_col = columns;
	}
}
/**********************************************************************
* Purpose: This function helps with going from a 2D array to a 1D
*		array in memory.
*
* Entry: This functions takes row and column value.
*
* Exit: This function returns the value at that location in memory.
*
************************************************************************/
template <typename T>
T & Array2D<T>::Select(int row, int column)
{
	if (row > m_row || column > m_col)
		throw Exception("Exception: Out of bounds~Select");
	else if (row < 0 || column < 0)
		throw Exception("Exception: Can not be a negative index ~Select");
	else
		return m_array[((m_col * row) + column)];
}
/**********************************************************************
* Purpose: This function helps with going from a 2D array to a 1D
*		array in memory.
*
* Entry: This functions takes row and column value.
*
* Exit: This function returns the value at that location in memory.
*
************************************************************************/
template <typename T>
T & Array2D<T>::Select(int row, int column) const
{
	if (row > m_row || column > m_col)
		throw Exception("Exception: Out of bounds ~Select const ");
	else if (row < 0 || column < 0)
		throw Exception("Exception: Can not be a negative index ~Select const ");
	else
		return m_array[((m_col * row) + column)];
}
#endif 
