/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:54:53 by avallet           #+#    #+#             */
/*   Updated: 2023/12/04 16:55:46 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef BRAIN_CLASS_H
# define BRAIN_CLASS_H

# include <string>

class Brain
{
	public:
		Brain(void);
		Brain(Brain const & src);
		~Brain(void);

		Brain &	operator=(Brain const & src);

		std::string const &	getIdea(int index) const;
		void				setIdea(int index, std::string const & idea);

		static int const	nb_ideas = 100;

	private:
		std::string	_ideas[nb_ideas];
};

#endif
