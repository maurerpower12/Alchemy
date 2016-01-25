/************************************************************************
* Class: Array
*
* Updates:
*		1. The set Length function is now refined to take into account
*		for when going back and forth between shorter and longer lengths.
*
*		2. Made Exception throws more effecient.
*
* Purpose: This class creates a dynamic one-dimensional array that can be
*	 started at any base and will manage the array and throw exceptions
*	 when the bonds of the array are hit.
*
* Manager functions:
* 	Array ( )
* 		The default length is zero and the starting index is zero.
*	Array (int length, int start_index = 0)
*		Creates an appropriate sized array with the starting index
*              either zero or the supplied starting value.
*	Array (const Array & copy)
*		Copy Contructor that will instantiate another array and
*				copy over the data involved with the passed array.
*	operator = (const Array & copy)
*		Transferes the elements of one array into anthor via a deep
*				copy.
*	~Array()
*		Destructor. This manager function deallocates the memory back
*				to the operating system, and resets to nullptr or 0;
*
* Methods:
*	operator [ ] (int index)
*		Allows the consumer to do array[1] in main. Returns the value
*				at the assosiated address.
*	getStartIndex()
*		Returns the start index of the array as an integer.
*	setStartIndex(int start_index)
*		Sets the arrays start_index to the passed parameter.
*	getLength()
*		Returns the length of the passed array as an integer.
*	setLength(int length)
*		Sets the length of the array passed to the value of the integer
*				passed to the function.
*************************************************************************/

#ifndef ARRAY_H
#define ARRAY_H

template<typename T>
class Array
{
public:
	Array<T>();
	Array<T>(int length, int start_index = 0);
	Array<T>(const Array<T> & copy);
	Array<T> & operator=(const Array<T> & rhs);
	T & operator[](int index);
	T & operator[](int index) const;
	const int getStartIndex()const;
	void setStartIndex(int start_index);
	const int getLength()const;
	void setLength(int length);
	~Array<T>();
private:
	T * m_array;
	int m_length;
	int m_start_index;
};
/**********************************************************************
* Purpose: This function is the default CTOR.
*
* Entry: This functions takes nothing.
*
* Exit: This function returns nothing.
*
************************************************************************/
template <typename T>
Array<T>::Array() : m_array(nullptr), m_length(0), m_start_index(0)
{
}
/**********************************************************************
* Purpose: This function is the two arg CTOR.
*
* Entry: This functions takes a length an start index
*
* Exit: This function returns nothing.
*
************************************************************************/
template <typename T>
Array<T>::Array(int length, int start_index) 
			: m_length(length), m_start_index(start_index)
{
	if (length < 0) // Can't have a negative length
		throw Exception("Exception: Can't have a negative Length");
	// allocate new memory for the array at size passed in
	m_array = new T[m_length];
}
/**********************************************************************
* Purpose: This function allows the consumer to instantiate an obj 
*			an have it copy the values to it.
*
* Entry: This functions an object to copy.
*
* Exit: This function returns the array with the copied values.
*
************************************************************************/
template <typename T>
Array<T>::Array(const Array<T> & copy)
{
	// make space for the array at size 
	m_array = new T[copy.m_length];
	m_length = copy.m_length;
	m_start_index = copy.m_start_index;
	//deep copy everything over
	for (int i(0); i < m_length; i++)
	{
		m_array[i] = copy.m_array[i];
	}
}
/**********************************************************************
* Purpose: This function allows the user to do s1 = s2.
*
* Entry: This functions an object to copy.
*
* Exit: This function returns the array with the copied values.
*
************************************************************************/
template <typename T>
Array<T> & Array<T>:: operator=(const Array<T> & rhs)
{
	if (this != &rhs) // check for self assignment
	{
		delete[] m_array; // delete the array we will be writing into
		m_array = nullptr;
		m_length = rhs.m_length;	// set the new lenghth

		if (rhs.m_array != nullptr)
		{
			m_array = new T[rhs.m_length]; // new the memory the array
			for (int i(0); i < m_length; i++) // copy over the goods
				m_array[i] = rhs.m_array[i];
		}
	}
	m_start_index = rhs.m_start_index;
	return *this;
}
/**********************************************************************
* Purpose: This function gets value of the array at that index.
*
* Entry: This functions takes an index.
*
* Exit: This function returns the value of the array at the index.
*
************************************************************************/
template <typename T>
T & Array<T>:: operator[](int index)
{
	// get real index by offset and start
	int real = 0;
	real = index - m_start_index;
	// check if real is less than zero or greater than length of the array
	if (real < 0 || real > m_length)
		throw Exception("Exception: Out of Bounds\n");
	else
		//cout << m_array[real].getSymbol() << '\n';
		return m_array[real];
}
/**********************************************************************
* Purpose: This function gets value of the array at that index.
*
* Entry: This functions takes an index.
*
* Exit: This function returns the value of the array at the index.
*
************************************************************************/
template <typename T>
T & Array<T>:: operator[](int index) const
{
	// get real index by offset and start
	int real = 0;
	real = index - m_start_index;
	// check if real is less than zero or greater than length
	if (real < 0 || real > m_length)
		throw Exception("Exception: Out of Bounds\n");
	else
		return m_array[real];
}
/**********************************************************************
* Purpose: This function gets start_index.
*
* Entry: This functions takes nothing(:
*
* Exit: This function returns the m_start index of the array.
*
************************************************************************/
template <typename T>
const int Array<T>::getStartIndex() const
{
	return m_start_index;
}
/**********************************************************************
* Purpose: This function sets the start index.
*
* Entry: This functions takes a new start index
*
* Exit: This function returns nothing.
*
************************************************************************/
template <typename T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}
/**********************************************************************
* Purpose: This function gets a length.
*
* Entry: This functions takes nothing(:
*
* Exit: This function returns the m_legnth of the array.
*
************************************************************************/
template <typename T>
const int Array<T>::getLength()const
{
	return m_length;
}
/**********************************************************************
* Purpose: This function allows the user to set the length of the array.
*
* Entry: This functions takes a new length.
*
* Exit: This function returns an updated array.
*
************************************************************************/
template <typename T>
void Array<T>::setLength(int length)
{
	if (length < 0) // Can't have a negative lengths
		throw Exception("Exception: Length is invalid");
	else
	{
		///////////* Updated copy *///////////////
		T * temp = new T[length];
		if (length < m_length) // case for shorter array
		{
			for (int i(0); i < length; i++)
				temp[i] = m_array[i];
		}
		else // case for greater than array
		{
			for (int i(0); i < m_length; i++)
				temp[i] = m_array[i];
		}
		delete[] m_array;
		m_array = temp;
		////////////* Updated copy *////////////////

		m_length = length;
	}

}
/**********************************************************************
* Purpose: This function is a DTOR.
*
* Entry: This functions takes nothing.
*
* Exit: This function returns nothing.
*
************************************************************************/
template <typename T>
Array<T>::~Array()
{
	delete[] m_array;
	m_array = nullptr;
	m_length = 0;
	m_start_index = 0;
}
#endif 
