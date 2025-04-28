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
	return (0);
}
