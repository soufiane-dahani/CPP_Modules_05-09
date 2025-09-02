#include "AForm.hpp"

class  RobotomyRequestForm : public AForm
{
private:
    std::string _target;
public:
    RobotomyRequestForm(const std::string &target);
    virtual ~ RobotomyRequestForm();
    void execute(Bureaucrat const &executor) const;
};
