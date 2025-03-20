/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:41:56 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/20 15:38:00 by llaakson         ###   ########.fr       */
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
		Zombie* newZombie( std::string name );
		void randomChump( std::string name );
		Zombie();
		~Zombie();
};
#endif
