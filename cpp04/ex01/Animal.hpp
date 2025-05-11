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

class Animal {
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const Animal &copy);
		Animal& operator=(const Animal& rhs);
		virtual ~Animal();

		std::string getType()const;
		virtual void makeSound()const;
};

#endif
