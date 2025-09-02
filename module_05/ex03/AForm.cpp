#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::~AForm()
{
    std::cout << "default destructor AForm" << std::endl;
}

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high! (AForm)";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low! (AForm)";
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= _gradeToSign)
        _isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName()
       << ", AForm Grade To Sign " << f.getGradeToSign()
       << ", Grade To Execute " << f.getGradeToExecute()
       << ", Signed: " << (f.getIsSigned() ? "Yes" : "No");
    return os;
}
