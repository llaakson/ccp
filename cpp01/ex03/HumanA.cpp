/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:40:41 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/21 23:26:40 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name,Weapon& weapon) : name(name), weapon(weapon) {}

void HumanA::attack(){
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
