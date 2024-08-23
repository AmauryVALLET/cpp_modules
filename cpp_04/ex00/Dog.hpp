/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:54:23 by avallet           #+#    #+#             */
/*   Updated: 2023/12/06 17:47:01 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_H
# define DOG_CLASS_H

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog const & src);
		~Dog(void);

		Dog &	operator=(Dog const & src);

		void	makeSound(void) const;
};

#endif
