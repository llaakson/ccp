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

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called." << std::endl;
	_brain = new Brain();
	_type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called." << std::endl;
	_brain = new Brain(*copy._brain);
}

Dog& Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &rhs)
	{
		delete _brain;
		_brain = new Brain(*rhs._brain);
		_type = rhs._type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog default constructor called." << std::endl;
	delete _brain;
}

void Dog::makeSound()const
{
	std::cout << "BARK" << std::endl;
}

void Dog::think(int i)
{
	if( i >= 0 && i <= 100 && _brain)
	{	
		std::cout << "Dog is thinking about: " << _brain->getIdea(i) << std::endl;
	}
	else 
		std::cout << "Brain can't handle idea: " << i << std::endl;
}

void Dog::thinkIdea(std::string one_idea, int i)
{
	if( i >= 0 && i <= 100 && _brain)
	{
		_brain->setIdea(one_idea,i);
	}
}

void Dog::brain_address(void)
{	
	if (_brain)
		std::cout << "Brain address is " << &_brain << std::endl;
}