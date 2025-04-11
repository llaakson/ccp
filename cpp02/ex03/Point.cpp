/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:16:11 by llaakson          #+#    #+#             */
/*   Updated: 2025/04/11 18:13:08 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0){}

Point::Point(const float x1, const float y1) : x(Fixed(x1)),	y(Fixed(y1)){}

Point::~Point(){}

Point::Point(const Point &previousPoint){
	*this = previousPoint;
}

Point& Point::operator=(const Point& previousPoint){
	(void)previousPoint;	
	return(*this);
}

int Point::toX( void ) const{
	return(x.toInt());
}

int Point::toY( void ) const{
	return(y.toInt());
}

std::ostream& operator<<(std::ostream &outstream, const Point &pt)
{
	outstream << pt.toX() << "," << pt.toY();
	return outstream;
}
