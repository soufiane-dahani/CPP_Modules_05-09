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

void PmergeMe::fordJohnsonSort(std::vector<int> &container)
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
        std::vector<int> main;
        std::vector<int> pend;
        std::vector<int> leftover;
        int i = 0;
        int j = 0;
        int a1 = 0;

        while (order * i <= container.size())
        {
            if ((order * i) % 2 == 0) // all b
            {
                j = 0;
                while (j < order)
                {
                    main.push_back(container[(order * i) + j]);
                    j++;
                }
            }
            else
            {
                j = 0;
                if (a1 == 0)
                {
                    a1 = 1;
                    while (j < order)
                    {
                        main.push_back(container[(order * i) + j]);
                        j++;
                    }
                }
                else
                    {
                        while (j < order)
                        {
                            pend.push_back(container[(order * i) + j]);
                            j++;
                        }
                    }
            }
            i++;
        }
        order/=2;
    }
    
    
}



void PmergeMe::fordJohnsonSort(std::deque<int> &container)
{

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

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << elapsedVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << elapsedDeq << " us" << std::endl;
}

