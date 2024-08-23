/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:33:11 by avallet           #+#    #+#             */
/*   Updated: 2023/11/21 09:56:37 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "HumanA.hpp"




HumanA::HumanA( std::string const aName, Weapon const &aWeapon ): _name( aName ),	_weapon( aWeapon )
{
	std::cout << this->_name << " constructed!" << std::endl;
	return ;
}



HumanA::~HumanA( void )
{
	std::cout << this->_name << " destructed";
	if ( !(this->_weapon.getType().empty()) )
		std::cout << " with " << this->_weapon.getType();
	std::cout << std::endl;
	return ;
}



void	HumanA::attack( void ) const
{
	std::cout << this->_name << " attacks with their ";
	if ( this->_weapon.getType() == "" )
		std::cout << "bare knuckles!";
	else
		std::cout << this->_weapon.getType();
	std::cout << std::endl;
	return ;
}
