/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:07:05 by avallet           #+#    #+#             */
/*   Updated: 2023/11/21 09:56:04 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name )
{
	if ( N <= 0 )
		return ( NULL );
	Zombie	*aZombieHorde = new Zombie[N];
	
	for (int i = 0; i < N; i++) {
		aZombieHorde[i].setName( name );
	}
	return ( aZombieHorde );
}