/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:48:18 by avallet           #+#    #+#             */
/*   Updated: 2023/11/30 13:48:19 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_CLASS_H
# define FRAGTRAP_CLASS_H

#include "ClapTrap.hpp"

# define FRAG_HIT_PTS 100
# define FRAGT_ENERGY_PTS 100
# define FRAG_ATCK_DAMAGE 30

class FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string & name);
		FragTrap(FragTrap const & src);
		~FragTrap(void);

		FragTrap &	operator=(FragTrap const & src);

		void	highFivesGuys(void);

	private:
		FragTrap(void);
};

#endif