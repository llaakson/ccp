#include "ClapTrap.hpp"

int main(){
	ClapTrap Trap1 = ClapTrap("Trap1");
	Trap1.takeDamage(7);
	Trap1.beRepaired(4);
	Trap1.takeDamage(7);
    Trap1.beRepaired(4);
	Trap1.takeDamage(7);
    Trap1.beRepaired(4);
	Trap1.beRepaired(4);
	Trap1.attack("Target1");

	ClapTrap Trap2 = ClapTrap("Trap2");
	Trap2.takeDamage(2147483699);
	Trap2.attack("Target2");
	Trap2.takeDamage(1);
	Trap2.beRepaired(4);
	Trap2.attack("Target2");

	std::cout << Trap2.getHitpoints() << std::endl;
	return (0);
}
