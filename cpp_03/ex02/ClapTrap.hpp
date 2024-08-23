/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:48:06 by avallet           #+#    #+#             */
/*   Updated: 2023/11/30 13:48:07 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

# include <string>

# define CLAP_HIT_POINTS 10
# define CLAP_ENERGY_POINTS 10
# define CLAP_ATTACK_DAMAGE 0

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap(void);

		ClapTrap &	operator=(ClapTrap const & src);
		
		std::string		getName(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
		unsigned int	getAttackDamage(void) const;
		
		void		attack(std::string & target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	protected:
		ClapTrap(void);

		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		unsigned int	_maxHitPoints;
		unsigned int	_maxEnergyPoints;
		unsigned int	_maxAttackDamage;
};

#endif