/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:33:28 by avallet           #+#    #+#             */
/*   Updated: 2023/11/21 09:56:18 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_CLASS_H
# define HUMAN_A_CLASS_H

# include <string>
# include "Weapon.hpp"

class	HumanA
{
	private:
		std::string const	_name;
		Weapon const 		&_weapon;
		
	public:
		HumanA( std::string const aName, Weapon const &aWeapon );
		~HumanA( void );

		void	attack( void ) const;
};

#endif