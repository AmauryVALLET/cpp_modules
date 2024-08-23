/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:34:36 by avallet           #+#    #+#             */
/*   Updated: 2024/01/17 14:34:38 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>



ShrubberyCreationForm::ShrubberyCreationForm(void)
		:	AForm("Shrubbery Creation Form",
					ShrubberyCreationForm::gradeToSign,
					ShrubberyCreationForm::gradeToExecute),
			_target("Unknown")
{
	std::cout <<  "ShrubberyCreationForm default constructor called."
		 << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
		:	AForm(src),
			_target(src._target)
{
	std::cout <<  "ShrubberyCreationForm copy constructor called."
		 << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
		:	AForm("Shrubbery Creation Form",
					ShrubberyCreationForm::gradeToSign,
					ShrubberyCreationForm::gradeToExecute),
			_target(target)
{
	std::cout <<  "ShrubberyCreationForm attribute constructor called."
		 << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout <<  "ShrubberyCreationForm destructor called."
		 << std::endl;
	return ;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(
									ShrubberyCreationForm const & src)
{
	this->_target = src._target;
	return (*this);
}

std::string const &	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::beExecuted(void) const
{
	std::ofstream	ofs;

	ofs.open((this->_target + "_shrubbery").c_str(),
								std::ofstream::out | std::ofstream::app);
	if (ofs.is_open())
	{
		ofs << ShrubberyCreationForm::_shrubbery;
		std::cout << "A shrubbery has been planted at " << _target << "_shrubbery." << std::endl;
		ofs.close();
	}
	return ;
}

std::string const ShrubberyCreationForm::_shrubbery =
"\n"
"             0000000000000000000\n"
"                0000000000000\n"
"                  0000000\n"
"             0000000000000000000\n"
"                0000000000000\n"
"           00000000000000000000000\n"
"             0000000000000000000\n"
"                0000000000000\n"
"                  0000000\n"
"                    |||\n"
"                    |||\n"
"                    |||\n"
"                    |||\n"
"                    |||\n"
"                    |||\n"
"          __________|||_____________\n\n";
