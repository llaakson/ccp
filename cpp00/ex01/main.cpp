/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:35:18 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/21 12:01:28 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	std::string test;
	PhoneBook phonebook;
	while(1)
	{
		std::cout << "Input 'ADD', 'SEARCH' or 'EXIT: ";
		if (!std::getline(std::cin, test)){
			std::cout << "ctrl d found, exiting...\n";
			break ;
		}
		if (test == "ADD")
			if(phonebook.addPerson())
				break ;
		if (test == "SEARCH")
			phonebook.printPerson();
		else if (test == "EXIT")
			return(0);
	}
	return (0);
}

