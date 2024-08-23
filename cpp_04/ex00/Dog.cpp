/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:54:20 by avallet           #+#    #+#             */
/*   Updated: 2023/12/04 16:57:12 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Dog.hpp"
#include <string>
#include <iostream>

Dog::Dog(void) : Animal("Dog")
{
	std::cout <<  "Dog default constructor called."  << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::Dog(Dog const & src) : Animal(src._type)
{
	std::cout <<  "Dog copy constructor called."  << std::endl;
	*this = src;
	return ;
}

Dog::~Dog(void)
{
	std::cout <<  "Dog destructor called."  << std::endl;
	return ;
}

Dog &	Dog::operator=(Dog const & src)
{
	std::cout <<  "Dog overload operator called."  << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->_type << ": dog barking"  << std::endl;
	return ;
}
