/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:48:55 by llaakson          #+#    #+#             */
/*   Updated: 2025/04/11 13:29:21 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "Arithmetic operators" << std::endl;
	Fixed const c( Fixed( 5.05f ) + Fixed( 2 ) );
	std::cout << c << std::endl;
	Fixed const v( Fixed( 5.05f ) - Fixed( 2 ) );
	std::cout << v << std::endl;
	Fixed const n( Fixed( 5.05f ) / Fixed( 2 ) );
	std::cout << n << std::endl;
	
	std::cout << "Comparison operators" << std::endl;
	std::cout << "b is: " << b.toInt() << " a is: " << a.toInt() << std::endl;
	std::cout << "b is bigger than a: " << (b > a) << std::endl;
	std::cout << "b is smaller than a: " << (b < a) << std::endl;
	std::cout << "b is bigger or equal than a: " << (b >= a) << std::endl;
	std::cout << "b is smallar or equal than a: " << (b <= a) << std::endl;
	std::cout << "b is equal to a: " << (b == a) << std::endl;
	std::cout << "b is different than a: " << (b != a) << std::endl;

	std::cout << "MIN & MAX const" << std::endl;
	Fixed q(42);
	Fixed w(43);
	Fixed const e(42);
	Fixed const r(43);
	std::cout << Fixed::max( e, r ) << std::endl;
	std::cout << Fixed::min( q, w ) << std::endl;

	std::cout << "MIN & MAX non const" << std::endl;
	std::cout << Fixed::max( e, r ) << std::endl;
	std::cout << Fixed::max( q, w ) << std::endl;

	return 0;
}
