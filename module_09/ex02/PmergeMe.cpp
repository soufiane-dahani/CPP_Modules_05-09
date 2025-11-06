#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <string>
#include <stdexcept>
#include <iomanip>

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->_vec = other._vec;
        this->_deq = other._deq;
    }
    return *this;
}
void PmergeMe::parsing(const std::string& str)
{
    if (str.find_first_not_of("0123456789+ ") != std::string::npos)
        throw std::runtime_error("not a number");
    std::istringstream iss(str);
    std::string token;
    while (iss >> token)
    {
        if (token.empty())
            throw std::runtime_error("empty token");
        if (token.find_first_not_of("0123456789+") != std::string::npos)
            throw std::runtime_error("invalid character");
        if (token[0] == '+')
            token.erase(0, 1);
        if (token.empty() || !std::isdigit(token[0]))
            throw std::runtime_error("invalid token");
        long number = std::strtol(token.c_str(), NULL, 10);
        if (number < 0 || number > 2147483647)
            throw std::runtime_error("out of range");
        if (std::find(_vec.begin(), _vec.end(), number) != _vec.end())
            throw std::runtime_error("duplicate number");
        _vec.push_back(number);
        _deq.push_back(number);
    }
}

void PmergeMe::processInput(char **argv)
{
    int i = 1;
    while (argv[i] != NULL)
    {
        parsing(argv[i]);
        i++;
    }
}

void printVector(const std::vector<int>& vec, const std::string& name)
{
    std::cout << name << ": ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << (i + 1 < vec.size() ? ", " : "");
    std::cout << std::endl;
}

std::vector<size_t> jacobsthalIndices(size_t n) {
    std::vector<size_t> indices;
    size_t j1 = 1, j2 = 1;
    while (j1 <= n) {
        indices.push_back(j1 - 1); // convert to 0-based index
        size_t next = j1 + 2 * j2;
        j2 = j1;
        j1 = next;
    }
    return indices;
}

// Ford-Johnson (Merge-Insertion Sort)
void PmergeMe::fordJohnsonSort(std::vector<int> &container) {
    if (container.size() <= 1)
        return;

    // Step 1: Pair and sort each pair internally
    for (size_t i = 0; i + 1 < container.size(); i += 2) {
        if (container[i] > container[i + 1])
            std::swap(container[i], container[i + 1]);
    }

    // Step 2: Separate bigger (main) and smaller (pend)
    std::vector<int> main;
    std::vector<int> pend;
    for (size_t i = 0; i + 1 < container.size(); i += 2) {
        main.push_back(container[i + 1]); // larger
        pend.push_back(container[i]);     // smaller
    }
    if (container.size() % 2 != 0)
        main.push_back(container.back()); // leftover element

    // Step 3: Recursively sort main
    fordJohnsonSort(main);

    // Step 4: Insert pend elements in Jacobsthal order
    std::vector<int> sorted_main = main;
    std::vector<size_t> jac_indices = jacobsthalIndices(pend.size());
    std::vector<bool> inserted(pend.size(), false);

    for (size_t j = 0; j < jac_indices.size(); ++j) {
        size_t idx = jac_indices[j];
        if (idx < pend.size() && !inserted[idx]) {
            std::vector<int>::iterator pos = std::lower_bound(sorted_main.begin(), sorted_main.end(), pend[idx]);
            sorted_main.insert(pos, pend[idx]);
            inserted[idx] = true;
        }
    }

    // Step 5: Insert remaining pend elements
    for (size_t i = 0; i < pend.size(); ++i) {
        if (!inserted[i]) {
            std::vector<int>::iterator pos = std::lower_bound(sorted_main.begin(), sorted_main.end(), pend[i]);
            sorted_main.insert(pos, pend[i]);
        }
    }

    // Step 6: Copy back
    container = sorted_main;
}

bool isSorted(const std::vector<int>& vec)
{
    if (vec.size() < 2)
        return true; // A single element (or empty) vector is always sorted

    for (size_t i = 1; i < vec.size(); ++i)
    {
        if (vec[i - 1] > vec[i])
            return false; // Not sorted
    }
    return true; // All elements are in ascending order
}




void PmergeMe::displayResults()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;

    std::vector<int> vecCopy = _vec;
    clock_t startVec = clock();
    fordJohnsonSort(vecCopy);
    clock_t endVec = clock();
    double elapsedVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;

    std::deque<int> deqCopy = _deq;
    clock_t startDeq = clock();
    fordJohnsonSort(deqCopy);
    clock_t endDeq = clock();
    double elapsedDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

    std::cout << "After:  ";
    for (size_t i = 0; i < vecCopy.size(); ++i)
        std::cout << vecCopy[i] << " ";
    std::cout << std::endl;

    if (isSorted(vecCopy))
        std::cout << "\033[32mThe vector is sorted.\033[0m\n"; // Green
    else
        std::cout << "\033[31mThe vector is NOT sorted.\033[0m\n"; 

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << elapsedVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << elapsedDeq << " us" << std::endl;
}

std::deque<size_t> jacobsthalIndices2(size_t n) {
    std::deque<size_t> indices;
    size_t j1 = 1, j2 = 1;
    while (j1 <= n) {
        indices.push_back(j1 - 1); // convert to 0-based index
        size_t next = j1 + 2 * j2;
        j2 = j1;
        j1 = next;
    }
    return indices;
}

// Ford-Johnson (Merge-Insertion Sort)
void PmergeMe::fordJohnsonSort(std::deque<int> &container) {
    if (container.size() <= 1)
        return;

    // Step 1: Pair and sort each pair internally
    for (size_t i = 0; i + 1 < container.size(); i += 2) {
        if (container[i] > container[i + 1])
            std::swap(container[i], container[i + 1]);
    }

    // Step 2: Separate bigger (main) and smaller (pend)
    std::deque<int> main;
    std::deque<int> pend;
    for (size_t i = 0; i + 1 < container.size(); i += 2) {
        main.push_back(container[i + 1]); // larger
        pend.push_back(container[i]);     // smaller
    }
    if (container.size() % 2 != 0)
        main.push_back(container.back()); // leftover element

    // Step 3: Recursively sort main
    fordJohnsonSort(main);

    // Step 4: Insert pend elements in Jacobsthal order
    std::deque<int> sorted_main = main;
    std::deque<size_t> jac_indices = jacobsthalIndices2(pend.size());
    std::deque<bool> inserted(pend.size(), false);

    for (size_t j = 0; j < jac_indices.size(); ++j) {
        size_t idx = jac_indices[j];
        if (idx < pend.size() && !inserted[idx]) {
            std::deque<int>::iterator pos = std::lower_bound(sorted_main.begin(), sorted_main.end(), pend[idx]);
            sorted_main.insert(pos, pend[idx]);
            inserted[idx] = true;
        }
    }

    // Step 5: Insert remaining pend elements
    for (size_t i = 0; i < pend.size(); ++i) {
        if (!inserted[i]) {
            std::deque<int>::iterator pos = std::lower_bound(sorted_main.begin(), sorted_main.end(), pend[i]);
            sorted_main.insert(pos, pend[i]);
        }
    }

    // Step 6: Copy back
    container = sorted_main;
}

