/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:09:34 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/07 22:09:38 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap1"), _hitpoints(10), _energy(10), _damage(0){
	std::cout << _name << " ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energy(10), _damage(0){
	std::cout << _name << " ClapTrap name constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &rhs){
	std::cout << "ClapTrap Copy assigment operator called" << std::endl;
	this->_name = rhs._name;
	this->_hitpoints = rhs._hitpoints;
	this->_energy = rhs._energy;
	this->_damage = rhs._damage;
	this->_maxhitpoints = rhs._maxhitpoints;
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << _name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if (_energy <= 0){
		std::cout << _name << " is out of energy and can't attack" << std::endl;
		return ;
	}
	else if (_hitpoints <= 0){
		std::cout << _name << " is destroyed and can't attack" << std::endl;
		return ;
	}
	else
		std::cout << _name << " deals " << _damage << " damage to " << target << std::endl;
	_energy--;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (_hitpoints == 0){
		std::cout << _name << " is already destroyed" << std::endl;
		return ;
	}
	std::cout << _name << " takes " << amount <<" of damage" << std::endl;
	if (amount >= _hitpoints){
		_hitpoints = 0;
		return ;
	}
	_hitpoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_energy <= 0)
		std::cout << _name << " has no energy to repair" << std::endl;
	else {
	std::cout << _name << " repairs iself " << amount << " hitpoints" << std::endl;
	if ((amount + _hitpoints) >= _maxhitpoints){
		_hitpoints = _maxhitpoints;
		_energy--;
		return ;
	}
	_hitpoints += amount; 
	_energy--;
	}
}

int ClapTrap::getHitpoints(){
	return (_hitpoints);
}
