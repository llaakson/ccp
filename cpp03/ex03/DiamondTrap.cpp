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

DiamondTrap::DiamondTrap() : ClapTrap("Diammondo"){
	std::cout << "Diamond default constructor called" << std::endl;

}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name){
	std::cout << "Diamond name constructor called" << std::endl;

}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy){
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
	FragTrap::attack(target);
}

void DiamondTrap::whoAmI(){
	std::cout << "I am " << _name << std::endl;
}
