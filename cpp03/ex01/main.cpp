#include "ScavTrap.hpp"

int main(){
	ScavTrap Trap1 = ScavTrap("ScavTrap1");
	Trap1.guardGate();
	Trap1.attack("Target1");
	return (0);
}
