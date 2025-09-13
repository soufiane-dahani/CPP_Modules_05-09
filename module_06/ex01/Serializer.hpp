#pragma once
#include "Data.hpp"
#include <cstdint>

class Serializer
{
    private:
        Serializer();
        ~Serializer();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

