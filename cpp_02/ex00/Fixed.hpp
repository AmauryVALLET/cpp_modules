/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:38:05 by avallet           #+#    #+#             */
/*   Updated: 2024/08/23 17:34:19 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

class Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed const & src);
		~Fixed( void );

		Fixed &	operator=( Fixed const & src);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_raw;
		static const int	_fractionalBits = 8;
};

#endif