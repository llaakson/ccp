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
	std::cout << "FragTrap default constructor called. " << _name << std::endl;
	_hitpoints = 100;
	_damage = 30;
	_maxhitpoints = 100; 
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << "FragTrap name constructor called. " << _name << std::endl;
	_hitpoints = 100;
	_damage = 30;
	_maxhitpoints = 100;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy){
	std::cout << "FragTrap copy constructor called. " << _name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs){
	std::cout << "FragTrap copy assignment operator called. " << _name << std::endl;
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
	std::cout << "FragTrap destructor called. " << _name << std::endl;
}

void FragTrap::highFivesGuys(void){
	std::cout << _name << " Gives you positive high fives. The vibes are off the chart." << std::endl;
}
