/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:27:31 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/08 20:57:05 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal name constructor called." << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called." << std::endl;
	_type = copy._type;
}

Animal& Animal::operator=(const Animal &rhs)
{
	std::cout << "Animal copy assigment operator called." << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

std::string Animal::getType(void)const
{
	return(_type);
}

void Animal::makeSound()const
{
	std::cout << "Default animal sound" << _type << std::endl;
}

