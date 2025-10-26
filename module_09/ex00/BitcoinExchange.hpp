#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <stdexcept>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        void loadDatabase(const std::string &filename);
        void processInputFile(const std::string &filename);

        bool isValidDate(const std::string &date) const;
        bool isValidValue(const std::string &value) const;
        float getRateForDate(const std::string &date) const;
};
