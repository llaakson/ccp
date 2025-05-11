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
	for (int i = 0; i < 100; i++)
	{
		idea[i] = "idea" + std::to_string(1);
	}
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain default constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
	{
		idea[i] = copy.idea[i];
	}
}

Brain& Brain::operator=(const Brain &rhs)
{
	std::cout << "Brain default constructor called." << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
		{
			idea[i] = rhs.idea[i];
		}	
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain default constructor called." << std::endl;
}

std::string Brain::getIdea(int i)
{
	if( i >= 0 && i <= 100)
	{
		return(idea[i]);
	}
	else
		return ("Brain too small");
}

void Brain::setIdea (std::string one_idea, int i)
{
	if( i >= 0 && i <= 100)
	{
		idea[i] = one_idea;
	}
}