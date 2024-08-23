/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:10:06 by avallet           #+#    #+#             */
/*   Updated: 2023/12/06 16:37:57 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ice.hpp"
#include <iostream>

Ice::Ice(void) : AMateria("ice")
{
	std::cout <<  "Ice default constructor called."  << std::endl;
	return ;
}

Ice::Ice(Ice const & src) : AMateria("ice")
{
	std::cout <<  "Ice copy constructor called."  << std::endl;
	*this = src;
	return ;
}

Ice::~Ice(void)
{
	std::cout <<  "Ice destructor called."  << std::endl;
	return ;
}

Ice &	Ice::operator=(Ice const & src)
{
	std::cout <<  "Ice  operator called."  << std::endl;
	this->_type = src._type;
	return (*this);
}

AMateria *	Ice::clone(void) const
{
	AMateria *	iceClone = new Ice();
	return (iceClone);
}

void	Ice::use(ICharacter & target)
{
	std::cout <<  "* shoots an ice bolt at " << target.getName() << " *"
		 << std::endl;
}
