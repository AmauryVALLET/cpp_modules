/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:55:13 by avallet           #+#    #+#             */
/*   Updated: 2023/12/04 16:57:12 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void) : _type("Unidentified animal")
{
	std::cout <<  "Animal default constructor called."  << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const & src)
{
	std::cout <<  "Animal copy constructor called."  << std::endl;
	*this = src;
	return ;
}

// AAnimal::AAnimal(std::string const & type) : _type(type)
// {
// 	std::cout <<  "Animal type constructor called."  << std::endl;
// 	return ;
// }

AAnimal::~AAnimal(void)
{
	std::cout <<  "Animal destructor called."  << std::endl;
	return ;
}

AAnimal &	AAnimal::operator=(AAnimal const & src)
{
	std::cout <<  "Animal overload operator called."  << std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

// std::string const &	AAnimal::getType(void) const
// {
// 	return (this->_type);
// }

void	AAnimal::makeSound(void) const
{
	std::cout <<  this->_type << ":  Makes some noise "  << std::endl;
	return ;
}
