/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:40:41 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/21 23:03:11 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

void HumanB::attack(){
	std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}
void HumanB::setWeapon(Weapon newweapon){
	this->weapon = newweapon;
}

HumanB::HumanB(std::string name){
	this->name = name;
}
