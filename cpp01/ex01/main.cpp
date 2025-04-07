/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:41:17 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/21 13:22:02 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = -42;
	Zombie *ptr = zombieHorde(N,"BoB");
	if (!ptr)
		return (1);
	for(int i = 0; i < N; i++)
		ptr[i].announce();
	delete[] ptr;

	return (0);
}
