// Access to std::cout and std::endl
#include <iostream>

// DECLDIR will perform an export for us
#define DLL_EXPORT

// Include our header, must come after #define DLL_EXPORT
#include "dll_tutorial.h"

// Get rid of name mangeling
extern "C"
{
	// Define our 2 functions
	// Add will return the sum of two numbers
	DECLDIR int Add( int a, int b )
	{
		return( a + b );
	}

	// Function will print out a text string
	DECLDIR void Function( void )
	{
		std::cout << "DLL Called!" << std::endl;
	}
}