/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:54:44 by avallet           #+#    #+#             */
/*   Updated: 2023/12/04 16:57:12 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Animal.hpp"

#include <iostream>

Animal::Animal(void) : _type("Unidentified animal")
{
	std::cout <<  "Animal default constructor called."  << std::endl;
	return ;
}

Animal::Animal(Animal const & src)
{
	std::cout <<  "Animal copy constructor called."  << std::endl;
	*this = src;
	return ;
}

Animal::Animal(std::string const & type) : _type(type)
{
	std::cout <<  "Animal type constructor called."  << std::endl;
	return ;
}

Animal::~Animal(void)
{
	std::cout <<  "Animal destructor called."  << std::endl;
	return ;
}

Animal &	Animal::operator=(Animal const & src)
{
	std::cout <<  "Animal overload operator called."  << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

std::string const &	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << this->_type << ": makes some noise"  << std::endl;
	return ;
}
