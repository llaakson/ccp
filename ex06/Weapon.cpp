/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:41:21 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/21 23:08:42 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string &Weapon::getType(){
	return(this->type);}

void Weapon::setType(std::string typee){
	type = typee;
}

Weapon::Weapon(){};

Weapon::Weapon(std::string type){
	this->type = type;
}

Weapon::~Weapon(){};
