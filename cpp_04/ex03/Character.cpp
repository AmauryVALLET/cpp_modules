/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:09:47 by avallet           #+#    #+#             */
/*   Updated: 2023/12/06 17:24:46 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>
#include <string>

Character::Character(void) : _name("Unnamed")
{
	std::cout <<  "Character default constructor called."  << std::endl;
	this->_initInvent();
	return ;
}

Character::Character(Character const & src)
{
	std::cout <<  "Character copy constructor called."  << std::endl;
	this->_initInvent();
	*this = src;
	return ;
}

Character::Character(std::string const & name) : _name(name)
{
	std::cout <<  "Character name constructor called with name \""
		<< this->_name << "\"."  << std::endl;
	this->_initInvent();
	return ;
}

Character::~Character(void)
{
	std::cout <<  "Character destructor called for \""
		<< this->_name << "\"."  << std::endl;
	this->_deleteInventory();
	return ;
}

Character &	Character::operator=(Character const & src)
{
	std::cout <<  "Character operator overload called." << std::endl;
	this->_name = src._name;
	this->_deleteInventory();
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (src._inventory[i] != NULL)
			this->_inventory[i] = src._inventory[i]->clone();
	}
	return (*this);
}

std::string const &	Character::getName(void) const
{
	return (this->_name);
}

void	Character::setName(std::string const & newName)
{
	this->_name = newName;
	return ;
}

void	Character::equip(AMateria * materia)
{
	if (!materia)
	{
		std::cout << this->_name << " equip failed, materia s not existing" << std::endl;
		return ;
	}
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = materia;
			std::cout << this->_name << " equipped " << materia->getType() << " materia to inventory at index " << i  << std::endl;
			return ;
		}
	}
	std::cout << this->_name
		<< ": Can't carry more materia"  << std::endl;
	return ;
}

void	Character::unequip(int index)
{
	if (index < 0 || index >= this->_inventorySize)
	{
		std::cout << ": wrong index given to unequip -> " << index  << std::endl;
		return ;
	}
	if (this->_inventory[index] == NULL)
	{
		std::cout << this->_name << ": index " << index << " already empty!" << std::endl;
		return ;
	}
	std::cout << this->_name << " unequipped " << this->_inventory[index]->getType() << " materia at index " << index << std::endl;
	this->_inventory[index] = NULL;	
	return ;
}

void	Character::use(int index, ICharacter & target)
{
	if (index < 0 || index >= this->_inventorySize)
	{
		std::cout << ": wrong index given to use -> " << index  << std::endl;
		return ;
	}
	if (this->_inventory[index] != NULL)
	{
		std::cout << this->_name << ": ";
		this->_inventory[index]->use(target);
	}
	else
		std::cout << this->_name << "Noting in inventory at index " << index << std::endl;
	return ;
}

void	Character::InvDisplay(void) const
{
	std::cout << std::endl << this->_name << "'s inventory:" << std::endl;
	for (int i = 0; i < this->_inventorySize; i++)
	{
		std::cout << "materia * " << i;
		if (this->_inventory[i] == NULL)
			std::cout << " None";
		else
			std::cout << " " << this->_inventory[i]->getType();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return ;
}

void	Character::_initInvent(void)
{
	for (int i = 0; i < this->_inventorySize; i++)
		this->_inventory[i] = NULL;
	return ;
}

void	Character::_deleteInventory(void)
{
	for (int i = 0; i < this->_inventorySize; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
	return ;
}