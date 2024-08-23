/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:38:01 by avallet           #+#    #+#             */
/*   Updated: 2024/08/23 17:34:40 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"



Fixed::Fixed( void ) : _raw( 0 )
{
	std::cerr <<  "Default constructor called."  << std::endl;
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	std::cerr <<  "Copy constructor called."  << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed( int const n ) : _raw( n << _fractionalBits )
{
	std::cerr <<  "Int constructor called."  << std::endl;
	return ;
}

Fixed::Fixed( float const f ) : _raw( roundf(f * (1 << _fractionalBits)) )
{
	std::cerr <<  "Float constructor called."  << std::endl;
	return ;
}

Fixed::~Fixed( void )
{
	std::cerr <<  "Destructor called."  << std::endl;
	return ;
}

Fixed &	Fixed::operator=( Fixed const & src )
{
	std::cerr <<  "Copy assignment operator called."  << std::endl;
	if ( this != &src )
		this->_raw = src.getRawBits();
	return ( *this );
}


int	Fixed::getRawBits( void ) const
{
	return ( this->_raw );
}


void	Fixed::setRawBits( int const raw )
{
	this->_raw = raw;
	return ;
}

int		Fixed::toInt( void ) const
{
	return ( this->_raw >> Fixed::_fractionalBits );	
}

float	Fixed::toFloat( void ) const
{
	return ( (float)this->_raw / (1 << _fractionalBits) );
}

std::ostream& operator<<( std::ostream& out, const Fixed& number )
{
	out << number.toFloat();
	return ( out );
}