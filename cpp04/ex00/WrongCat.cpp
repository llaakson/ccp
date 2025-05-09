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

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << "WrongCat copy assignment operator called." << std::endl;
	if (this != &rhs)
	{
		return *this;
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat default constructor called." << std::endl;
}

