/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:21:54 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/20 13:01:35 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "main.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		int contact_num;
		int current_contact;
	public:
		PhoneBook();
		~PhoneBook();
		int addPerson();
		int printPerson();
		void print_contact(int i);
};

#endif
