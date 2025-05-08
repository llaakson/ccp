/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 14:31:40 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/08 14:31:43 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	std::cout << "----COPYING TRAP1----" << std::endl;
	ClapTrap Trap2 = ClapTrap(Trap1);
	Trap2.ClapTrapStatus();

	Trap2.takeDamage(2147483699);
	Trap2.attack("Target2");
	Trap2.takeDamage(1);
	Trap2.beRepaired(4);
	Trap2.attack("Target2");
	
	std::cout << "----COPYING ASSIGMENT OPERATOR TEST----" << std::endl;
	Trap1 = Trap2;
	Trap1.ClapTrapStatus();
	Trap1.beRepaired(20);
	Trap1.beRepaired(4);
	Trap1.beRepaired(4);
	Trap1.beRepaired(4);
	Trap1.attack("Target1");

	std::cout << "---FINAL STATUS----" << std::endl;
	Trap1.ClapTrapStatus();


	return (0);
}
