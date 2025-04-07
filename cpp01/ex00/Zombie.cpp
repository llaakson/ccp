/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:45:39 by llaakson          #+#    #+#             */
/*   Updated: 2025/04/03 15:00:43 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name){
	this->name = name;
}

Zombie::~Zombie(void){
	std::cout << name << ": Destroyed" << std::endl;
}

void Zombie::announce(void){
		std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
