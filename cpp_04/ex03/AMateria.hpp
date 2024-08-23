/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:09:40 by avallet           #+#    #+#             */
/*   Updated: 2023/12/06 16:35:06 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_CLASS_H
# define AMATERIA_CLASS_H

# include "ICharacter.hpp"
# include <string>

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
		
	public:
		AMateria(void);
		AMateria(AMateria const & src);
		AMateria(std::string const & type);
		//virtual destruct == si suppr obj derivee depuis classe de base
		virtual ~AMateria(void);

		AMateria &	operator=(AMateria const & src);

		std::string const & getType(void) const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter & target);
};

#endif
