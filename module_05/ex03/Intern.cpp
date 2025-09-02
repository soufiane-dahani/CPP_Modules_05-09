#include "Intern.hpp"

Intern::~Intern()
{
    std::cout << "default destructor Intern" << std::endl ;
}

Intern::Intern(const Intern& other)
{
   (void)other;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    
}