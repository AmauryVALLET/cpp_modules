/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:34:18 by avallet           #+#    #+#             */
/*   Updated: 2024/01/17 14:34:20 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>


PresidentialPardonForm::PresidentialPardonForm(void)
		:	AForm("Presidential Pardon Form",
					PresidentialPardonForm::gradeToSign,
					PresidentialPardonForm::gradeToExecute),
			_target("Unknown")
{
	std::cout <<  "PresidentialPardonForm default constructor called."
		 << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
		:	AForm(src),
			_target(src._target)
{
	std::cout <<  "PresidentialPardonForm copy constructor called."
		 << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
		:	AForm("Presidential Pardon Form",
					PresidentialPardonForm::gradeToSign,
					PresidentialPardonForm::gradeToExecute),
			_target(target)
{
	std::cout <<  "PresidentialPardonForm attribute constructor called."
		 << std::endl;
	if (_target.empty())
		_target = "Unknown";
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout <<  "PresidentialPardonForm destructor called."
		 << std::endl;
	return ;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(
									PresidentialPardonForm const & src)
{
	this->_target = src._target;
	return (*this);
}

std::string const &	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void	PresidentialPardonForm::beExecuted(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return ;
}
