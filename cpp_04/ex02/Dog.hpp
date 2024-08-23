/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:55:36 by avallet           #+#    #+#             */
/*   Updated: 2023/12/04 16:55:46 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef DOG_CLASS_H
# define DOG_CLASS_H

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog(void);
		Dog(Dog const & src);
		~Dog(void);

		Dog &	operator=(Dog const & src);

		Brain *	getBrain(void) const;
		void	makeSound(void) const;

	private:
		Brain *	_brain;
};

#endif
