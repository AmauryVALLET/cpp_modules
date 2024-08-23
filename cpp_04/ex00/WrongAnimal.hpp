/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:54:34 by avallet           #+#    #+#             */
/*   Updated: 2023/12/04 16:55:46 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef WRONG_ANIMAL_CLASS_H
# define WRONG_ANIMAL_CLASS_H

# include <string>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal(std::string const & type);
		virtual ~WrongAnimal(void);

		WrongAnimal &	operator=(WrongAnimal const & src);

		std::string const &	getType(void) const;
		void		makeSound(void) const;

	protected:
		std::string	_type;
};

#endif
