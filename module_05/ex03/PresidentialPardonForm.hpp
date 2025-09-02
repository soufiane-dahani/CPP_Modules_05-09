#include "AForm.hpp"

class  PresidentialPardonForm : public AForm
{
private:
    std::string _target;
public:
    PresidentialPardonForm(const std::string &target);
    virtual ~ PresidentialPardonForm();
    void execute(Bureaucrat const &executor) const;
};
