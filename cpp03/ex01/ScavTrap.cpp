#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << _name << " ScravTrap created." << std::endl;
}
ScavTrap::~ScavTrap(){
	std::cout << _name << " ScravTrap destroyed." << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "Guard" << std::endl;
}
