/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:10:18 by avallet           #+#    #+#             */
/*   Updated: 2023/12/06 14:10:37 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_CLASS_H
# define IMATERIASOURCE_CLASS_H

# include "AMateria.hpp"
# include <string>

class IMateriaSource
{
	public:
		virtual ~IMateriaSource(void) {}

		virtual void		learnMateria(AMateria * m) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif