/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:12:03 by aammirat          #+#    #+#             */
/*   Updated: 2025/01/17 16:36:09 by aammirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

const char * RPN::InvalidInput::what() const throw()
{
    return ("Error: Invalid Input");
}

const char * RPN::InvalidOperation::what() const throw()
{
    return ("Error: Invalid Operation");
}

const char * RPN::ZeroDivision ::what() const throw()
{
    return ("Error: Can't divide by 0");
}

static int IsValid(char c)
{
    if ((c >= '0' && c <= '9') || c == '-' || c == '+' || c == '/' || c == '*')
        return (1);
    return (0);
}

RPN::RPN(char *tab)
{
    int i;
    i = 0;
    while (tab[i])
    {
        if (tab[i] != ' ')
        {
             if (!IsValid(tab[i]))
                throw InvalidInput();
            else
            {
                _buff.push(tab[i]);
            }
        }
        i++;
    }
    while (!_buff.empty())
    {
        _stak.push(_buff.top());
        _buff.pop();
    }
}

RPN::RPN(const RPN & copy)
{
(void)copy;
}

RPN::~RPN()
{

}

RPN & RPN::operator=(const RPN & copy)
{
    (void)copy;
    return (*this);
}

void RPN::minus()
{
    int res;
    if (_calc.size() < 2)
        throw InvalidOperation();
    else
    {
        res = _calc.top();
        _calc.pop();
        res = _calc.top() - res;
        _calc.pop();
        _calc.push(res);   
    }
}

void RPN::add()
{
    int res;
    if (_calc.size() < 2)
        throw InvalidOperation();
    else
    {
        res = _calc.top();
        _calc.pop();
        res = res + _calc.top();
        _calc.pop();
        _calc.push(res);   
    }
}

void RPN::mult()
{
    int res;
    if (_calc.size() < 2)
        throw InvalidOperation();
    else
    {
        res = _calc.top();
        _calc.pop();
        res = res * _calc.top();
        _calc.pop();
        _calc.push(res);   
    }
}

void RPN::divide()
{
    int res;
    if (_calc.size() < 2)
        throw InvalidOperation();
    else
    {
        res = _calc.top();
        _calc.pop();
        if (res == 0)
            throw ZeroDivision();
        else
        {
            res = _calc.top() / res;
            _calc.pop();
            _calc.push(res);
        }
    }
}

void RPN::resolve()
{
    while (!_stak.empty())
    {
        if (_stak.top() >= '0' && _stak.top() <= '9')
            _calc.push(_stak.top() - 48);
        else if (_stak.top() == '-')
            minus();
        else if (_stak.top() == '+')
            add();
        else if (_stak.top() == '/')
            divide();
        else
            mult();
        _stak.pop();
    }
    if (_calc.size() == 1)
        std::cout << _calc.top() << std::endl;
    else
        throw InvalidOperation();
}

