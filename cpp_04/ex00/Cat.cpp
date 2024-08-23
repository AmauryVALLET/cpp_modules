/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:54:15 by avallet           #+#    #+#             */
/*   Updated: 2023/12/06 17:46:52 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <string>
#include <iostream>

Cat::Cat(void) : Animal()
{
	std::cout <<  "Cat default constructor called."  << std::endl;
	this->_type = "Cat";
	return ;
}

Cat::Cat(Cat const & src) : Animal() 
{
	std::cout <<  "Cat copy constructor called."  << std::endl;
	*this = src;
	return ;
}

Cat::~Cat(void)
{
	std::cout <<  "Cat destructor called."  << std::endl;
	return ;
}

Cat &	Cat::operator=(Cat const & src)
{
	std::cout <<  "Cat overload operator called."  << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout <<  this->_type << ":  meows "  << std::endl;
	return ;
}

