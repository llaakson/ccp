/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:35:23 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/19 17:10:20 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void PhoneBook::print_contact(int i)
{
	std::cout << "First name: " << contacts[i].getName() << std::endl;
	std::cout << "Last name: " << contacts[i].getLastname() << std::endl;
	std::cout << "Nickname: " << contacts[i].getNickname() << std::endl;
	std::cout << "Phone number: " << contacts[i].getNumber() << std::endl;
}

std::string shrink_str(const std::string str){
	if(str.size() > 10)
		return (str.substr(0,9) + ".");
	return (str);
}

int is_digits(const std::string str)
{
	for(int i = 0; str[i] != '\0'; i++) {
		if(!isdigit(str[i]))
				return (0);
	}
	return (1);
}

int PhoneBook::printPerson() {
	if (this->contact_num == 0){
		std::cout << "Phonebook is empty use ADD\n";
		return (0);
	}
	std::cout << "Phonebook is empty use ADD\n";
	std::cout << "------------------PHONEBOOK-----------------" << std::endl;
	std::cout << "     Index|      Name| Last name|  Nickname|" << std::endl;
	for(int i = 0; i < this->contact_num; i++) {
		std::cout << std::setw(10);
		std::cout << i << "|";
		std::cout << std::setw(10);
		std::cout << shrink_str(contacts[i].getName()) << "|";
		std::cout << std::setw(10);
		std::cout << shrink_str(contacts[i].getLastname()) << "|";
		std::cout << std::setw(10);
		std::cout << shrink_str(contacts[i].getNickname()) << "|" << std::endl;
	}
	std::cout << "Enter index\n";
	std::string input;
	if(!std::getline(std::cin, input)){
		std::cout << "ctrl d found, exiting...\n";
		return (1);
	}
	if (is_digits(input) && std::stoi(input) < this->contact_num)
		print_contact(std::stoi(input));
	else 
		std::cout << "Index out of scope\n";
	return (0);
}
int PhoneBook::addPerson() {
	if (current_contact == 8)
		current_contact = 0;
	std::string input;
	std::string question[5] = {"Enter name\n","Enter lastname\n","Enter nickname\n","Enter number\n","Enter darkest secret\n"};
	int i = 0;
	while(i < 5)
	{
		std::cout << question[i];
		if(!std::getline(std::cin, input)){
			std::cout << "ctrl d found, exiting...\n";
			return(1);
		}
		if (!input.empty())
		{
			if (i == 0)
				this->contacts[this->current_contact].setName(input);
			else if (i == 1)
				this->contacts[this->current_contact].setLastname(input);
			else if (i == 2)
				this->contacts[this->current_contact].setNickname(input);
			else if (i == 3)
				this->contacts[this->current_contact].setNumber(input);
			else if (i == 4)
				this->contacts[this->current_contact].setSecret(input);
			i++;
		}
	}
	if (contact_num < 8)
		this->contact_num++;
	this->current_contact++;
	return (0);
}
