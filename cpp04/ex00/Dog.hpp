/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:15:17 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/08 20:16:44 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HH
#define DOG_HH
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
    public:
		Dog();
		Dog(const Dog &copy);
		Dog& operator=(const Dog &rhs);
		~Dog() override;

        void makeSound()const override;
};

#endif
