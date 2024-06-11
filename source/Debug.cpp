#include "Debug.h"

void debug(std::vector<std::string> vector)
{
    for (std::vector<std::string>::size_type i = 0; i < vector.size(); i++)
    {
        std::cout << " " << vector[i] << std::endl;
    }
}