/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:38:05 by avallet           #+#    #+#             */
/*   Updated: 2024/08/23 17:34:44 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

class Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed const & src);
		Fixed (int const i);
		Fixed (float const f);
		~Fixed( void );

		Fixed &	operator=( Fixed const & src);
		float 	toFloat( void ) const;
		int 	toInt( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_raw;
		static const int	_fractionalBits = 8;
};

std::ostream& operator<<( std::ostream& os, const Fixed& number );


#endif