#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <bits/stdc++.h>
#include <fstream>  

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "default destructor RobotomyRequestForm" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw std::runtime_error("Form is not signed!");
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "drilling noises..." << std::endl;

    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy of " << _target << " failed." << std::endl;
}

