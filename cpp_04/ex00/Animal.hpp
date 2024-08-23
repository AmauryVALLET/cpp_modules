/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:54:12 by avallet           #+#    #+#             */
/*   Updated: 2023/12/04 16:55:46 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ANIMAL_CLASS_H
# define ANIMAL_CLASS_H

# include <string>

class Animal
{
	public:
		Animal(void);
		Animal(Animal const & src);
		Animal(std::string const & type);
		virtual ~Animal(void);

		Animal &	operator=(Animal const & src);

		std::string const &	getType(void) const;
		virtual void		makeSound(void) const;

	protected:
		std::string	_type;
};

#endif
