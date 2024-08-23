/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:35:02 by avallet           #+#    #+#             */
/*   Updated: 2024/01/17 14:35:03 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

# include "AForm.hpp"
# include <string>

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat(std::string const & name, int grade);
		~Bureaucrat(void);

		Bureaucrat &	operator=(Bureaucrat const & src);

		std::string const &	getName(void) const;
		int					getGrade(void) const;

		void	incrementGrade(void);
		void	incrementGrade(int i);
		void	decrementGrade(void);
		void	decrementGrade(int i);

		void	signForm(AForm & form) const;
		void	executeForm(AForm & form) const;

		static int const	highestGrade = 1;
		static int const	lowestGrade = 150;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

	private:
		std::string const	_name;
		int					_grade;

};

std::ostream &	operator<<(std::ostream & os, Bureaucrat const & obj);

#endif