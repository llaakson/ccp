/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:41:35 by llaakson          #+#    #+#             */
/*   Updated: 2025/05/06 15:41:42 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <stdio.h>

//Sources
//https://nerdparadise.com/math/pointinatriangle
//https://www.mathportal.org/calculators/analytic-geometry/triangle-calculator.php?val1=0&val2=0&val3=10&val4=30&val5=20&val6=0&rb1=area#google_vignette

float calc_sign (const Point& p1, const Point& p2, const Point& p3)
{
    return (p1.toX() - p3.toX()) * (p2.toY() - p3.toY()) - (p2.toX() - p3.toX()) * (p1.toY() - p3.toY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
		
	bool has_neg, has_pos;

	Fixed ab = calc_sign(point, a, b);
	Fixed bc = calc_sign(point, b, c);
	Fixed ca = calc_sign(point, c, a);

	//printf("Sign calculations: d1 %d d2 %d d3 %d\n", ab.toInt(), bc.toInt(), ca.toInt());

	has_neg = (ab < Fixed(0)) || (bc < Fixed(0)) || (ca < Fixed(0));
    has_pos = (ab > Fixed(0)) || (bc > Fixed(0)) || (ca > Fixed(0));

	return !(has_neg && has_pos);
}
