/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:21:54 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/18 17:37:53 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "main.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int contact_num;
	public:
		PhoneBook() {
		contact_num = 0; 
		}
		void addPerson();
		void printPerson();
};

#endif
