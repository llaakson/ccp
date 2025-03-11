/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:35:18 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/11 08:51:45 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(int argc, char **argv) {
	(void)argc;
	(void)argv;
	PhoneBook book1;
	book1.n = 4224;

	std::cout << book1.n << "\n";
	return (0);
}

