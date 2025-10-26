#include <sstream>
#include <cstdlib>
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

std::string trim(const std::string &str)
{
    size_t start = 0;
    while (start < str.length() && std::isspace(str[start]))
        start++;

    size_t end = str.length();
    while (end > start && std::isspace(str[end - 1]))
        end--;

    return str.substr(start, end - start);
}
    
    
void BitcoinExchange::processInputFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Failed to open file!");

    loadDatabase("data.csv");

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line))
    {
        std::string date, valueStr;
        std::stringstream ss(line);

        if (std::getline(ss, date, '|') && std::getline(ss, valueStr))
        {
            date = trim(date);
            valueStr = trim(valueStr);

            try {
                if (!isValidDate(date))
                    throw std::invalid_argument("Invalid date");

                if (!isValidValue(valueStr))
                    throw std::invalid_argument("Invalid value");

                float value = std::atof(valueStr.c_str());
                float rate = getRateForDate(date);
                std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
            }
            catch (const std::exception &e) {
                std::cerr << "Error: " << e.what() << " => " << line << std::endl;
            }
        }
        else
        {
            std::cerr << "Warning: bad line in input file => " << line << std::endl;
        }
    }
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
                float rate = std::atof(rateStr.c_str());  // safer than atof
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
    file.close();
}



bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    for (size_t i = 0; i < yearStr.length(); i++)
        if (!std::isdigit(yearStr[i]))
            return false;
    for (size_t i = 0; i < monthStr.length(); i++)
        if (!std::isdigit(monthStr[i]))
            return false;
    for (size_t i = 0; i < dayStr.length(); i++)
        if (!std::isdigit(dayStr[i]))
            return false;

    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    if (month == 2 && day > 29)
        return false;

    return true;
}



bool BitcoinExchange::isValidValue(const std::string &value) const
{
    std::istringstream ss(value);
    float num;
    ss >> num;

    if (ss.fail() || !ss.eof())
        return false;

    if (num < 0.0f || num > 1000.0f)
        return false;

    return true;
}

float BitcoinExchange::getRateForDate(const std::string &date) const
{
    
}