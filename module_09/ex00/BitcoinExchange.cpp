#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

// Copy assignment operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _data = other._data;
        return *this;
    }
    
    
void BitcoinExchange::processInputFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file!");
    }
    loadDatabase("data.csv");
    std::string line;
    std::getline(file, line);  // skip first line "date | value"
    while (std::getline(file, line))
    {
        // process each line here
    }
    file.close();
}


void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Failed to open file!");

    std::string line;
    std::getline(file, line);  // skip first line "date,exchange_rate"

    while (std::getline(file, line))
    {
        std::string date, rateStr;
        std::stringstream ss(line);

        if (std::getline(ss, date, ',') && std::getline(ss, rateStr))
        {
            try
            {
                float rate = std::stof(rateStr);  // safer than atof
                _data[date] = rate;
            }
            catch (std::exception &)
            {
                std::cerr << "Warning: invalid rate in line => " << line << std::endl;
            }
        }
        else
        {
            std::cerr << "Warning: bad line in database => " << line << std::endl;
        }
    }
}



bool BitcoinExchange::isValidDate(const std::string &date) const
{
    
}

bool BitcoinExchange::isValidValue(const std::string &value) const
{
    
}

float BitcoinExchange::getRateForDate(const std::string &date) const
{
    
}