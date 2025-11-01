#pragma once
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <stdexcept>

class RPN
{
private:
    std::stack<int> _stack;

public:
    RPN();
    ~RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);

    void evaluate(const std::string &expr);
};
