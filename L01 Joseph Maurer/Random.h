/************************************************************************
* Class: Random
* Overview:
*	Used for randomly generating values. 
* Constructors:
*	Random()
*		Seed for random-number generation.
*
* Mutators:
*	None.
*
* Methods:
*	unsigned GetRandom(int n) const
*		Returns a random integer using time as a standard.
*
*************************************************************************/
#ifndef RANDOM_H
#define RANDOM_H
#include <cstdlib>
#include <ctime>

class Random
{
public:
	Random()
	{ // Seed for random-number generation 
		srand(static_cast<unsigned> (time(0)));
	}
	unsigned GetRandom(int n) const
	{
		return rand() % n;
	}
};
#endif