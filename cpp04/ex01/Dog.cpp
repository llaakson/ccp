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
	brain = new Brain();
	_type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal()
{
	std::cout << "Dog copy constructor called." << std::endl;
	*this = copy;
}

Dog& Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &rhs)
	{
		return *this;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog default constructor called." << std::endl;
	delete brain;
}

void Dog::makeSound()const
{
	std::cout << "BARK" << std::endl;
}

void Dog::think(int i)
{
	if( i >= 0 && i <= 100)
	{	
		std::cout << "Dog is thinking about: " << brain->getIdea(i) << std::endl;
	}
	else 
		std::cout << "Brain can't handle idea: " << i << std::endl;
}

void Dog::thinkIdea(std::string one_idea, int i)
{
	if( i >= 0 && i <= 100)
	{
		brain->setIdea(one_idea,i);
	}
}
