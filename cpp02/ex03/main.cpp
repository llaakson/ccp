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

#include <iostream>
#include "Point.hpp"
#include <stdio.h>

//Sources
//https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle
//https://www.mathportal.org/calculators/analytic-geometry/triangle-calculator.php?val1=0&val2=0&val3=10&val4=30&val5=20&val6=0&rb1=area#google_vignette

float calc_sign (const Point& p1, const Point& p2, const Point& p3)
{
    return (p1.toX() - p3.toX()) * (p2.toY() - p3.toY()) - (p2.toX() - p3.toX()) * (p1.toY() - p3.toY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
		
	bool has_neg, has_pos;

	Fixed d1 = calc_sign(point, a, b);
	Fixed d2 = calc_sign(point, b, c);
	Fixed d3 = calc_sign(point, c, a);

	printf("Sign calculations: d1 %d d2 %d d3 %d\n", d1.toInt(), d2.toInt(), d3.toInt());

	has_neg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
    has_pos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));

	return !(has_neg && has_pos);
}

int main(){
	
	std::cout << "1st cube" << std::endl;
	bool result = bsp(Point(0,0),Point(10,30),Point(20,0),Point(5,5));
	std::cout << result << std::endl;

	result = bsp(Point(0,0),Point(10,30),Point(20,0),Point(20,5));
	std::cout << result << std::endl;

	result = bsp(Point(0,0),Point(10,30),Point(20,0),Point(5,20));
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
