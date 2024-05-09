#include <iostream>

#include "Debug.h"

bool criticalError(std::string msg)
{
    std::cerr << msg << std::endl;
    return false;
}