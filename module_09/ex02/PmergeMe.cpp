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

void PmergeMe::fordJohnsonSort(std::vector<int> &container) {
    if (container.size() <= 1) return;

    // Step 1: Form pairs and sort within each pair
    for (size_t i = 0; i + 1 < container.size(); i += 2) {
        if (container[i] > container[i + 1])
            std::swap(container[i], container[i + 1]);
    }

    // Step 2: Separate main (bigger) and pend (smaller)
    std::vector<int> main;
    std::vector<int> pend;
    for (size_t i = 0; i + 1 < container.size(); i += 2) {
        main.push_back(container[i + 1]); // bigger
        pend.push_back(container[i]);     // smaller
    }
    if (container.size() % 2 != 0)
        main.push_back(container.back()); // leftover last element

    // Step 3: Sort main
    std::sort(main.begin(), main.end());

    // Step 4: Insert pend elements in Jacobsthal order
    std::vector<size_t> jac_indices = jacobsthalIndices(pend.size());
    std::vector<bool> inserted(pend.size(), false);

    for (size_t idx : jac_indices) {
        if (idx < pend.size() && !inserted[idx]) {
            // Insert pend[idx] into main at correct position
            auto pos = std::lower_bound(main.begin(), main.end(), pend[idx]);
            main.insert(pos, pend[idx]);
            inserted[idx] = true;
        }
    }

    // Insert any remaining pend elements that were not in Jacobsthal sequence
    for (size_t i = 0; i < pend.size(); ++i) {
        if (!inserted[i]) {
            auto pos = std::lower_bound(main.begin(), main.end(), pend[i]);
            main.insert(pos, pend[i]);
        }
    }

    // Step 5: Copy back to original container
    container = main;
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

void PmergeMe::fordJohnsonSort(std::deque<int> &container)
{
     int order = 1;
    int last_pos;
    int first_pos;

    while (order <= container.size() / 2)
    {
        last_pos = (order * 2) - 1; // 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0
        first_pos = order - 1;
        while (last_pos < container.size())  // Changed >= to 
        {
            if (container[first_pos] > container[last_pos])
            {
                container = swap_container(first_pos, last_pos, &container, order);
            }
            first_pos = first_pos + (2 * order);  // Fixed: add 2*order
            last_pos = last_pos + (2 * order);    // Fixed: add 2*order
        }
        order = order * 2;
    }
    order/=2;
    while (true)
    {
        if (order == 1)
            break;
        
        std::deque<int> main;
        std::deque<int> pend;
        std::deque<int> leftover;
        
        int pos = 0;
        bool first_a = true;
        
        while (pos + order <= container.size())
        {
            //  'a'
            for (int j = 0; j < order && pos + j < container.size(); j++)
            {
                if (first_a)
                    main.push_back(container[pos + j]);
                else
                    pend.push_back(container[pos + j]);
            }
            pos += order;
            
            if (pos + order > container.size())
                break;
            
            //  'b'
            for (int j = 0; j < order && pos + j < container.size(); j++)
            {
                main.push_back(container[pos + j]);
            }
            pos += order;
            
            first_a = false;
        }

        // Handle remaining elements that form an incomplete 'a' group
        if (pos < container.size() && !first_a)
        {
            // There are remaining elements and we've already processed at least one pair
            // These belong to an 'a' group that should go to pend
            while (pos < container.size())
            {
                pend.push_back(container[pos]);
                pos++;
            }
        }
        else
        {
            // leftover (truly unpaired elements)
            while (pos < container.size())
            {
                leftover.push_back(container[pos]);
                pos++;
            }
        }
        pos = 0;
        int j;
        while (pos < pend.size())
        {
            j = 0;
            bool inserted = false;
            while (j < main.size())
            {
                if (pend[pos] < main[j])
                {
                    main.insert(main.begin() + j, pend[pos]);
                    inserted = true;
                    break;
                }
                j++;
            }
            // If element wasn't inserted (it's larger than all elements in main)
            if (!inserted)
            {
                main.push_back(pend[pos]);
            }
            pos++;
        }
        container = main;
        // printVector(main, "main");
        // printVector(pend, "pend");
        // printVector(leftover, "leftover");
        // exit(1);
        order /= 2;
    }
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

