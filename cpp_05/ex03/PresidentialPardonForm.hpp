/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:35:32 by avallet           #+#    #+#             */
/*   Updated: 2024/01/17 14:35:33 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRESIDENTIAL_PARDON_FORM_CLASS_H
# define PRESIDENTIAL_PARDON_FORM_CLASS_H

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm(std::string const & target);
		~PresidentialPardonForm(void);

		PresidentialPardonForm &	operator=(PresidentialPardonForm const & src);

		std::string const &	getTarget(void) const;

		void	beExecuted(void) const;

		static int const	gradeToSign = 25;
		static int const	gradeToExecute = 5;

	private:
		std::string	_target;
};

#endif