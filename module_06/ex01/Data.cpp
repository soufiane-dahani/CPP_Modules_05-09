#include <iostream>
#include "Data.hpp"

Data::Data()
{
    _value = 10 ;
};

Data::Data(int value) : _value(value) {} 

Data::Data(const Data &other)
{
    _value = other._value;
};

Data &Data::operator=(const Data &other)
{
    if (this != &other)
    {
        _value = other._value;
    }
    return *this;
};

Data::~Data()
{
    std::cout << "default desctructor" << std::endl ;
}

int Data::getValue() const
{
    return _value ;
};

