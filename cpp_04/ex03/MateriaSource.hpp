/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:10:31 by avallet           #+#    #+#             */
/*   Updated: 2023/12/06 15:13:02 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_CLASS_H
# define MATERIASOURCE_CLASS_H

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		~MateriaSource(void);

		MateriaSource &	operator=(MateriaSource const & src);

		void		learnMateria(AMateria * m);
		AMateria *	createMateria(std::string const & type);
		void		displayKnownMaterias(void);

	private:
		static int const	_maxMaterias = 4;
		AMateria *	_Materias[_maxMaterias];

		void	_initializeEmptyMaterias(void);
		void	_deleteMaterias(void);
};

#endif