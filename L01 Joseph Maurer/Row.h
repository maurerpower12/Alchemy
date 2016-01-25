/************************************************************************
* Class: Row
*
* Purpose: The purpose of this class is to hold the row information
*		for a 2D array. This function is able to hold const methods
*		along with functions to hold any type of data.
*
* Manager functions:
* 	Row<T>(Array2D<T> & t_array, int row)
*			Default constructor that initilizes everything to default
*	Row<T>(const Array2D<T> & t_array, int row);
*			Two arg ctor to set data to passed information.
*	T & operator[](int column)
*			Error checks than call the Select function of the 2D array.
*			returns that spot in the array
*	T & operator[](int column) const
*			Const method that does the exact same thing.
*************************************************************************/
#ifndef ROW_H
#define ROW_H
#include "Exception.h"
template <typename T>
class Row
{
	template <typename T>
	friend class Array2D;

public:
	Row<T>(Array2D<T> & t_array, int row);
	Row<T>(const Array2D<T> & t_array, int row);

	T & operator[](int column);
	T & operator[](int column) const;
private:
	Array2D<T> & m_array2D;
	int m_row;
};

/**********************************************************************
* Purpose: This function is a two arg CTOR. 
*
* Entry: This function takes a array and a integer value for row.
*
* Exit: none.
*
************************************************************************/
template <typename T>
Row<T>::Row(Array2D<T> & t_array, int row) : m_array2D(t_array), m_row(row)
{

}
/**********************************************************************
* Purpose: This function is a two arg CTOR.
*
* Entry: This function takes a array and a integer value for row.
*
* Exit: none.
*
************************************************************************/
template <typename T>
Row<T>::Row(const Array2D<T> & t_array, int row) : m_array2D(const_cast<Array2D<T>&>(t_array)), m_row(row)
{

}
/**********************************************************************
* Purpose: This function allows the user to array[] to access the array.
*
* Entry: A column that you want to access.
*
* Exit: This function returns a value at the column value passsed.
*
************************************************************************/
template <typename T>
T & Row<T>::operator[](int column)
{
	if (column < 0)
		throw Exception("Exception: Can't have a negative column length: ~Row op []");
	return m_array2D.Select(m_row, column);
}
/**********************************************************************
* Purpose: This function allows the user to array[] to access the array.
*
* Entry: A column that you want to access.
*
* Exit: This function returns a value at the column value passsed.
*
************************************************************************/
template <typename T>
T & Row<T>::operator[](int column) const
{
	if (column < 0)
		throw Exception("Exception: Can't have a negative column length: ~Row op [] const");
	return m_array2D.Select(m_row, column);
}

#endif