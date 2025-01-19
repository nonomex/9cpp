/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 09:55:26 by aammirat          #+#    #+#             */
/*   Updated: 2025/01/19 17:43:27 by aammirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::ifstream & file)
{
    std::string part1;
    std::string part2;
    std::string line;
    int commaPos;
    while (getline(file, line))
    {
        commaPos = line.find(',');
        part1 = line.substr(0, commaPos);
        part2 = line.substr(commaPos + 1);
        data[part1] = strtod(part2.c_str(), NULL);
    }
}

BitcoinExchange::~BitcoinExchange()
{
    data.clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
    data = copy.data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange  &copy)
{
    (void)copy;
    return (*this);    
}

static int check_4year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return (1);
    else
        return (0);
}

static int check_format(std::string date)
{
    int i = 0;
    if (date.size() != 10)
        return (1);
    for (i = 0; i < 10; i++)
    {
        if (i != 4 && i != 7 && (date[i] < '0' || date[i] > '9'))
            return (1);
    }
    return (0);
}

static int check_date(std::string date)
{
    if (check_format(date))
        return (1);
    int year, month, day;
    char dash1, dash2;
    std::istringstream isyear(date);
    if (!(isyear >> year >> dash1 >> month >> dash2 >> day))
        return (1);
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return (1);
    if (year == 2009 && month == 1 && day < 2)
        return (1);
    if (month == 2)
    {
        if (check_4year(year))
        {
            if (day > 29)
                return (1);
        }
        else
        {
            if (day > 28)
                return (1);
        }
    }
    if ((month % 2 == 0) && day > 30)
        return (1);
    return (0);
}

void BitcoinExchange::BitcoinCalc(std::ifstream &file)
{
    std::string line;
    getline(file, line);
    std::string date;
    size_t commaPos;
    float     price;
    if (line != "date | value")
    {
        std::cerr << "Error: File not at the good format" << std::endl;
        return;
    }
    while (getline(file, line))
    {
        commaPos = line.find(" | ");
        if (commaPos == std::string::npos)
            std::cout << "Error: bad input => " << line << std::endl;
        else
        {
            date = line.substr(0, commaPos);
            price = strtod(line.substr(commaPos + 3).c_str(), NULL);
            if (price <= 0)
                std::cout << "Error: not a positive number" << std::endl;
            else if (price > 1000)
                std::cout << "Error: too large number" << std::endl;
            else if (check_date(date))
            {
                std::cout << "Error: invalid date => " << date << std::endl;
            }
            else
            {
                std::map<std::string, float>::iterator it = data.lower_bound(date);
                std::cout << date << " => " << price << " = ";
                if (it != data.begin())
                    it--;
                std::cout << it->second<< std::endl;
            }
        }
    }
}

