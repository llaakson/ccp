/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 22:13:38 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/09 23:10:24 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include <string>

class Brain {
	private:
		std::string idea[100]; 
	public:
		Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &rhs);
		virtual ~Brain();

		std::string getIdea(int i);
		void setIdea(std::string one_idea, int i);
};

#endif

