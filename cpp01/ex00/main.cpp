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
	randomChump("Tippa");
	
	Zombie *ptr = newZombie("Tappi");
	if (!ptr)
		return (1);
	ptr->announce();
	delete ptr;

	return (0);
}
