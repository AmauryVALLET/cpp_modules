/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:46:17 by avallet           #+#    #+#             */
/*   Updated: 2023/11/30 13:46:50 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(void)
	: _name("default"),
	_hitPoints(ClapTrap::maxHitPoints),
	_energyPoints(ClapTrap::allAccessEnergyPoints),
	_attackDamage(ClapTrap::maxAttackDamage) {
	std::cerr <<  " Constructor called."  << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	_hitPoints(ClapTrap::maxHitPoints),
	_energyPoints(ClapTrap::allAccessEnergyPoints),
	_attackDamage(ClapTrap::maxAttackDamage) {
	std::cerr <<  "ClapTrap \"" << name << "\" created."  << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cerr <<  "copy constructor called."  << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void) {
	std::cerr <<  "ClapTrap \"" << this->_name << "\" has been destroyed."  << std::endl;
	return ;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & src) {
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

std::string	ClapTrap::getName(void) const {
	return (this->_name);
}

unsigned int	ClapTrap::getHitPoints(void) const {
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return (this->_energyPoints);
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return (this->_attackDamage);
}

void	ClapTrap::attack(std::string & target) {
	if (this->_hitPoints == 0) {
		std::cout  << this->_name<< " can't attack as it has been destroyed."  << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout << this->_name << " can't attack as it has no energy left." << std::endl;
		return ;
	}

	this->_energyPoints--;
	std::cout << this->_name << " attacks " << target << " for a damage of " << this->_attackDamage << std::endl; 
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << this->_name << " can't take it any longer" << std::endl;
		return;
	}
	if ((int)this->_hitPoints - (int)amount <= 0) {
		this->_hitPoints = 0;
		std::cout << this->_name << " takes " << amount << " and dies"  << std::endl;
	}
	else {
		this->_hitPoints -= amount;
		std::cout << this->_name << " takes " << amount << " pts of damage"  << std::endl;
	}
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout << this->_name << " can't repair itself as its been hit too much"  << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout << this->_name << " can't repair itself as it has no battery left" << std::endl;
		return ;
	}
	if ((this->_hitPoints + amount) > ClapTrap::maxHitPoints)
		amount = ClapTrap::maxHitPoints - this->_hitPoints;
	if (amount == 0) {
		this->_energyPoints--;
		std::cout << this->_name << " trying to repair itself but is in great shape" << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout << this->_name << " repairs itself and gain " << amount << " pts"  << std::endl;
	return ;
}
