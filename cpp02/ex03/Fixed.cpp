/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:24:58 by llaakson          #+#    #+#             */
/*   Updated: 2025/04/11 18:33:07 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : fixed(0) {
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &previousFixed){
	//std::cout << "Copy constructor called" << std::endl;
	*this = previousFixed;
}

Fixed& Fixed::operator=(const Fixed& previousFixed) {
	//std::cout << "Copy assigment operator called" << std::endl;
	if (this != &previousFixed)
	{
		//(Fixed(previousFixed));
		fixed = previousFixed.fixed;
		//fixed = getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(){
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ){
	//std::cout << "getRawBits member function called" << std::endl;
	return (fixed);
}

void Fixed::setRawBits( int const raw ){
	//std::cout << "setRawBits member function called" << std::endl;
	this->fixed = raw;
}

float Fixed::toFloat( void ) const{
	return(fixed / (float)(1 << fractional_bits));
}

int Fixed::toInt( void ) const{
	return(fixed >> fractional_bits);
}

Fixed::Fixed (const int n){
	//std::cout << "Int constructor called" << std::endl;
	fixed = (int)roundf(n * (1 << fractional_bits));
}

std::ostream &operator<<(std::ostream &stream, const Fixed& previousFixed) {
	std::cout << previousFixed.toFloat();
	return(stream);
}

Fixed::Fixed (const float f){
		//std::cout << "Float constructor called" << std::endl;
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
	std::cout << "operator++" << std::endl;
	fixed += 1;
	return (*this);
}
Fixed Fixed::operator ++(int){
	std::cout << "operator++2" << std::endl;
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






















