/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:54:59 by avallet           #+#    #+#             */
/*   Updated: 2023/12/04 16:55:46 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CAT_CLASS_H
# define CAT_CLASS_H

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const & src);
		~Cat(void);

		Cat &	operator=(Cat const & src);

		Brain *	getBrain(void) const;
		void	makeSound(void) const;
	
	private:
		Brain *	_brain;
};

#endif
