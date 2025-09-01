#include <iostream>
#pragma once
#include <exception>
class Bureaucrat;

class Form 
{
private :
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
public :
	Form(const std::string &name , int gradeTosign, int gradeToExecute);
	~Form();
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

};


std::ostream& operator<<(std::ostream& os, const Form& f);
