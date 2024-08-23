/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:54:37 by avallet           #+#    #+#             */
/*   Updated: 2023/12/04 16:57:12 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "WrongCat.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout <<  "WrongCat default constructor called."  << std::endl;
	this->_type = "WrongCat";
	return ;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal() 
{
	std::cout <<  "WrongCat copy constructor called."  << std::endl;
	*this = src;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout <<  "WrongCat destructor called."  << std::endl;
	return ;
}

WrongCat &	WrongCat::operator=(WrongCat const & src)
{
	std::cout <<  "WrongCat overload operator called."  << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << this->_type << ": WCMeow "  << std::endl;
	return ;
}

