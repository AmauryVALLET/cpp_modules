/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:10:27 by avallet           #+#    #+#             */
/*   Updated: 2023/12/06 17:29:14 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	std::cout <<  "MateriaSource default constructor called."  << std::endl;
	this->_initializeEmptyMaterias();
	return ;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	std::cout <<  "MateriaSource copy constructor called."  << std::endl;
	this->_initializeEmptyMaterias();
	*this = src;
	return ;
}

MateriaSource::~MateriaSource(void)
{
	std::cout <<  "MateriaSource destructor called."  << std::endl;
	this->_deleteMaterias();
	return ;
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & src)
{
	std::cout <<  "MateriaSource operator overload called."
		 << std::endl;
	this->_deleteMaterias();
	for (int i = 0; i < this->_maxMaterias; i++)
	{
		if (src._Materias[i] != NULL)
			this->_Materias[i] = src._Materias[i]->clone();
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria * materia)
{
	if (!materia)
	{
		std::cout <<  "Can't learn as Materia does not exist" << std::endl;
		return ;
	}
	for (int i = 0; i < this->_maxMaterias; i++)
	{
		if (this->_Materias[i] == NULL)
		{
			this->_Materias[i] = materia;
			std::cout <<  "MateriaSource learned : " << materia->getType()  << std::endl;
			return ;
		}
	}
	std::cout <<  "MateriaSource can't learn any more materia."  << std::endl;
	delete materia;
	return ;
}

AMateria *	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_maxMaterias; i++)
	{
		if (this->_Materias[i]
			&& this->_Materias[i]->getType() == type)
		{
			std::cout << std::endl <<  "MateriaSource creating : " << type << std::endl;
			return (this->_Materias[i]->clone());
		}
	}
	std::cout <<  "MateriaSource does not know the type \"" << type << "\"."  << std::endl;
	return (NULL);
}

void	MateriaSource::_initializeEmptyMaterias(void)
{
	for (int i = 0; i < this->_maxMaterias; i++)
		this->_Materias[i] = NULL;
	return ;
}

void	MateriaSource::_deleteMaterias(void)
{
	for (int i = 0; i < this->_maxMaterias; i++)
	{
		if (this->_Materias[i] != NULL)
		{
			delete this->_Materias[i];
			this->_Materias[i] = NULL;
		}
	}
	return ;
}

void	MateriaSource::displayKnownMaterias(void)
{
	std::cout << std::endl << "MateriaSource knows the following Materias:" << std::endl;
	for (int i = 0; i < this->_maxMaterias; i++)
	{
		std::cout << "* " << i;
		if (this->_Materias[i] == NULL)
			std::cout << " None";
		else
			std::cout << " Materia = " <<  this->_Materias[i]->getType();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return ;
}
