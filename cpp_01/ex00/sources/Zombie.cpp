/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:01:40 by avallet           #+#    #+#             */
/*   Updated: 2023/11/21 09:55:41 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name(name)
{
	std::cout << this->_getName() << " has been created" << std::endl;
	return ;
}

Zombie::~Zombie( void )
{
	std::cout << this->_getName()
			<< ": died"
			<< std::endl;
	return ;
}


std::string Zombie::_getName( void ) const
{
	return ( this->_name );
}


void	Zombie::announce( void )
{
	std::cout << this->_getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}