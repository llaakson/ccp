/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:35:18 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/18 18:37:44 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "phonebook.hpp"

int main() {
	std::string test;
	PhoneBook phonebook; // Instance ??
	Phonebook();
	while(1)
	{
		std::cout << "Please: ";
		std::getline(std::cin, test);
		if (test == "ADD")
			phonebook.addPerson();
		if (test == "SEARCH")
			phonebook.printPerson();
		else if (test == "EXIT")
			return(0);
		//std::cout << "\n";

	}

	return (0);
}

