#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Nameless trap"){
	std::cout << " ScravTrap default constructor called" << std::endl;
	_hitpoints = 100;
	_energy = 50;
	_damage = 20;
	_maxhitpoints = 100; 
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "ScravTrap name constructor called" << std::endl;
	_name = "GigaTrap";
	_hitpoints = 100;
	_energy = 50;
	_damage = 20;
	_maxhitpoints = 100;
}

ScavTrap::ScavTrap(const ScavTrap &copy){
	std::cout << "ScravTrap copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs){
	std::cout << "ScravTrap copy assignment operator called" << std::endl;
	if (this != &rhs){
		this->_name = rhs._name;
		this->_hitpoints = rhs._hitpoints;
		this->_energy = rhs._energy;
		this->_damage = rhs._damage;
		this->_maxhitpoints = rhs._maxhitpoints;
	}
	return (*this);
} 

ScavTrap::~ScavTrap(){
	std::cout << _name << " ScravTrap destructor called" << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << _name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target){
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
