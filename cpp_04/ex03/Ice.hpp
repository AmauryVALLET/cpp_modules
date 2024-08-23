/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:10:10 by avallet           #+#    #+#             */
/*   Updated: 2023/12/06 14:10:37 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_MATERIA_CLASS_H
# define ICE_MATERIA_CLASS_H

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const & src);
		~Ice(void);

		Ice	&	operator=(Ice const & src);

		AMateria *	clone(void) const;
		void		use(ICharacter & target);
};

#endif