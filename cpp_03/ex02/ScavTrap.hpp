/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:48:36 by avallet           #+#    #+#             */
/*   Updated: 2023/11/30 13:48:37 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_CLASS_H
# define SCAVTRAP_CLASS_H

# include "ClapTrap.hpp"

# define SCAV_HIT_POINTS 100
# define SCAV_ENERGY_POINTS 50
# define SCAV_ATTACK_DAMAGE 20

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string & name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap(void);

		ScavTrap &	operator=(ScavTrap const & src);

		void	attack(std::string & target);
		void	guardGate(void);

	private:
		ScavTrap(void);
};

#endif