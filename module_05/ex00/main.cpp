#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat b1("Alice", 2);
        std::cout << b1 << std::endl;

        std::cout << "Incrementing Alice's grade..." << std::endl;
        b1.incrementGrade(); // grade becomes 1
        std::cout << b1 << std::endl;

        std::cout << "Incrementing Alice's grade again..." << std::endl;
        b1.incrementGrade(); // should throw GradeTooHighException
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-------------------------" << std::endl;

    try {
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;

        std::cout << "Decrementing Bob's grade..." << std::endl;
        b2.decrementGrade(); // should throw GradeTooLowException
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-------------------------" << std::endl;

    try {
        Bureaucrat b3("Charlie", 0); // invalid grade, should throw
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught while creating Charlie: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b4("David", 200); // invalid grade, should throw
    }
    catch (const std::exception& e) {
        std::cout << "Exception caught while creating David: " << e.what() << std::endl;
    }

    return 0;
}
