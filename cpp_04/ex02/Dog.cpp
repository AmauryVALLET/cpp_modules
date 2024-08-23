/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:55:33 by avallet           #+#    #+#             */
/*   Updated: 2023/12/04 16:57:12 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "Dog.hpp"
#include <string>
#include <iostream>

Dog::Dog(void) : AAnimal(), _brain(new Brain())
{
	std::cout <<  "Dog default constructor called."  << std::endl;
	this->_type = "Dog";
	return ;
}

Dog::Dog(Dog const & src) : AAnimal(), _brain(NULL)
{
	std::cout <<  "Dog copy constructor called."  << std::endl;
	*this = src;
	return ;
}

Dog::~Dog(void)
{
	std::cout <<  "Dog destructor called."  << std::endl;
	delete this->_brain;
	return ;
}

Dog &	Dog::operator=(Dog const & src)
{
	std::cout <<  "Dog overload operator called."  << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		if (this->_brain != NULL)
			delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Brain *	Dog::getBrain(void) const
{
	return (this->_brain);
}

void	Dog::makeSound(void) const
{
	std::cout  << this->_type << ":  barking"  << std::endl;
	return ;
}
