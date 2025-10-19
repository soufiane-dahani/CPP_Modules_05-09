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
