#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <chrono>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    void processInput(char **argv);
    void parsing(const std::string& str);
    void displayResults();
    void fordJohnsonSort(std::vector<int> &container);
    void fordJohnsonSort(std::deque<int> &container);
};
