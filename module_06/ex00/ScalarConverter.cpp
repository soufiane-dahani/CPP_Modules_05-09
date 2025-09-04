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

}
void ScalarConverter::printDouble(double value);
{

}
void ScalarConverter::printFloat(double value)
{

}
bool ScalarConverter::isChar(std::string const &literal)
{

}
bool ScalarConverter::isFloat(std::string const &literal)
{

}
bool ScalarConverter::isInt(std::string const &literal)
{

}
bool ScalarConverter::isDouble(std::string const &literal)
{

}

void ScalarConverter::convert(std::string const &literal)
{

}