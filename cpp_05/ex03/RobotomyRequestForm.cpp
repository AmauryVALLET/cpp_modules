/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:35:37 by avallet           #+#    #+#             */
/*   Updated: 2024/01/17 14:35:38 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>



RobotomyRequestForm::RobotomyRequestForm(void)
		:	AForm("Robotomy Request Form",
					RobotomyRequestForm::gradeToSign,
					RobotomyRequestForm::gradeToExecute),
			_target("Unknown")
{
	std::cout <<  "RobotomyRequestForm default constructor called."
		 << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
		:	AForm(src),
			_target(src._target)
{
	std::cout <<  "RobotomyRequestForm copy constructor called."
		 << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
		:	AForm("Robotomy Request Form",
					RobotomyRequestForm::gradeToSign,
					RobotomyRequestForm::gradeToExecute),
			_target(target)
{
	std::cout <<  "RobotomyRequestForm attribute constructor called."
		 << std::endl;
	if (_target.empty())
		_target = "Unknown";
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout <<  "RobotomyRequestForm destructor called."
		 << std::endl;
	return ;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(
									RobotomyRequestForm const & src)
{
	this->_target = src._target;
	return (*this);
}

std::string const &	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void	RobotomyRequestForm::beExecuted(void) const
{
	std::cout << "Robot request sent..." << std::endl;
	if (std::rand() % 2)
		std::cout << this->_target << " successfully robotomized!" << std::endl;
	else
		std::cout << this->_target << " failed to robotomize..." << std::endl;
	return ;
}
