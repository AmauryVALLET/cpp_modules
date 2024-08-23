/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:35:41 by avallet           #+#    #+#             */
/*   Updated: 2024/01/17 14:35:42 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ROBOTOMY_REQUEST_FORM_CLASS_H
# define ROBOTOMY_REQUEST_FORM_CLASS_H

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm(std::string const & target);
		~RobotomyRequestForm(void);

		RobotomyRequestForm &	operator=(RobotomyRequestForm const & src);

		std::string const &	getTarget(void) const;

		void	beExecuted(void) const;

		static int const	gradeToSign = 72;
		static int const	gradeToExecute = 45;

	private:
		std::string	_target;
};

#endif
