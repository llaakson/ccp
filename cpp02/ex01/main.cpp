/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:48:55 by llaakson          #+#    #+#             */
/*   Updated: 2025/04/10 12:49:38 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "------Bonus tests--------" << std::endl;
	Fixed e;
	Fixed const h( 2147483647 );
	Fixed const j( 42.4222222222222222222f );
	Fixed const k( h );
	e = Fixed( -8388609 );
	std::cout << "e is " << e << std::endl;
	std::cout << "h is " << h << std::endl;
	std::cout << "j is " << j << std::endl;
	std::cout << "k is " << k << std::endl;
	std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	std::cout << "h is " << h.toInt() << " as integer" << std::endl;
	std::cout << "j is " << j.toInt() << " as integer" << std::endl;
	std::cout << "k is " << k.toInt() << " as integer" << std::endl;


	return 0;
}
