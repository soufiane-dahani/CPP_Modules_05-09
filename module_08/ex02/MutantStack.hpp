#pragma once 
#include <stack>
#include <deque>
template <typename T, typename Container = std::deque<T> >

class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;

        iterator begin();
        iterator end();
        const_iterator begin() const;
        const_iterator end() const; 
};

