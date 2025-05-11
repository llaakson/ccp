/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:14:24 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/08 20:14:27 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called." << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog default constructor called." << std::endl;
}

void Dog::makeSound()const
{
	std::cout << "BARK" << std::endl;
}
