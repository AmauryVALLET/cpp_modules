/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:10:01 by avallet           #+#    #+#             */
/*   Updated: 2023/12/06 14:10:37 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_MATERIA_CLASS_H
# define CURE_MATERIA_CLASS_H

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const & src);
		~Cure(void);

		Cure &	operator=(Cure const & src);

		AMateria *	clone(void) const;
		void		use(ICharacter & target);
};

#endif