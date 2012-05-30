// Loading DLLs The Easy Way
#include <iostream>
// We need the DLL_Tutorial.h header to access its functions
#include "../myDll/DLL_Tutorial.h"

int main()
{
	std::cout << Add(23, 43) << std::endl; // call and print the result of Add() from DLL
	Function();     // call Function() from DLL

	std::cin.get(); // Wait for input to prevent opening then closing immediatly

	return(1); // return success
}