/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:11:58 by aammirat          #+#    #+#             */
/*   Updated: 2025/01/17 16:32:32 by aammirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>

class RPN
{
    private : 
        std::stack<char> _stak;
        std::stack<char> _buff;
        std::stack<int> _calc;
    public : 
        RPN(char *tab);
        ~RPN();
        RPN(const RPN &copy);
        RPN& operator=(const RPN &copy);
        void resolve();
        void minus();
        void add();
        void mult();
        void divide();
        class InvalidInput : public std::exception { public : const char * what() const throw();};
        class InvalidOperation : public std::exception { public : const char * what() const throw();};
        class ZeroDivision : public std::exception { public : const char * what() const throw();};
};

#endif