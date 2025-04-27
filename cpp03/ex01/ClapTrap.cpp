#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name){
	std::cout << _name << " created." << std::endl;
}
ClapTrap::~ClapTrap(){
	std::cout << _name << " destroyed." << std::endl;
}
void ClapTrap::attack(const std::string& target){
	if (_energy <= 0)
		return ;
	else
		std::cout << _name << " deals " << _damage << " to" << target << std::endl;
	_energy--;
}
void ClapTrap::takeDamage(unsigned int amount){
	std::cout << _name << " takes " << amount << std::endl;
	_hitpoints -= amount;
	if (_hitpoints <= 0)
		return ;
}
void ClapTrap::beRepaired(unsigned int amount){
	std::cout << _name << " repairs " << std::endl;
	_hitpoints += amount;
}
