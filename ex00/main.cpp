/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:06:10 by aammirat          #+#    #+#             */
/*   Updated: 2025/01/15 10:43:24 by aammirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <string>
#include "BitcoinExchange.hpp"

int main (int argc, char *argv[])
{
    std::ifstream data("data.csv");
    if (argc != 2)
    {
        std::cerr << "Error: could not open file" << std::endl;
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
    BitcoinExchange btc(data);
    btc.BitcoinCalc(input);
}