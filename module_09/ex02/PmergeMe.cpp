#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stack>
#include <string>
#include <stdexcept>

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