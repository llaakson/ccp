#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
	private:
		std::string _name;
		int _hitpoints = 100;
		int _energy = 50;
		int _damage = 20;
	public:
		ScavTrap(std::string name);
		~ScavTrap();
		void guardGate();
	
};

#endif
