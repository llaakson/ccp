/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:41:56 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/21 13:09:21 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
	private:
		std::string name;
	public:
		void announce( void );
		void setName(std::string zombiename);
		Zombie();
		~Zombie();
};

Zombie* zombieHorde( int N, std::string name );

#endif
