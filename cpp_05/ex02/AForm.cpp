/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:33:49 by avallet           #+#    #+#             */
/*   Updated: 2024/01/17 14:33:52 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>


AForm::AForm(void) :_name("default Form"),
					_isSigned(false),
					_gradeRequiToSign(Bureaucrat::lowestGrade),
					_gradeRequiToExecute(Bureaucrat::lowestGrade)
{
	std::cout <<  "Form default constructor called."  << std::endl;
	return ;
}

AForm::AForm(AForm const & src) :	_name(src._name),
									_isSigned(false),
									_gradeRequiToSign(src._gradeRequiToSign),
									_gradeRequiToExecute(src._gradeRequiToExecute)
{
	std::cout <<  "Form copy constructor called."  << std::endl;
	return ;
}

AForm::AForm(std::string const & name, int const gradeToSign, int const gradeToExecute)
			:	_name(name),
				_isSigned(false),
				_gradeRequiToSign(gradeToSign),
				_gradeRequiToExecute(gradeToExecute)
{
	std::cout <<  "Form attribute constructor called."  << std::endl;
	if (gradeToSign < Bureaucrat::highestGrade || gradeToExecute < Bureaucrat::highestGrade )
		throw (AForm::GradeTooHighException());
	if (gradeToSign > Bureaucrat::lowestGrade || gradeToExecute > Bureaucrat::lowestGrade)
		throw (AForm::GradeTooLowException());
	std::srand(time(0));
	return ;
}

AForm::~AForm(void)
{
	std::cout <<  "Form destructor called."  << std::endl;
	return ;
}

AForm &	AForm::operator=(AForm const & src)
{
	std::cout <<  "Form assignment operator overload called."  << std::endl;
	this->_isSigned = src._isSigned;
	return (*this);
}

std::string const &	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::isSigned(void) const
{
	return (this->_isSigned);
}

int	AForm::getGradeRequiToSign(void) const
{
	return (this->_gradeRequiToSign);
}

int	AForm::getGradeRequiToExecute(void) const
{
	return (this->_gradeRequiToExecute);
}

void	AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (this->_isSigned)
		throw (AForm::AlreadySignedException());
	if (bureaucrat.getGrade() > this->_gradeRequiToSign)
		throw (AForm::GradeTooLowException());
	this->_isSigned = true;
	return ;
}

void	AForm::execute(Bureaucrat const & bureaucrat) const
{
	if (this->_isSigned == false)
		throw (AForm::NotSignedException());
	if (bureaucrat.getGrade() > this->_gradeRequiToExecute)
		throw (AForm::GradeTooLowException());
	this->beExecuted();
	return ;
}

const char *	AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high for form.");
}

const char *	AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low for form.");
}

const char *	AForm::AlreadySignedException::what(void) const throw()
{
	return ("Form is already signed.");
}

const char *	AForm::NotSignedException::what(void) const throw()
{
	return ("Form has not been signed.");
}

std::ostream &	operator<<(std::ostream & os, AForm const & obj)
{
	os << "\"" << obj.getName() << "\" ["
		<< (obj.isSigned() ? "signed" : "unsigned") << "] "
		<< "(Requi grade to sign: " << obj.getGradeRequiToSign()
		<< "; to execute: " << obj.getGradeRequiToExecute() << ")";
	return (os);
}
