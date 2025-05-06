/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:57:26 by llaakson          #+#    #+#             */
/*   Updated: 2025/04/11 18:13:10 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;		
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &previousPoint);
		Point& operator=(const Point& previousPoint);
		~Point();
		int toX(void) const;
		int toY(void) const;		
};

#endif
