/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:09:52 by avallet           #+#    #+#             */
/*   Updated: 2023/12/06 14:54:49 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_H
# define CHARACTER_CLASS_H

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Character : public ICharacter
{
	public:
		Character(void);
		Character(Character const & src);
		Character(std::string const & name);
		~Character(void);

		Character &	operator=(Character const & src);

		std::string const &	getName(void) const;
		void				setName(std::string const & newName);
		void				equip(AMateria * m);
		void				unequip(int	idx);
		void				use(int idx, ICharacter & target);
		void				InvDisplay(void) const;

	private:
		static int const	_inventorySize = 4;
		std::string	_name;
		AMateria *	_inventory[_inventorySize];

		void	_initInvent(void);
		void	_deleteInventory(void);
};

#endif