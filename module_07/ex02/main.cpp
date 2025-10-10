#include "Array.hpp"

int main() {
    try {
        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i * 10;

        std::cout << "Array a: ";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        Array<int> b = a;
        b[0] = 999;

        std::cout << "Array b (copied): ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << std::endl;

        std::cout << "Array a (unchanged): ";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        std::cout << "Trying out-of-bounds access..." << std::endl;
        std::cout << a[10] << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
