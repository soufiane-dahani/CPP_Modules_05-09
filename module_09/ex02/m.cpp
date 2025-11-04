#include <iostream>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"

int main()
{
    int arr[] = {25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
    PmergeMe::fordJohnsonSort(v);
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}
