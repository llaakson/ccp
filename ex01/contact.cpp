/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:47:01 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/18 17:18:07 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void Contact::setName(std::string str) {
	name = str;
}
std::string Contact::getName() {
	return (name);
}
void Contact::setLastname(std::string str) {
	lastname = str;
}
std::string Contact::getLastname() {
	return (lastname);
}
void Contact::setNickname(std::string str) {
	nickname = str;
}
std::string Contact::getNickname() {
	return (nickname);
}
void Contact::setNumber(std::string str) {
	number = str;
}
std::string Contact::getNumber() {
	return (number);
}
void Contact::setSecret(std::string str) {
	secret = str;
}
std::string Contact::getSecret() {
	return (secret);
}


