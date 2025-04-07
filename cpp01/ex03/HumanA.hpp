/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:36:41 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/21 23:17:46 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_HPP
#define HumanA_HPP
#include "Weapon.hpp"
#include <string>

class HumanA {
	private:
		std::string name;
		Weapon& weapon;
	public:
		void attack();
		HumanA(std::string name,Weapon& weapon);
};

#endif
