#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat bob("Bob", 137);
        ShrubberyCreationForm form("home");

        std::cout << form << std::endl;
        try
        {
            form.execute(bob);
        }
        catch (std::exception &e)
        {
            std::cout << "Execution failed: " << e.what() << std::endl;
        }
        bob.signForm(form);
        std::cout << form << std::endl;
        try
        {
            form.execute(bob);
            std::cout << "Execution succeeded!" << std::endl;
        }
        catch (std::exception &e)
        {
            std::cout << "Execution failed: " << e.what() << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
