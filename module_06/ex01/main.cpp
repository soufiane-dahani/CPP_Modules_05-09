#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data data1(42);


    uintptr_t raw = Serializer::serialize(&data1);

    Data* data2 = Serializer::deserialize(raw);

    std::cout << "Original Data value: " << data1.getValue() << std::endl;
    std::cout << "Deserialized Data value: " << data2->getValue() << std::endl;

    std::cout << "Address of data1: " << &data1 << std::endl;
    std::cout << "Address of data2: " << data2 << std::endl;

    return 0;
}
