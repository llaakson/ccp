/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:14:58 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/08 20:52:22 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HH
#define CAT_HH
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	private:
		Brain *brain;
    public:
		Cat();
		Cat(const Cat &copy);
		Cat& operator=(const Cat &rhs);
		~Cat() override;

        void makeSound()const override;
		void think(int i);
		void thinkIdea(std::string one_idea, int i);
};

#endif
