#include <iostream>
#include <exception>
#pragma once
class Bureaucrat;

class AForm 
{
private :
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
public :
	AForm(const std::string &name , int gradeTosign, int gradeToExecute);
	virtual ~AForm();
	const std::string &getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat& b);
	class GradeTooHighException : public std::exception
    	{
        public:
            const char* what() const throw();
    	};

    class GradeTooLowException : public std::exception
    	{
        public:
            const char* what() const throw();
    	};
	virtual void execute(Bureaucrat const & executor) const = 0;
};


std::ostream& operator<<(std::ostream& os, const AForm& f);
