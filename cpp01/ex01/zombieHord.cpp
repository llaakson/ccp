/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:35:00 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/21 13:11:36 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name )
{
	try
	{
	Zombie *newzombie = new Zombie[N];
	for(int i = 0; i < N; i++)
		newzombie[i].setName(name + std::to_string(1+i));
	return (newzombie);
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (nullptr);
	}
	catch(...){
		std::cout << "--exit test--" << std::endl;
	}
	std::cout << "--second test--" << std::endl;
	return (0);
}