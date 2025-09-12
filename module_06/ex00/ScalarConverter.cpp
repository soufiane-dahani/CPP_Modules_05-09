#include "ScalarConverter.hpp"
#include <limits>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <cmath>

void ScalarConverter::printInt(double value)
{
    if (value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max() ||
        std::isnan(value))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    std::cout << "int : " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printChar(double value)
{
    if (std::isnan(value) ||
        value < std::numeric_limits<char>::min() ||
        value > std::numeric_limits<char>::max())
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    char c = static_cast<char>(value);
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printDouble(double value)
{
    if (std::isnan(value)) {
        std::cout << "double: nan" << std::endl;
    } else if (std::isinf(value)) {
        if (value > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    } else {
        std::cout << "double: " << value;
        if (value == static_cast<int>(value)) 
            std::cout << ".0";
        std::cout << std::endl;
    }
}


void ScalarConverter::printFloat(double value)
{
    if (std::isnan(value)) {
        std::cout << "float: nanf" << std::endl;
    } else if (std::isinf(value)) {
        if (value > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
    } else if (value < -std::numeric_limits<float>::max() ||
               value > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
    } else {
        float f = static_cast<float>(value);
        std::cout << "float: " << f;
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}


bool ScalarConverter::isFloat(std::string const &literal)
{
    if (literal.empty())
        return false;

    size_t i = 0;

    if (literal[0] == '+' || literal[0] == '-')
        i = 1;

    bool dotFound = false;

    if (i == literal.length() - 1)
        return false;

    for (; i < literal.length() - 1; ++i)
    {
        if (literal[i] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else if (!std::isdigit(literal[i]))
            return false;
    }

    if (literal[literal.length() - 1] != 'f')
        return false;

    return dotFound;
}

bool ScalarConverter::isInt(std::string const &literal)
{
    if (literal.empty())
        return false;

    size_t i = 0;

    if (literal[0] == '+' || literal[0] == '-')
        i = 1;
    if (i == literal.length())
        return false;

    for (; i < literal.length(); ++i)
    {
        if (!std::isdigit(literal[i]))
            return false;
    }

    return true;
}

bool ScalarConverter::isDouble(std::string const &literal)
{
    if (literal.empty())
        return false;

    size_t i = 0;
    if (literal[0] == '+' || literal[0] == '-')
        i = 1;

    bool dotFound = false;
    if (i == literal.length())
        return false;

    for (; i < literal.length(); ++i)
    {
        if (literal[i] == '.')
        {
            if (dotFound)
                return false;
            dotFound = true;
        }
        else if (!std::isdigit(literal[i]))
            return false;
    }
    return true;
}

void ScalarConverter::convert(std::string const &literal)
{
    double value;

    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'') {
        value = static_cast<double>(literal[1]);
    }
    else if (literal.length() == 1 && !std::isdigit(literal[0])) {
        value = static_cast<double>(literal[0]);
    }
    else if (isInt(literal)) {
        value = static_cast<double>(std::atoi(literal.c_str()));
    }
    else if (isFloat(literal)) {
        value = std::strtod(literal.c_str(), NULL);
    }
    else if (isDouble(literal)) {
        value = std::strtod(literal.c_str(), NULL);
    }
    else if (literal == "nan" || literal == "nanf") {
        value = 0.0 / 0.0;
    }
    else if (literal == "+inf" || literal == "+inff") {
        value = 1.0 / 0.0;
    }
    else if (literal == "-inf" || literal == "-inff") {
        value = -1.0 / 0.0;
    }
    else {
        std::cout << "Error: invalid literal" << std::endl;
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}