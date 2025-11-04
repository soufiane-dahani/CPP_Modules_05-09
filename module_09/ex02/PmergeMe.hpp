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
    static void fordJohnsonSort(std::vector<int> &container);
    void fordJohnsonSort(std::deque<int> &container);
};

#include <vector>
#include <deque>
#include <algorithm> // for std::swap

template <typename Container>
Container swap_container(int first_pos, int last_pos, Container *container, int order)
{
    // Make a copy of the original container to modify safely
    Container result = *container;

    // Swap blocks of size 'order' starting from first_pos and last_pos
    for (int i = 0; i < order; ++i)
    {
        if (first_pos + i < (int)container->size() && last_pos + i < (int)container->size())
        {
            typename Container::value_type temp = (*container)[first_pos + i];
            result[first_pos + i] = (*container)[last_pos + i];
            result[last_pos + i] = temp;
        }
    }

    return result;
}