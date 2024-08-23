/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:47:48 by avallet           #+#    #+#             */
/*   Updated: 2023/11/30 13:47:50 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout <<  "ScavTrap constructor called."  << std::endl;
	this->_hitPoints = SCAV_HIT_POINTS;
	this->_maxHitPoints = SCAV_HIT_POINTS;
	this->_energyPoints = SCAV_ENERGY_POINTS;
	this->_maxEnergyPoints = SCAV_ENERGY_POINTS;
	this->_attackDamage = SCAV_ATTACK_DAMAGE;
	this->_maxAttackDamage = SCAV_ATTACK_DAMAGE;
	return ;
}

ScavTrap::ScavTrap(std::string & name) : ClapTrap(name) {
	std::cout <<  "ScavTrap  \"" << name << "\" constructed." << std::endl;
	this->_hitPoints = SCAV_HIT_POINTS;
	this->_maxHitPoints = SCAV_HIT_POINTS;
	this->_energyPoints = SCAV_ENERGY_POINTS;
	this->_maxEnergyPoints = SCAV_ENERGY_POINTS;
	this->_attackDamage = SCAV_ATTACK_DAMAGE;
	this->_maxAttackDamage = SCAV_ATTACK_DAMAGE;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap() {
	std::cout <<  "ScavTrap copy constructor called."  << std::endl;
	*this = src;
	return ;
}

ScavTrap::~ScavTrap(void) {
	std::cout <<  "ScavTrap \"" << this->_name << "\" destroyed."  << std::endl;
	return ;
}

ScavTrap &	ScavTrap::operator=(ScavTrap const & src) {
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

void	ScavTrap::attack(std::string & target) {
	if (this->_hitPoints == 0) {
		std::cout <<  "ScavTrap " << this->_name << " as it has been destroyed."  << std::endl;
		return ;
	}
	if (this->_energyPoints == 0) {
		std::cout <<  "ScavTrap " << this->_name << " cannot attack, low battery." << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout <<  "ScavTrap " << this->_name << " attacks " << target << " for a damage of " << this->_attackDamage << std::endl;  
}

void	ScavTrap::guardGate(void) {
	if (this->_hitPoints == 0)
		std::cout << this->_name << "can't guard the gate, hit pts to 0."  << std::endl;
	else
		std::cout << this->_name << " Gate keeper mode activated."  << std::endl;
	return ;
}

