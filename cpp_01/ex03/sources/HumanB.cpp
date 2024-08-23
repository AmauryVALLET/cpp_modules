/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:33:06 by avallet           #+#    #+#             */
/*   Updated: 2023/11/21 11:50:38 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "HumanB.hpp"



HumanB::HumanB( std::string const aName ) : _weapon( NULL ), _name( aName )
{
	std::cout << this->_name << " constructed" << std::endl;
	return ;
}

HumanB::~HumanB( void )
{
	std::cout << this->_name << " destructed!" << std::endl;
	return ;
}







void	HumanB::setWeapon( Weapon &aWeapon )
{
	if ( aWeapon.getType().empty() )
	{
		if ( this->_weapon == NULL || this->_weapon->getType().empty() )
			std::cout << this->_name << " failed to pick up weapon" << std::endl;
		else
			std::cout << this->_name << " drops its weapon" << std::endl;
	}
	else
	{
		if ( this->_weapon == NULL || this->_weapon->getType().empty() )
			std::cout << this->_name << " picks up a " << aWeapon.getType() << std::endl;
		else
			std::cout << this->_name << " changed to a " << aWeapon.getType() << std::endl;
	}
	if ( aWeapon.getType().empty() )
		this->_weapon = NULL;
	else
		this->_weapon = &aWeapon;
	return ;
}





void	HumanB::attack( void ) const
{
	std::cout << this->_name << " attacks with their ";
	if ( this->_weapon != NULL && this->_weapon->getType() != "" )
		std::cout << this->_weapon->getType();
	else
		std::cout << "bare knuckles!";	
	std::cout << std::endl;
	return ;
}
