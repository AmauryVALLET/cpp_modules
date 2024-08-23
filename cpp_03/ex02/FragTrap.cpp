/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallet <avallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:48:12 by avallet           #+#    #+#             */
/*   Updated: 2023/11/30 13:48:14 by avallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <string>

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout <<  "FragTrap constructor called."  << std::endl;
	this->_hitPoints = FRAG_HIT_PTS;
	this->_maxHitPoints = FRAG_HIT_PTS;
	this->_energyPoints = FRAGT_ENERGY_PTS;
	this->_maxEnergyPoints = FRAGT_ENERGY_PTS;
	this->_attackDamage = FRAG_ATCK_DAMAGE;
	this->_maxAttackDamage = FRAG_ATCK_DAMAGE;
	return ;
}

FragTrap::FragTrap(std::string & name) : ClapTrap(name) {
	std::cout <<  "FragTrap \"" << name << "\" constructed."
		 << std::endl;
	this->_hitPoints = FRAG_HIT_PTS;
	this->_maxHitPoints = FRAG_HIT_PTS;
	this->_energyPoints = FRAGT_ENERGY_PTS;
	this->_maxEnergyPoints = FRAGT_ENERGY_PTS;
	this->_attackDamage = FRAG_ATCK_DAMAGE;
	this->_maxAttackDamage = FRAG_ATCK_DAMAGE;
	return ;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap() {
	std::cout <<  "FragTrap copy constructor called."  << std::endl;
	*this = src;
	return ;
}

FragTrap::~FragTrap(void) {
	std::cout <<  "FragTrap \"" << this->_name << "\" destroyed."  << std::endl;
	return ;
}

FragTrap &	FragTrap::operator=(FragTrap const & src) {
	if (this != &src) {
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	if (this->_hitPoints == 0)
		std::cout << this->_name << " can't hi five as 0 hit pts" << std::endl;
	else
		std::cout << this->_name << " throws a hi five"  << std::endl;
	return ;
}
