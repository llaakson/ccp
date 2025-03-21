/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHord.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:35:00 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/21 13:11:36 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::setName(std::string zombiename){
	name = zombiename;
}
Zombie* zombieHorde( int N, std::string name ){
	Zombie *newzombie = new Zombie[N];
	for(int i = 0; i < N; i++)
		newzombie[i].setName(name);	
	return (newzombie);
}


