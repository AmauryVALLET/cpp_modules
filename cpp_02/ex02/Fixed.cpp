/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:38:01 by avallet           #+#    #+#             */
/*   Updated: 2024/08/23 17:36:00 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <cmath>
#include "Fixed.hpp"


Fixed::Fixed( void ) : _raw( 0 )
{
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	*this = src;
	return ;
}

Fixed::Fixed( int const n ) : _raw( n << _fractionalBits )
{
	return ;
}

Fixed::Fixed( float const f ) : _raw( roundf(f * (1 << _fractionalBits)) )
{
	return ;
}

Fixed::~Fixed( void )
{
	return ;
}



Fixed &	Fixed::operator=( Fixed const & src )
{
	if ( this != &src )
		this->_raw = src.getRawBits();
	return ( *this );
}



bool	Fixed::operator>( Fixed const & src ) const
{
	if ( this->_raw > src.getRawBits() )
		return ( true );
	return ( false );
}

bool	Fixed::operator<( Fixed const & src ) const
{
	if ( this->_raw < src.getRawBits() )
		return ( true );
	return ( false );
}

bool	Fixed::operator>=( Fixed const & src ) const
{
	if ( this->_raw >= src.getRawBits() )
		return ( true );
	return ( false );
}

bool	Fixed::operator<=( Fixed const & src ) const
{
	if ( this->_raw <= src.getRawBits() )
		return ( true );
	return ( false );
}

bool	Fixed::operator==( Fixed const & src ) const
{
	if ( this->_raw == src.getRawBits() )
		return ( true );
	return ( false );
}

bool	Fixed::operator!=( Fixed const & src ) const
{
	if ( this->_raw != src.getRawBits() )
		return ( true );
	return ( false );
}

Fixed	Fixed::operator+( Fixed const & src ) const
{
	return ( Fixed( this->toFloat() + src.toFloat() ) );
}

Fixed	Fixed::operator-( Fixed const & src ) const
{
	return ( Fixed( this->toFloat() - src.toFloat() ) );
}

Fixed	Fixed::operator*( Fixed const & src ) const
{
	return ( Fixed( this->toFloat() * src.toFloat() ) );
}

Fixed	Fixed::operator/( Fixed const & src ) const
{
	return ( Fixed( this->toFloat() / src.toFloat() ) );
}

Fixed &	Fixed::operator++( void )
{
	this->_raw += 1;
	return ( *this );
}

Fixed Fixed::operator++( int )
{
	Fixed	tmp( *this );

	++(*this);
	return ( tmp );
}

Fixed &	Fixed::operator--( void )
{
	this->_raw -= 1;
	return ( *this );
}

Fixed Fixed::operator--( int )
{
	Fixed	tmp( *this );

	--(*this);
	return ( tmp );
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

Fixed &	Fixed::min( Fixed & left, Fixed & src )
{
	if ( left <= src )
		return ( left );
	return ( src );
}

Fixed const &	Fixed::min( Fixed const & left, Fixed const & src )
{
	if ( left <= src )
		return ( left );
	return ( src );
}

Fixed &	Fixed::max( Fixed & left, Fixed & src )
{
	if ( left >= src )
		return ( left );
	return ( src );
}

Fixed const &	Fixed::max( Fixed const & left, Fixed const & src )
{
	if ( left >= src )
		return ( left );
	return ( src );
}

std::ostream& operator<<( std::ostream& os, const Fixed& number )
{
	os << number.toFloat();
	return ( os );
}