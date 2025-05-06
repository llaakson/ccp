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

	std::cout << "ARITHMEIC OPERATORS" << std::endl;
	Fixed c( 42.42f );
	std::cout << c << std::endl;
	std::cout << b << std::endl;
	std::cout << "Multiplication" << std::endl;
	std::cout << c*c << std::endl;
	std::cout << c*b << std::endl;
	std::cout << "Division" << std::endl;
	std::cout << c/c << std::endl;
	std::cout << c/b << std::endl;
	std::cout << "Addition" << std::endl;
	std::cout << c+c << std::endl;
	std::cout << c+b << std::endl;
	std::cout << "subtraction" << std::endl;
	std::cout << c-c << std::endl;
	std::cout << c-b << std::endl;
	std::cout << b-c << std::endl;

	std::cout << "COPARISON OPERATORS" << std::endl;
	std::cout << c << std::endl;
	std::cout << b << std::endl;
	std::cout << (c<b) << std::endl;
	std::cout << (c>b) << std::endl;
	std::cout << (c<=b) << std::endl;
	std::cout << (c>=b) << std::endl;
	std::cout << (c==b) << std::endl;
	std::cout << (c!=b) << std::endl;
	std::cout << (c==c) << std::endl;
	
	std::cout << "MIN & MAX" << std::endl;
	Fixed const d(99);
	std::cout << Fixed::max( c, b ) << std::endl;
	std::cout << Fixed::max( c, c ) << std::endl;
	std::cout << Fixed::min( c, b ) << std::endl;
	std::cout << Fixed::min( c, c ) << std::endl;
	std::cout << Fixed::min( b, d ) << std::endl;
	std::cout << Fixed::min( a, c ) << std::endl;

	return 0;
}
