/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:24:58 by llaakson          #+#    #+#             */
/*   Updated: 2025/04/10 16:10:43 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixed(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &previousFixed){
	std::cout << "Copy constructor called" << std::endl;
	fixed = previousFixed.fixed;
}

Fixed& Fixed::operator=(const Fixed& previousFixed) {
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &previousFixed)
	{
		//(Fixed(previousFixed));
		fixed = previousFixed.fixed;
		//fixed = getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ){
	std::cout << "getRawBits member function called" << std::endl;
	return (fixed);
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed = raw;
}

float Fixed::toFloat( void ) const{
	return(fixed / (float)(1 << fractional_bits));
}

int Fixed::toInt( void ) const{
	return(fixed >> fractional_bits);
}

Fixed::Fixed (const int n){
	std::cout << "Int constructor called" << std::endl;
	fixed = (int)roundf(n * (1 << fractional_bits));
}

std::ostream &operator<<(std::ostream &stream, const Fixed& previousFixed) {
	std::cout << previousFixed.toFloat();
	return(stream);
}

Fixed::Fixed (const float f){
		std::cout << "Float constructor called" << std::endl;
		fixed = (int)roundf(f * (1 << fractional_bits));
}
