/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:54:18 by avallet           #+#    #+#             */
/*   Updated: 2023/12/06 17:46:56 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_H
# define CAT_CLASS_H

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const & src);
		~Cat(void);

		Cat &	operator=(Cat const & src);

		void	makeSound(void) const;
};

#endif
