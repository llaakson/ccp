/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:41:17 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/20 15:48:49 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie zombie("Tupu");
	zombie.announce();
	
	Zombie *ptr = newZombie("Hupu");
	if (!ptr)
		return (1);
	ptr->announce();
	delete ptr;
	
	randomChump("Lupu");
	return (0);
}
