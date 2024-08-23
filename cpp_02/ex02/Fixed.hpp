/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:38:05 by avallet           #+#    #+#             */
/*   Updated: 2024/08/23 17:35:25 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

# include <iostream>

class Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed const & src);
		Fixed( int const n );
		Fixed( float const f );
		~Fixed( void );

		Fixed &	operator=( Fixed const & src);


		bool	operator>( Fixed const & src ) const;
		bool	operator<( Fixed const & src ) const;
		bool	operator>=( Fixed const & src ) const;
		bool	operator<=( Fixed const & src ) const;
		bool	operator==( Fixed const & src ) const;
		bool	operator!=( Fixed const & src ) const;

		Fixed	operator+( Fixed const & src ) const;
		Fixed	operator-( Fixed const & src ) const;
		Fixed	operator*( Fixed const & src ) const;
		Fixed	operator/( Fixed const & src ) const;

		Fixed &	operator++( void );
		Fixed	operator++( int	);
		Fixed &	operator--( void );
		Fixed	operator--( int );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed &			min( Fixed & left, Fixed & src );
		static Fixed &			max( Fixed & left, Fixed & src );
		static Fixed const &	min( Fixed const & left, Fixed const & src );
		static Fixed const &	max( Fixed const & left, Fixed const & src );

	private:
		int					_raw;
		static const int	_fractionalBits = 8;
};

std::ostream & operator<<( std::ostream & os, const Fixed & number );

#endif