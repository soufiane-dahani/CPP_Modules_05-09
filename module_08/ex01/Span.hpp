#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;

    public:
        Span();
        Span(unsigned int size);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int number);

        template <typename It>
        void addNumber(It begin, It end);

        int shortestSpan() const;
        int longestSpan() const;
};

template <typename It>
void Span::addNumber(It begin, It end)
{
    unsigned int rangeSize = std::distance(begin, end);
    if (_numbers.size() + rangeSize > _maxSize)
        throw std::runtime_error("Cannot add range: Span would exceed max size");
    _numbers.insert(_numbers.end(), begin, end);
}