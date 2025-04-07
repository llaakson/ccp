/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:33:29 by llaakson          #+#    #+#             */
/*   Updated: 2025/04/03 16:33:33 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(){
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("ERROR");
	harl.complain("INFO");
	harl.complain("WARNING");

	harl.complain("ASDA");
	harl.complain("");
	harl.complain("    ");
	harl.complain(" WARNING");
return 0;
}
