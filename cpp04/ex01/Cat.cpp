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

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called." << std::endl;
	_brain = new Brain();
	_type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called." << std::endl;
	_brain = new Brain(*copy._brain);
}

Cat& Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &rhs)
	{
		delete _brain;
		_brain = new Brain(*rhs._brain);
		_type = rhs._type;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat default constructor called." << std::endl;
	delete _brain;
}

void Cat::makeSound()const
{
	std::cout << "MEOW" << std::endl;
}

void Cat::think(int i)
{
	if( i >= 0 && i <= 100 && _brain)
	{	
		std::cout << "Cat is thinking about: " << _brain->getIdea(i) << std::endl;
	}
	else 
		std::cout << "Brain can't handle idea: " << i << std::endl;
}

void Cat::thinkIdea(std::string one_idea, int i)
{
	if( i >= 0 && i <= 100 && _brain)
	{
		_brain->setIdea(one_idea,i);
	}
}

void Cat::brain_address(void)
{	
	if (_brain)
		std::cout << "Brain address is " << &_brain << std::endl;
}