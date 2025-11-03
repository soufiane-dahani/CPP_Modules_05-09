#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error\n";
        return 1;
    }
    try {
        PmergeMe sorter;
        sorter.processInput(argv);
        sorter.displayResults();
    } catch (std::exception &e) {
        std::cerr << "Error\n";
        return 1;
    }
}
