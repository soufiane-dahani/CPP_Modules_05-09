#pragma once

struct Data
{
        int _value ;
        Data();
        Data(int value);
        Data(const Data &other);
        Data &operator=(const Data &other);
        ~Data();
        int getValue() const;
};
