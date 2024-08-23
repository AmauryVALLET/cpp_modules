/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:33:24 by avallet           #+#    #+#             */
/*   Updated: 2023/11/21 09:56:25 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_CLASS_H
# define HUMAN_B_CLASS_H

# include <string>
# include "Weapon.hpp"

class	HumanB
{
	private:
		Weapon				*_weapon;
		std::string const	_name;

	public:
		HumanB( std::string const aName );
		~HumanB( void );
		void	attack( void ) const;
		void	setWeapon( Weapon &aWeapon );
};

#endif