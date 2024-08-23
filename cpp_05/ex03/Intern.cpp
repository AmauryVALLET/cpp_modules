/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:35:08 by avallet           #+#    #+#             */
/*   Updated: 2024/01/17 14:35:09 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>


Intern::Intern(void)
{
	std::cout <<  "Intern default constructor called."  << std::endl;
	return ;
}

Intern::Intern(Intern const & src)
{
	std::cout <<  "Intern copy constructor called."  << std::endl;
	(void)src;
	return ;
}

Intern::~Intern(void)
{
	std::cout <<  "Intern desctructor called."  << std::endl;
	return ;
}

Intern &	Intern::operator=(Intern const & src)
{
	std::cout <<  "Intern assignment operator overload called."  << std::endl;
	(void)src;
	return (*this);
}

static AForm *	createPresidentialPardonForm(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

static AForm *	createRobotomyRequestForm(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

static AForm *	createShrubberyCreationForm(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

const char *	Intern::InvalidFormName::what(void) const throw()
{
	return ("Invalid form name");
}

AForm *	Intern::makeForm(std::string formName, std::string target)
{
	AForm *	formToCreate = NULL;
	static formList const	forms[3] = 
		{
			{"ShrubberyCreation", createShrubberyCreationForm},
			{"RobotomyRequest", createRobotomyRequestForm},
			{"PresidentialPardon", createPresidentialPardonForm}
		};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i].formName == formName)
		{
			formToCreate = forms[i].function(target);
			std::cout <<  "Intern created " << *formToCreate << std::endl;
			return (formToCreate);
		}
	}
	std::cout << "Intern couldm't make the following form \"" << formName << "\"" ;
	throw Intern::InvalidFormName();
}