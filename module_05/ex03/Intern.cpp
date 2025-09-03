#include "Intern.hpp"

Intern::~Intern()
{
    std::cout << "default destructor Intern" << std::endl;
}
Intern::Intern()
{
    std::cout << "default constructor Intern" << std::endl;
}

Intern::Intern(const Intern& other)
{
   (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this ;
}

static AForm* makeShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* makeRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* makePresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* (*constructors[3])(const std::string&) = {
        &makeShrubbery,
        &makeRobotomy,
        &makePresidential
    };

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formNames[i] << std::endl;
            return constructors[i](target);
        }
    }
    std::cout << "Error: Form name '" << formName << "' does not exist." << std::endl;
    return NULL;
}

