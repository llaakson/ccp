/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:00:17 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/07 14:00:42 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Nameless trap"){
	std::cout << "FragTrap default constructor called" << std::endl;
	_hitpoints = 100;
	_energy = 50;
	_damage = 20;
	_maxhitpoints = 100; 
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << "FragTrap name constructor called" << std::endl;
	_name = "GigaTrap";
	_hitpoints = 100;
	_energy = 50;
	_damage = 20;
	_maxhitpoints = 100;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy){
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs){
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &rhs){
		this->_name = rhs._name;
		this->_hitpoints = rhs._hitpoints;
		this->_energy = rhs._energy;
		this->_damage = rhs._damage;
		this->_maxhitpoints = rhs._maxhitpoints;
	}
	return (*this);
} 

FragTrap::~FragTrap(){
	std::cout << _name << " FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target){
	if (_energy <= 0){
		std::cout << _name << " is out of energy and can't attack" << std::endl;
		return ;
	}
	else if (_hitpoints <= 0){
		std::cout << _name << " is destroyed and can't attack" << std::endl;
		return ;
	}
	else
		std::cout << _name << " DEALS " << _damage << " damage to " << target << std::endl;
	_energy--;
}

void FragTrap::highFivesGuys(void){
	std::cout << _name << " Positive high fives" << std::endl;
}
