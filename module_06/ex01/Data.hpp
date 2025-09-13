#pragma once

class Data
{
    private:
        int _value ;
    public:
        Data(int value);
        Data(const Data &);
        Data &operator=(const Data &);
        ~Data();
    
};
