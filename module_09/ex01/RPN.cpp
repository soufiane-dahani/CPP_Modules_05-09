#include "RPN.hpp"
#include <cstdlib>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

void RPN::evaluate(const std::string &expr)
{
    if (expr.find_first_not_of("0123456789/*+- ") != std::string::npos)
    {
        std::cerr << "Error" << std::endl;
        return;
    }
    std::istringstream iss(expr);
    std::string token;
    while (iss >> token)
    {
        if (isdigit(token[0]))
        {
            if (token.find_first_not_of("/*+-") == std::string::npos)
            {
                std::cerr << "Error" << std::endl;
                return;
            }
            int number = std::atoi(token.c_str());
            if (number >= 10 )
            {
                std::cerr << "Error" << std::endl;
                return;
            }
            _stack.push(number);
        }
        else if (token.size() == 1 && std::string("+-*/").find(token) != std::string::npos)
        {
            if (_stack.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return;
            }
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
             _stack.pop();
              switch (token[0]) {
                case '+': _stack.push(a + b); break;
                case '-': _stack.push(a - b); break;
                case '*': _stack.push(a * b); break;
                case '/':
                    if (b == 0) {
                        std::cerr << "Division by zero" << std::endl;
                        return;
                    }
                    _stack.push(a / b);
                    break;
            }
        }
        else
        {
            std::cerr << "Error" << std::endl;
                return;
        }
    }
    if (_stack.size() == 1)
        std::cout << _stack.top() << std::endl;
    else
        std::cerr << "Error" << std::endl;
}
