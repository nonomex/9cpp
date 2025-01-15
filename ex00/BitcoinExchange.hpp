/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:41:45 by aammirat          #+#    #+#             */
/*   Updated: 2025/01/15 13:44:41 by aammirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_HPP
# define BITCOIN_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib> 
#include <sstream>

class BitcoinExchange
{
    private : 
        std::map<std::string, float> data;
        
    public :
        BitcoinExchange(std::ifstream &file);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange & copy);
        BitcoinExchange &operator=(const BitcoinExchange &copy);
        void    BitcoinCalc(std::ifstream &file);
};

#endif