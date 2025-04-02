/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:41:21 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/21 22:59:13 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Weapon_HPP
#define Weapon_HPP
#include <string>

class Weapon {
	private:
		std::string type;
	public:
		std::string &getType();
		void setType(std::string type);

		Weapon();
		Weapon(std::string type);
		~Weapon();
};

#endif
