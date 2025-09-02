#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::~Form()
{
    std::cout << "default destructor Form" << std::endl;
}

const std::string& Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high! (Form)";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low! (Form)";
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() <= _gradeToSign)
        _isSigned = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName()
       << ", Form Grade To Sign " << f.getGradeToSign()
       << ", Grade To Execute " << f.getGradeToExecute()
       << ", Signed: " << (f.getIsSigned() ? "Yes" : "No");
    return os;
}
