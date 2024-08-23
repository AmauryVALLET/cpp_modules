/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:10:14 by avallet           #+#    #+#             */
/*   Updated: 2023/12/06 14:10:37 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_CLASS_H
# define ICHARACTER_CLASS_H

# include "AMateria.hpp"
# include <string>

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter(void) {}

		virtual std::string const & getName(void) const = 0;
		virtual void equip(AMateria * m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif