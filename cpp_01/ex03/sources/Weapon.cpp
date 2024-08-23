/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:33:18 by avallet           #+#    #+#             */
/*   Updated: 2023/11/21 09:56:55 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>


Weapon::Weapon( std::string const type ) : _type( type )
{
	return ;
}

Weapon::~Weapon( void )
{
	return ;
}




std::string const	&Weapon::getType( void ) const
{
	return ( this->_type );
}






void	Weapon::setType( std::string const newType )
{
	if ( newType.empty() && !(this->getType().empty()) )
		std::cout << "The " << this->getType() << " broke!" << std::endl;
	else if ( !(this->getType().empty()) )
		std::cout << "The " << this->getType() << " has been switched for " << newType << std::endl;
	else
		std::cout << "A " << newType << " has been picked up!" << std::endl;
	this->_type = newType;
	return ;
}
