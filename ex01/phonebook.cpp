/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:35:23 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/18 18:14:53 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <iomanip>

void PhoneBook::printPerson() {
	int i = 0;
	std::cout << "Phonebook" << std::endl;
	while(i < this->contact_num)
	{
		std::cout << std::setw(10);
		std::cout << contacts[i].getName() << contacts[i].getLastname() << contacts[i].getNickname() << contacts[i].getNumber() << contacts[i].getSecret() << std::endl;
		i++;
	}
}
void PhoneBook::addPerson() {

	std::string test;
	std::cout << "Enter name\n";
	std::getline(std::cin, test);
		this->contacts[this->contact_num].setName(test);
	std::cout << "Enter lastname\n";
	std::getline(std::cin, test);
		this->contacts[this->contact_num].setLastname(test);
	std::cout << "Enter nickname\n";
	std::getline(std::cin, test);
		this->contacts[this->contact_num].setNickname(test);
	std::cout << "Enter number\n";
	std::getline(std::cin, test);
		this->contacts[this->contact_num].setNumber(test);
	std::cout << "Enter darkest secret\n";
	std::getline(std::cin, test);
		this->contacts[this->contact_num].setSecret(test);
	this->contact_num++;
}
