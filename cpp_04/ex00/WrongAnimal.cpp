/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:54:30 by avallet           #+#    #+#             */
/*   Updated: 2023/12/04 16:57:12 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("Unidentified animal")
{
	std::cout <<  "WrongAnimal default constructor called."  << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout <<  "WrongAnimal copy constructor called."  << std::endl;
	*this = src;
	return ;
}

WrongAnimal::WrongAnimal(std::string const & type) : _type(type)
{
	std::cout <<  "WrongAnimal type constructor called."  << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout <<  "WrongAnimal destructor called."  << std::endl;
	return ;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & src)
{
	std::cout <<  "WrongAnimal overload operator called."  << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

std::string const &	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout <<  this->_type << ":  makes some noise "  << std::endl;
	return ;
}
