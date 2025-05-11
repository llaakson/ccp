/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:20:28 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/09 22:17:13 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HH
#define WRONGCAT_HH
#include <iostream>
#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat : public WrongAnimal{
	private:
		Brain *_brain;
    public:
		WrongCat();
		WrongCat(const WrongCat &copy);
		WrongCat& operator=(const WrongCat &rhs);
		~WrongCat() override;

		void think(int i);
		void thinkIdea(std::string one_idea, int i);
};

#endif
