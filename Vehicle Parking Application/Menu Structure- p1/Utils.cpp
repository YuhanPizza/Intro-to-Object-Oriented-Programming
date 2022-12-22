/***********************************************************************
// Utils Module
// File  utils.cpp
// Version 0.0
// Date
// Author
// Description
// Estra Classes and functions needed in the project
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "Utils.h"
#include <iostream>

namespace sdds
{
    void clearBuffer()
    {
        while (getchar() != '\n')
            ;
        std::cin.clear();
    };
}