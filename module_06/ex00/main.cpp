#include <iostream>
#include "ScalarConverter.hpp"

int main()
{
    std::cout << "==== Test with int ====" << std::endl;
    ScalarConverter::convert("42");
    ScalarConverter::convert("-123");

    std::cout << "\n==== Test with char ====" << std::endl;
    ScalarConverter::convert("a");
    ScalarConverter::convert("Z");

    std::cout << "\n==== Test with float ====" << std::endl;
    ScalarConverter::convert("42.0f");
    ScalarConverter::convert("-4.2f");
    ScalarConverter::convert("0.0f");

    std::cout << "\n==== Test with double ====" << std::endl;
    ScalarConverter::convert("42.0");
    ScalarConverter::convert("-4.2");
    ScalarConverter::convert("0.0");

    std::cout << "\n==== Test with special literals ====" << std::endl;
    ScalarConverter::convert("nan");
    ScalarConverter::convert("nanf");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("-inff");

    std::cout << "\n==== Test with edge cases ====" << std::endl;
    ScalarConverter::convert("2147483647");  // INT_MAX
    ScalarConverter::convert("-2147483648"); // INT_MIN
    ScalarConverter::convert("340282346638528859811704183484516925440.0f"); // float max

    return 0;
}
