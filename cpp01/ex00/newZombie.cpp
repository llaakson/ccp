/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:35:00 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/20 15:43:01 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie( std::string name ){
	try {
	Zombie *newzombie = new Zombie(name);
	return (newzombie);
	}
	catch(std::bad_alloc& e){
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
