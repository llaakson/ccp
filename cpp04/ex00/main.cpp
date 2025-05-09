/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:11:25 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/08 20:11:43 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	Animal One;
	Dog DogOne;
	Cat CatOne;

	One.makeSound();
	DogOne.makeSound();
	CatOne.makeSound();
	std::cout << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	//...
	std::cout << std::endl;
	std::cout << "  =^..^=  WRONG ANIMAL TEST  =^..^=  " << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const Animal* j2 = new Dog();
	const WrongAnimal* i2 = new WrongCat();
	std::cout << j2->getType() << " " << std::endl;
	std::cout << i2->getType() << " " << std::endl;
	i2->makeSound(); //will output the WrongCat sound!
	j2->makeSound();
	meta2->makeSound();
	std::cout << std::endl;
	delete(meta2);
	delete(j2);
	delete(i2);
	delete(meta);
	delete(j);
	delete(i);

	return 0;
}
