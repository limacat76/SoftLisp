#include "stdafx.h"
#include "System.h"


// This is an example of an exported function.
SOFTLISP_API int fnLibrary()
{
    return 42;
}

/*
// This is an example of an exported variable
SOFTLISP_API int nLibrary = 0;

// This is the constructor of a class that has been exported.
// see ConsoleApplication1.h for the class definition
CConsoleApplication1::CConsoleApplication1()
{
    return;
}
*/