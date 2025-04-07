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
	if (_weapon == nullptr)
		std::cout << _name << " attacks with their fist" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
void HumanB::setWeapon(Weapon &newweapon){
	_weapon = &newweapon;
}

HumanB::HumanB(std::string name){
	_name = name;
	_weapon = nullptr;
}
