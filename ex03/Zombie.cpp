/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:45:39 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/20 15:29:43 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

Zombie::Zombie(void){}

Zombie::~Zombie(void){}

void announce(void){
		std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}
