#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 50);
        Bureaucrat bob("Bob", 120);

        Form contract("Work Contract", 100, 50);

        std::cout << contract << std::endl;

        bob.signForm(contract);

        std::cout << contract << std::endl;

        alice.signForm(contract);

        std::cout << contract << std::endl;

    } catch (std::exception& e) {
        std::cout << "Exception caught in main: " << e.what() << std::endl;
    }
    return 0;
}
