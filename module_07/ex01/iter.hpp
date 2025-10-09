#pragma once 
#include <iostream>

template <typename T>

void iter(const T *array, size_t length, void (*func)(const T &))
{
    if (!array || !func)
    return;
    for (size_t i = 0; i < length; i++)
    func(array[i]);
}

template <typename T>

void iter(T *array, size_t length, void (*func)(T &))
{
    if (!array || !func)
    return;
    for (size_t i = 0; i < length; i++)
    func(array[i]);
}

template <typename T>

void printElement(const T  &x)
{
    std::cout << x << std::endl;
}

template <typename T>

void print1337(T &x)
{
    std::cout << x << std::endl;
}