/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:06:45 by avallet           #+#    #+#             */
/*   Updated: 2023/11/21 10:19:45 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"


Zombie::Zombie( void )
{
	std::cout << "new zombie created" << std::endl;
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << this->_getName() << ": is dead" << std::endl;
	return ;
}


std::string Zombie::_getName( void ) const
{
	return (this->_name);
}

void	Zombie::setName( std::string const name )
{
	this->_name = name;
	return ;
}


void	Zombie::announce( void )
{
	std::cout << this->_getName() << " speaking: BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}