#pragma once
#include <string>

class ScalarConverter
{
    private:
        static void printChar(double value);
        static void printInt(double value);
        static void printFloat(double value);
        static void printDouble(double value);
        static bool isChar(std::string const &literal);
        static bool isInt(std::string const &literal);
        static bool isFloat(std::string const &literal);
        static bool isDouble(std::string const &literal);
    public:
        static void convert(std::string const &literal);
        ScalarConverter() = delete;
        ScalarConverter(ScalarConverter const &) = delete;
        ScalarConverter &operator=(ScalarConverter const &) = delete;
        ~ScalarConverter() = delete;

};