#include <iostream>
#include "iter.hpp"



int main(void)
{
    int intArray[5] = {1, 2, 3, 4, 5};
    std::cout << "Integer array:" << std::endl;
    iter(intArray, 5, printElement);
    std::cout << std::endl;
    return 0;
}

