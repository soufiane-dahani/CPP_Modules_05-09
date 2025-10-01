#include "Base.hpp"
#include "Identify.hpp"
#include <iostream>

int main() {
    for (int i = 0; i < 5; ++i) {
        Base* obj = generate();

        std::cout << "Using pointer: ";
        identify(obj);

        std::cout << "Using reference: ";
        identify(*obj);

        delete obj;

        std::cout << "-----------------" << std::endl;
    }

    return 0;
}


