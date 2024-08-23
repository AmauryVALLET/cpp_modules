/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:09:33 by avallet           #+#    #+#             */
/*   Updated: 2023/12/06 16:38:45 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
#include <string>

AMateria::AMateria(void) : _type("unknown")
{
	std::cout <<  "AMateria default constructor called."  << std::endl;
	return ;
}

AMateria::AMateria(AMateria const & src) : _type(src._type)
{
	std::cout <<  "AMateria copy constructor called."  << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout <<  "AMateria type constructor called."  << std::endl;
	return ;
}

AMateria::~AMateria(void)
{
	std::cout <<  "AMateria destructor called."  << std::endl;
	return ;
}

AMateria &	AMateria::operator=(AMateria const & src)
{
	std::cout <<  "AMateria  operator overload called." 
		<< std::endl;
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

void	AMateria::use(ICharacter & target)
{
	std::cout <<  "* unknown materia used towards"
		<< target.getName() << " *"  << std::endl;
	return ;
}

std::string const &	AMateria::getType(void) const
{
	return (this->_type);
}
