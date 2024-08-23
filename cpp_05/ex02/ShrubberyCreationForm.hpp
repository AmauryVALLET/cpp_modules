/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:34:41 by avallet           #+#    #+#             */
/*   Updated: 2024/01/17 14:34:43 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_CLASS_H
# define SHRUBBERY_CREATION_FORM_CLASS_H

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm(std::string const & target);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & src);

		std::string const &	getTarget(void) const;

		void	beExecuted(void) const;

		static int const	gradeToSign = 145;
		static int const	gradeToExecute = 137;

	private:
		std::string					_target;
		static std::string const	_shrubbery;
};

#endif
