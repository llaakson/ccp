#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap1"), _hitpoints(10), _energy(10), _damage(0){
	std::cout << _name << " created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitpoints(10), _energy(10), _damage(0){
	std::cout << _name << " created." << std::endl;
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
	else
		std::cout << _name << " deals " << _damage << " damage to" << target << std::endl;
	_energy--;
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << _name << " takes " << amount <<" of damage" << std::endl;
	_hitpoints -= amount;
	if (_hitpoints <= 0)
		_hitpoints = 0;
	if (_hitpoints == 0)
		return ;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (_energy <= 0)
		std::cout << _name << " has no energy to repair" << std::endl;
	else {
	std::cout << _name << " repairs iself " << amount << " hitpoints" << std::endl;
	std::cout << _energy << std::endl;
	_hitpoints += amount; 
	_energy--;
	}
}
