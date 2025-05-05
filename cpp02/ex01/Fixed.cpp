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

Fixed::Fixed() : fixed(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &previousFixed){
	std::cout << "Copy constructor called" << std::endl;
	*this = previousFixed;
}

Fixed& Fixed::operator=(const Fixed& previousFixed) {
	std::cout << "Copy assigment operator called" << std::endl;
	if (this != &previousFixed)
	{
		fixed = previousFixed.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const{
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
	if (n > FT_MAX_INT){
		std::cout << "Float bigger than FT_MAX_INT" << std::endl;
		fixed = FT_MAX_INT << fractional_bits;
	}
	else if (n < FT_MIN_INT){
		std::cout << "Float smaller than FT_MIN_INT" << std::endl;
		fixed = FT_MIN_INT * (1 << fractional_bits);
	}
	else
		fixed = n << fractional_bits;

}

std::ostream &operator<<(std::ostream &stream, const Fixed& previousFixed) {
	std::cout << previousFixed.toFloat();
	return(stream);
}

Fixed::Fixed (const float f){
		std::cout << "Float constructor called" << std::endl;
		if (f > FT_MAX_INT){
			std::cout << "Float bigger than FT_MAX_INT" << std::endl;
			fixed = (int)roundf(FT_MAX_INT * (1 << fractional_bits));
		}
		else if (f < FT_MIN_INT){
			std::cout << "Float smaller than FT_MIN_INT" << std::endl;
			fixed = (int)roundf(FT_MIN_INT * (1 << fractional_bits));
		}
		else
			fixed = (int)roundf(f * (1 << fractional_bits));
}
