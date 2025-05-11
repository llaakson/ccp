/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 23:06:15 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/09 23:15:42 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	//...
	int size = 10;
	Animal *k[size];
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
			k[i] = new Dog();
		else
			k[i] = new Cat();
	}
	for (int i = 0; i < size; i++)
		k[i]->makeSound();
	for (int i = 0; i < size; i++)
	{
		delete k[i];
	}
	std::cout << "-----------More test-----------" << std::endl;
	Cat Cat1;
	Cat1.thinkIdea("Must drop stuff from the table", 1);
	Cat1.think(1);
	Dog Dog1;
	Dog1.thinkIdea("Must roll in the mud", 1);
	Dog1.think(1);
	Dog1.think(2);
	Dog1.think(101);
	std::cout << "-----------Testing Copying-----------" << std::endl;
	Dog Dog2;
	Dog2 = Dog1;
	Dog1.think(1);
	Dog2.think(2);
	Cat Cat2 = Cat1;
	Cat2.think(1);

	//Animal fail;

	return 0;
}
