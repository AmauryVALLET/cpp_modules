/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:06:22 by avallet           #+#    #+#             */
/*   Updated: 2024/08/23 17:24:59 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

#include <string>

class Zombie
{

	
	private:
		std::string	_name;
		std::string _getName( void ) const;



	public:
		Zombie(void);
		~Zombie();
		void	setName( std::string const name );
		void	announce( void );
};

#endif