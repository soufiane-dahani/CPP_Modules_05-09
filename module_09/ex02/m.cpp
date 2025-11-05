#include <iostream>
#include <vector>
#include <deque>
#include "PmergeMe.hpp"

int main()
{
    int arr[] = {3, 5 ,9, 7 ,4};
    std::vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
    PmergeMe::fordJohnsonSort(v);
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}


// int main()
// {
//     int arr[] = {25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
//     std::vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
//     std::vector<int> swapped = swap_container(3, 7, &v, 4);

//     std::cout << "Swapped vector:  ";
//     for (int n : swapped)
//         std::cout << n << " ";
//     std::cout << "\n";

//     return 0;
// }