/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:38:01 by avallet           #+#    #+#             */
/*   Updated: 2023/11/23 15:34:45 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"


Fixed::Fixed( void ) : _raw( 0 )
{
	std::cerr << "Default constructor called."  << std::endl;
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	std::cerr << "Copy constructor called."  << std::endl;
	*this = src;
	return ;
}

Fixed::~Fixed( void )
{
	std::cerr << "Destructor called."  << std::endl;
	return ;
}

Fixed &	Fixed::operator=( Fixed const & src )
{
	std::cerr << "Copy assignment operator called."  << std::endl;
	if ( this != &src )
		this->_raw = src.getRawBits();
	return ( *this );
}


int	Fixed::getRawBits( void ) const
{
	std::cerr << "getRawBits member function called."  << std::endl;
	return ( this->_raw );
}

void	Fixed::setRawBits( int const raw )
{
	std::cerr << "setRawBits member funtion called."  << std::endl;
	this->_raw = raw;
	return ;
}
