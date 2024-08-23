/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:55:16 by avallet           #+#    #+#             */
/*   Updated: 2023/12/04 17:08:46 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef AANIMAL_CLASS_H
# define AANIMAL_CLASS_H

# include <string>

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(AAnimal const & src);
		// AAnimal(std::string const & type);
		virtual ~AAnimal(void);

		AAnimal &	operator=(AAnimal const & src);

		// std::string const &	getType(void) const;
		virtual void		makeSound(void) const;

	protected:
		std::string	_type;
};

#endif
