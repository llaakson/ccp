/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:40:50 by llaakson          #+#    #+#             */
/*   Updated: 2025/04/03 13:49:00 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv){
	Harl harl;
	
	if (argc != 2){
		std::cout << "Error! Give only one argument" << std::endl;
		return 1;
	}
	std::string arg = argv[1];
	harl.complain(arg);
return 0;
}
