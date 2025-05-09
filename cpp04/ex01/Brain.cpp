/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:13:26 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/09 23:14:34 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called." << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain default constructor called." << std::endl;
	*this = copy;
}

Brain& Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain default constructor called." << std::endl;
	if (this != &rhs)
	{
		return *this;
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain default constructor called." << std::endl;
}

