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

template <typename Container>
Container swap_container(int first_pos, int last_pos, Container *container, int order)
{
    // Make a copy of the original container to modify safely
    Container result = *container;

    // Calculate the start positions of both blocks
    int block1_start = first_pos - order + 1;  // Start of first block
    int block2_start = last_pos - order + 1;   // Start of second block

    // Swap blocks of size 'order'
    for (int i = 0; i < order; ++i)
    {
        if (block1_start + i >= 0 && block1_start + i < (int)container->size() &&
            block2_start + i >= 0 && block2_start + i < (int)container->size())
        {
            typename Container::value_type temp = (*container)[block1_start + i];
            result[block1_start + i] = (*container)[block2_start + i];
            result[block2_start + i] = temp;
        }
    }

    return result;
}