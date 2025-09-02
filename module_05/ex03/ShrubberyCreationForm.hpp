#include "AForm.hpp"

class  ShrubberyCreationForm : public AForm
{
private:
    std::string _target;
public:
    ShrubberyCreationForm(const std::string &target);
    virtual ~ ShrubberyCreationForm();
    void execute(Bureaucrat const &executor) const;
};
