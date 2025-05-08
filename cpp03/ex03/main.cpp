/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:43:17 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/08 17:43:19 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(){
	DiamondTrap Trap1 = DiamondTrap("DiamondTrap1");

	Trap1.takeDamage(7);
	Trap1.beRepaired(4);
	Trap1.takeDamage(7);
    Trap1.beRepaired(4);
	Trap1.takeDamage(7);
    Trap1.beRepaired(4);
	Trap1.beRepaired(4);
	Trap1.attack("Target1");

	std::cout << "----COPYING TRAP1----" << std::endl;
	DiamondTrap Trap2 = DiamondTrap(Trap1);
	Trap2.DiamondTrapStatus();

	Trap2.takeDamage(2147483699);
	Trap2.attack("Target2");
	Trap2.takeDamage(1);
	Trap2.beRepaired(4);
	Trap2.attack("Target2");
	
	std::cout << "----COPYING ASSIGMENT OPERATOR TEST----" << std::endl;
	Trap1 = Trap2;
	Trap1.DiamondTrapStatus();
	Trap1.beRepaired(20);
	Trap1.beRepaired(4);
	Trap1.beRepaired(4);
	Trap1.beRepaired(4);
	Trap1.attack("Target1");
	Trap1.beRepaired(4242424242);
	
	Trap1.whoAmI();

	std::cout << "---FINAL STATUS----" << std::endl;
	Trap1.DiamondTrapStatus();
	return (0);
}
