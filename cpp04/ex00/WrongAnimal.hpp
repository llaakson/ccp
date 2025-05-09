/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:20:11 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/09 22:19:51 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HH
#define WRONGANIMAL_HH
#include <iostream>

class WrongAnimal {
	private:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		WrongAnimal& operator=(const WrongAnimal& rhs);
		virtual ~WrongAnimal();

		std::string getType()const;
		virtual void makeSound()const;
};

#endif
