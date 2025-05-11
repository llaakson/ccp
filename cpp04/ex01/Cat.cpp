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
	brain = new Brain();
	_type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal()
{
	std::cout << "Cat copy constructor called." << std::endl;
	*this = copy;
}

Cat& Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &rhs)
	{
		return *this;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat default constructor called." << std::endl;
	delete brain;
}

void Cat::makeSound()const
{
	std::cout << "MEOW" << std::endl;
}

void Cat::think(int i)
{
	if( i >= 0 && i <= 100)
	{	
		std::cout << "Cat is thinking about: " << brain->getIdea(i) << std::endl;
	}
	else 
		std::cout << "Brain can't handle idea: " << i << std::endl;
}

void Cat::thinkIdea(std::string one_idea, int i)
{
	if( i >= 0 && i <= 100)
	{
		brain->setIdea(one_idea,i);
	}
}