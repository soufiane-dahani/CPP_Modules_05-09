#include <iostream>
// #include <stdexcept>

int main ()
{
    try {
    throw std::string("oops");
    }
    catch (const std::string e) {
        std::cout << "Caught a string: " << e << std::endl;
    }

}