/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:02:27 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/07 22:02:35 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), _name("Default"){
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energy = ScavTrap::_energy;
	this->_damage = FragTrap::_damage;
	this->_maxhitpoints = FragTrap::_hitpoints;
}

DiamondTrap::DiamondTrap(std::string name)  : ClapTrap(name + "_clap_name"), _name(name){
	std::cout << "DiamondTrap name constructor called" << std::endl;

}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy){
	std::cout << "Diamond default constructor called" << std::endl;

}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs){
	std::cout << "Diamond copy assignment operator called" << std::endl;
	if (this != &rhs){
		this->_name = rhs._name;
		this->_hitpoints = rhs._hitpoints;
		this->_energy = rhs._energy;
		this->_damage = rhs._damage;
		this->_maxhitpoints = rhs._maxhitpoints;
	}
	return (*this);
} 

DiamondTrap::~DiamondTrap(){
	std::cout << _name << " DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
	std::cout << "DiamonTrap name is " << this->_name << std::endl;
	std::cout << "ClapTrap name is " << ClapTrap::_name << std::endl;
}

void DiamondTrap::TrapStatus(){
	std::cout << this->_name << " current state:" << std::endl;
	std::cout << "Hitpoints: " << _hitpoints << std::endl;
	std::cout << "Energy:    " << _energy << std::endl;
	std::cout << "Damage:    " << _damage << std::endl;
}
