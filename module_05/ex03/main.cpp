#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    AForm* form;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        try
        {
        Bureaucrat bob("Bob", 140);
        form->beSigned(bob);
            form->execute(bob);
        }
        catch(const std::exception& e)
        {
            std::cerr  << "failed: "<< e.what() << '\n';
        }
        delete form;
    }

    form = someRandomIntern.makeForm("invalid form", "TargetX");
    if (form) delete form;

    return 0;
}

