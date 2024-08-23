/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:01:44 by avallet           #+#    #+#             */
/*   Updated: 2024/08/23 17:24:35 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

# include <string>

class	Zombie
{
	
	private:
		std::string	_name;
		std::string	_getName(void) const;



	public:
		Zombie(std::string name);
		~Zombie(void);
		void		announce(void);
};

#endif