#include <iostream>

class Bureaucrat
{
    private :
        int _grade ;
        const std::string _name ;

    public :
        Bureaucrat(int grade, std::string name);
       ~Bureaucrat();
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
        const std::string&  getName() const;
        int  getGrade() const;
        void incrementGrade();
        void decrementGrade();

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
