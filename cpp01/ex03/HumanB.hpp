/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:36:41 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/21 23:03:18 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_HPP
#define HumanB_HPP
#include <string>
#include "Weapon.hpp"

class HumanB {
	private:
		Weapon* _weapon;
		std::string _name;
	public:
		void attack();
		void	setWeapon(Weapon &newweapon);
		HumanB(std::string name);
};

#endif
