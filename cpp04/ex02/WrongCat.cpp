/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:20:43 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/08 22:20:46 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called." << std::endl;
	_brain = new Brain();
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat copy constructor called." << std::endl;
	_brain = new Brain(*copy._brain);
}

WrongCat& WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << "WrongCat copy assignment operator called." << std::endl;
	if (this != &rhs)
	{
		delete _brain;
		_brain = new Brain(*rhs._brain);
		_type = rhs._type;
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat default constructor called." << std::endl;
	delete _brain;
}

void WrongCat::think(int i)
{
	if( i >= 0 && i <= 100 && _brain)
	{	
		std::cout << "WrongCat is thinking about: " << _brain->getIdea(i) << std::endl;
	}
	else 
		std::cout << "Brain can't handle idea: " << i << std::endl;
}

void WrongCat::thinkIdea(std::string one_idea, int i)
{
	if( i >= 0 && i <= 100 && _brain)
	{
		_brain->setIdea(one_idea,i);
	}
}