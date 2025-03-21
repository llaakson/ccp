/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 13:47:38 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/21 15:33:57 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
	
int main(){
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string& stringREF = brain;
	std::cout << "memory address of the string variable: " << &brain << " " << brain << std::endl;
	std::cout << "The memory address held by stringREF:  " << &stringREF << " " << stringREF << std::endl;
	std::cout << "The memory address held by stringPTR:  " << stringPTR << " " << *stringPTR << std::endl;
	return (0);
}
