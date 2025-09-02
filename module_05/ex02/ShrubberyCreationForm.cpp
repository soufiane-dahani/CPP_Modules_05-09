#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>  

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "default destructor ShrubberyCreationForm" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw std::runtime_error("Form is not signed!");

    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (!outfile.is_open())
        throw std::runtime_error("Failed to open file");

    outfile << "  c  " << std::endl;
    outfile << " ccc " << std::endl;
    outfile << "ccccc" << std::endl;
    outfile.close();
}
