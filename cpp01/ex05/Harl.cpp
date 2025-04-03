/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:23:03 by llaakson          #+#    #+#             */
/*   Updated: 2025/04/03 16:28:23 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug( void ){
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;	
}
void Harl::info( void ){
        std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}       

void Harl::warning( void ){
        std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}       

void Harl::error( void ){
        std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;                              
}

void Harl::complain( std::string level ){
	std::string string[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*complains[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int check = 1;
	for(int i = 0; i < 4; i++){
		if (level == string[i]){
			check = 0;
			(this->*complains[i])();
		}
	}
	if (check)
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
