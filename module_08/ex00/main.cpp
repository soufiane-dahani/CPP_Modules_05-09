#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    try {
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        vec.push_back(50);

        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(10);
        lst.push_back(15);
        lst.push_back(20);
        lst.push_back(25);

        // --- Test with vector ---
        std::cout << "Searching 30 in vector..." << std::endl;
        std::vector<int>::iterator itVec = easyfind(vec, 30);
        std::cout << "Found value: " << *itVec << std::endl;

        // --- Test with list ---
        std::cout << "Searching 20 in list..." << std::endl;
        std::list<int>::iterator itList = easyfind(lst, 20);
        std::cout << "Found value: " << *itList << std::endl;

        // --- Test value not found ---
        std::cout << "Searching 100 in vector..." << std::endl;
        std::vector<int>::iterator itFail = easyfind(vec, 100);
        std::cout << "Found value: " << *itFail << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "❌ Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
