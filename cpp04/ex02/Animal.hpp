/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:28:16 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/08 20:56:26 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HH
#define ANIMAL_HH
#include <iostream>
#include <string>

class Animal {
	protected:
		std::string _type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &copy);
		Animal& operator=(const Animal& rhs);
		virtual ~Animal();

		std::string getType()const;
		virtual void makeSound()const = 0;
};

// Abstract base class, constains 1 pure virtual function ( can only be derrived from)
// makeSound funtion must be override.

#endif
