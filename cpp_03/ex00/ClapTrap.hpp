/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:46:58 by avallet           #+#    #+#             */
/*   Updated: 2023/11/30 13:47:00 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

# include <string>

class ClapTrap
{
	public:
		static unsigned int const	maxHitPoints = 10;
		static unsigned int const	allAccessEnergyPoints = 10;
		static unsigned int const	maxAttackDamage = 0;

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

	private:
		ClapTrap(void);
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif
