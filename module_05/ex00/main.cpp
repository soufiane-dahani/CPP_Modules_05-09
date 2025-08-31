#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try {
        std::cout << "try risky code \n";
        Bureaucrat b("dahani", 1);
        std::cout << b ;
        b.incrementGrade();
        std::cout << b ;
    }
    catch (const std::exception &e)
    {
        std::cout << "something happen error " << e.what() << std::endl ;
    }
    return 0;
}
