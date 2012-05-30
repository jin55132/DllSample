// LOADING DLLS THE HARD(ER) WAY (Dynamic Loading)
#include <iostream>
// Need Windows.h for HINSTANCE and DLL Loading and Releasing functions.
#include <windows.h>

// Function pointers that will be used for the DLL functions.
typedef int (*AddFunc)(int,int);
typedef void (*FunctionFunc)();

// Must have a main function
int main()
{
	// Typedef functions to hold what is in the DLL
	AddFunc _AddFunc;
	FunctionFunc _FunctionFunc;
	// The Instance of the DLL.
	// LoadLibrary used to load a DLL
	HINSTANCE hInstLibrary = LoadLibrary( L"myDLL.dll");

	if (hInstLibrary)
	{
		// Our DLL is loaded and ready to go.

		// Set up our function pointers.
		_AddFunc = (AddFunc)GetProcAddress(hInstLibrary, "Add");
		_FunctionFunc = (FunctionFunc)GetProcAddress(hInstLibrary, "Function");
		_AddFunc = (AddFunc)GetProcAddress(hInstLibrary, "ASDF");

		// Check if _AddFunc is currently holding a function, if not don't run it.
		if (_AddFunc)
		{
			std::cout << "23 = 43 = " << _AddFunc(23, 43) << std::endl;
		}
		// Check if _FunctionFunc is currently holding a function, if not don't run it.
		if (_FunctionFunc)
		{
			_FunctionFunc();
		}

		// We're done with the DLL so we need to release it from memory.
		FreeLibrary(hInstLibrary);
	}
	else
	{
		// Our DLL failed to load!
		std::cout << "DLL Failed To Load!" << std::endl;
	}

	// Wait for the user to press enter to exit
	std::cin.get();

	return 0;
}