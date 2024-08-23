/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:33:21 by avallet           #+#    #+#             */
/*   Updated: 2023/11/21 10:24:00 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_H
# define WEAPON_CLASS_H

# include <string>


class	Weapon
{
	private:
		std::string	_type;

	public:
		Weapon( std::string const type );
		~Weapon( void );

		// 		&: ref evite accidents/check de desalloc/ptr null (& ne peut pas ê NULL)  
		std::string const	&getType( void ) const;
		void				setType( std::string const newType );
};

#endif