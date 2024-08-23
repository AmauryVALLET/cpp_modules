/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:48:01 by avallet           #+#    #+#             */
/*   Updated: 2023/11/30 13:48:02 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

ClapTrap::ClapTrap(void)
	: _name("Default"),
	_hitPoints(CLAP_HIT_POINTS),
	_energyPoints(CLAP_ENERGY_POINTS),
	_attackDamage(CLAP_ATTACK_DAMAGE),
	_maxHitPoints(CLAP_HIT_POINTS),
	_maxEnergyPoints(CLAP_ENERGY_POINTS),
	_maxAttackDamage(CLAP_ATTACK_DAMAGE) {
	std::cerr <<  "ClapTrap constructor called."  << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name),
	_hitPoints(CLAP_HIT_POINTS),
	_energyPoints(CLAP_ENERGY_POINTS),
	_attackDamage(CLAP_ATTACK_DAMAGE),
	_maxHitPoints(CLAP_HIT_POINTS),
	_maxEnergyPoints(CLAP_ENERGY_POINTS),
	_maxAttackDamage(CLAP_ATTACK_DAMAGE) {
	std::cerr <<  "ClapTrap  \"" << name << "\" constructed."  << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cerr <<  "ClapTrap copy constructor called."  << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void) {
	std::cerr <<  "ClapTrap \"" << this->_name << "\" destroyed."  << std::endl;
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
		std::cout <<  "ClapTrap " << this->_name << " can't attack as it has been KO"  << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout <<  "ClapTrap " << this->_name << " can't attack, low battery" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout <<  "ClapTrap " << this->_name << " attacks " << target << " for a damage of " << this->_attackDamage  << std::endl; 
}







void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout <<  this->_name << " can't take it any longer, too much hits taken" << std::endl;
		return;
	}
	if ((int)this->_hitPoints - (int)amount <= 0) {
		this->_hitPoints = 0;
		std::cout <<  this->_name << " takes damage of " << amount << " and dies!"  << std::endl;
	}
	else {
		this->_hitPoints -= amount;
		std::cout <<  this->_name << " takes damage of " << amount  << std::endl;
	}
	return ;
}






void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints == 0) {
		std::cout <<  this->_name << " can't repair, too much hits taken"  << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout <<  this->_name << " can't repair, low battery." << std::endl;
		return ;
	}
	if ((this->_hitPoints + amount) > this->_maxHitPoints)
		amount = this->_maxHitPoints - this->_hitPoints;
	if (amount == 0) {
		this->_energyPoints--;
		std::cout <<  this->_name << " uses energy trying to repair while not needed." << std::endl;
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	std::cout <<  this->_name << " repairs itself and gains" << amount  << std::endl;
	return ;
}
