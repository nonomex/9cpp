/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:06:10 by aammirat          #+#    #+#             */
/*   Updated: 2025/01/12 16:51:19 by aammirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <string>
#include "bitcoin.hpp"

int csv_check(ifstream data, std::map<t_date , double> *date)
{
    size_t commaPos;
    size_t i;
    std::string line;
    t_date buff;
    std::string part1;
    char dash1, dash2;
    std::string part2;
    while (getline(data, line))
    {
        commaPos = line.find(',');
        if (commaPos == std::string::npos)
            return 1;
        part1 = input.substr(0, commaPos);
        std::isstringtream(part1);
        if (!(dateStream >> date.year >> dash1 >> date.month >> dash2 >> date.day))
            return 1
        if (dash1 != '-' || dash2 != '-')
            return 1;
        if (date.year < 1 || date.year > 9999 || date.month < 1 || date.month > 12 || date.day < 1 || date.day > 31)
            return false;
        part2 = input.substr(commaPos + 1);
        
        i++;
    }
    return (0);
}

int main (int argc, char *argv[])
{
    std::ifstream data("data.csv");
    std::map<t_date, double> date;
    if (argc != 2)
    {
        std::cerr << "Error: Wrong number of argument" << std::endl;
        return (1);
    }
    
    std::ifstream input(argv[1]);
    if (!data)
    {
        std::cerr << "Error: Data.csv not found" << std::endl;
        return (1);
    }
    if (!input)
    {
        std::cerr << "Error: could not open file" << std::endl;
        return (1);
    }
    if (csv_check(data, &date))
    {
        std::cerr << "Error: data.csv is invalid" << std::endl;
        return (1);
    }
}