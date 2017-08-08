// ConsoleApplication1.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Library.h"


// This is an example of an exported variable
CONSOLEAPPLICATION1_API int nLibrary=0;

// This is an example of an exported function.
CONSOLEAPPLICATION1_API int fnLibrary()
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see ConsoleApplication1.h for the class definition
CConsoleApplication1::CConsoleApplication1()
{
    return;
}
