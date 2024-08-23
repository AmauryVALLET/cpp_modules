/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:55:26 by avallet           #+#    #+#             */
/*   Updated: 2023/12/04 17:07:00 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Cat.hpp"

#include <string>
#include <iostream>

Cat::Cat(void) : AAnimal(), _brain(new Brain())
{
	std::cout <<  "Cat default constructor called."  << std::endl;
	this->_type = "Cat";
	return ;
}

Cat::Cat(Cat const & src) : AAnimal(), _brain(NULL) 
{
	std::cout <<  "Cat copy constructor called."  << std::endl;
	*this = src;
	return ;
}

Cat::~Cat(void)
{
	std::cout <<  "Cat destructor called."  << std::endl;
	delete this->_brain;
	return ;
}

Cat &	Cat::operator=(Cat const & src)
{
	std::cout <<  "Cat overload operator called."  << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
		if (this->_brain != NULL)
			delete (this->_brain);
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

Brain *	Cat::getBrain(void) const
{
	return (this->_brain);
}

void	Cat::makeSound(void) const
{
	std::cout  << this->_type << ": Meows "  << std::endl;
	return ;
}

