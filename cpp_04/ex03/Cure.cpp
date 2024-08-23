/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:09:56 by avallet           #+#    #+#             */
/*   Updated: 2023/12/06 16:37:57 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void) : AMateria("cure")
{
	std::cout <<  "Cure default constructor called."  << std::endl;
	return ;
}

Cure::Cure(Cure const & src) : AMateria("cure")
{
	std::cout <<  "Cure copy constructor called."  << std::endl;
	*this = src;
	return ;
}

Cure::~Cure(void)
{
	std::cout <<  "Cure destructor called."  << std::endl;
	return ;
}

Cure &	Cure::operator=(Cure const & src)
{
	std::cout <<  "Cure  operator called."  << std::endl;
	this->_type = src._type;
	return (*this);
}

AMateria *	Cure::clone(void) const
{
	AMateria *	cureClone = new Cure();
	return (cureClone);
}

void	Cure::use(ICharacter & target)
{
	std::cout <<  "* heals " << target.getName() << "'s wounds *" 
		<< std::endl;
}
