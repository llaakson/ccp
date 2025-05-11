/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:14:41 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/08 21:02:13 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "Cat default constructor called." << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &rhs)
	{
		_type = rhs._type;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat default constructor called." << std::endl;
}

void Cat::makeSound()const
{
	std::cout << "MEOW" << std::endl;
}