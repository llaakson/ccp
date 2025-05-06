/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:48:55 by llaakson          #+#    #+#             */
/*   Updated: 2025/04/11 20:17:55 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
bool bsp( Point const a, Point const b, Point const c, Point const point);

int main(){
	
	std::cout << "1st cube" << std::endl;
	bool result = bsp(Point(0,0),Point(10,30),Point(20,0),Point(5,5));
	std::cout << result << std::endl;

	result = bsp(Point(50,50),Point(10,30),Point(20,0),Point(5,5));
	std::cout << result << std::endl;
	
	result = bsp(Point(1,1),Point(10,30),Point(20,0),Point(5,5));
	std::cout << result << std::endl;

	result = bsp(Point(10,30),Point(10,30),Point(20,0),Point(5,5));
	std::cout << result << std::endl;

	std::cout << "2nd cube" << std::endl;
	result = bsp(Point(-5,6),Point(10,30),Point(20,-6),Point(5,5));
	std::cout << result << std::endl;

	result = bsp(Point(-5,6),Point(10,30),Point(20,-6),Point(20,5));
	std::cout << result << std::endl;

	result = bsp(Point(-5,6),Point(10,30),Point(20,-6),Point(5,20));
	std::cout << result << std::endl;

	std::cout << "3nd cube" << std::endl;
	result = bsp(Point(-5.4,6.4),Point(10.1,30.1),Point(20.2,-6.2),Point(5,5));
	std::cout << result << std::endl;

	result = bsp(Point(-5.4,6.4),Point(10.1,30.1),Point(20.2,-6.2),Point(20.13,5.23));;
	std::cout << result << std::endl;

	result = bsp(Point(-5.4,6.4),Point(10.1,30.1),Point(20.2,-6.2),Point(5,20));;
	std::cout << result << std::endl;


	return (0);
}