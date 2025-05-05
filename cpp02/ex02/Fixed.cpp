/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:24:58 by llaakson          #+#    #+#             */
/*   Updated: 2025/04/11 13:16:05 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>


Fixed::Fixed() : fixed(0) {
}

Fixed::Fixed(const Fixed &previousFixed){
	*this = previousFixed;
}

Fixed& Fixed::operator=(const Fixed& previousFixed) {
	if (this != &previousFixed)
	{
		fixed = previousFixed.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(){
}

int Fixed::getRawBits( void ) const{
	return (fixed);
}

void Fixed::setRawBits( int const raw ){
	this->fixed = raw;
}

float Fixed::toFloat( void ) const{
	return(fixed / (float)(1 << fractional_bits));
}

int Fixed::toInt( void ) const{
	return(fixed >> fractional_bits);
}

Fixed::Fixed (const int n){
	fixed = (int)roundf(n * (1 << fractional_bits));
}

std::ostream &operator<<(std::ostream &stream, const Fixed& previousFixed) {
	std::cout << previousFixed.toFloat();
	return(stream);
}

Fixed::Fixed (const float f){
		fixed = (int)roundf(f * (1 << fractional_bits));
}

Fixed Fixed::operator*(const Fixed &number) const{
	float result = this->toFloat() * number.toFloat();
	return (result);
}

Fixed Fixed::operator+(const Fixed &number) const{
	float result = this->toFloat() + number.toFloat();
	return (result);
}

Fixed Fixed::operator-(const Fixed &number) const{
	float result = this->toFloat() - number.toFloat();
	return (result);
}

Fixed Fixed::operator/(const Fixed &number) const{
	float result = this->toFloat() / number.toFloat();
	return (result);
}

Fixed& Fixed::operator++(){
	fixed += 1;
	return (*this);
}
Fixed Fixed::operator ++(int){
	Fixed temp(*this);
	fixed += 1;
	return (temp);

}
Fixed& Fixed::operator--(){
	fixed -= 1;
	return (*this);
}
Fixed Fixed::operator--(int){
	Fixed temp(*this);
	fixed -= 1;
	return (temp);
}

const Fixed &Fixed::max(const Fixed &number1, const Fixed &number2){
	if (number1.toFloat() < number2.toFloat())
		return (number2);
	else
		return (number1);
}

const Fixed &Fixed::min(const Fixed &number1, const Fixed &number2){
	if (number1.toFloat() > number2.toFloat())
		return (number2);
	else
		return (number1);
}

Fixed &Fixed::max(Fixed &number1, Fixed &number2){
	if (number1.toFloat() < number2.toFloat())
		return (number2);
	else
		return (number1);
}

Fixed &Fixed::min(Fixed &number1, Fixed &number2){
	if (number1.toFloat() > number2.toFloat())
		return (number2);
	else
		return (number1);
}

bool Fixed::operator>(const Fixed &number) const{
	return (this->fixed > number.fixed);
}

bool Fixed::operator<(const Fixed &number) const{
	return (this->fixed < number.fixed);
}

bool Fixed::operator>=(const Fixed &number) const{
	return (this->fixed >= number.fixed);
}

bool Fixed::operator<=(const Fixed &number) const{
	return (this->fixed <= number.fixed);
}

bool Fixed::operator==(const Fixed &number) const{
	return (this->fixed == number.fixed);
}

bool Fixed::operator!=(const Fixed &number) const{
	return (this->fixed != number.fixed);
}






















