/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:54:40 by avallet           #+#    #+#             */
/*   Updated: 2023/12/04 16:55:46 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef WRONG_CAT_CLASS_H
# define WRONG_CAT_CLASS_H

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const & src);
		~WrongCat(void);

		WrongCat &	operator=(WrongCat const & src);

		void	makeSound(void) const;
};

#endif
