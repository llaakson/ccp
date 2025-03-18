/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 11:04:24 by llaakson          #+#    #+#             */
/*   Updated: 2025/03/18 17:16:09 by llaakson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "main.hpp"

class Contact {
	private:
		std::string name;
		std::string lastname;
		std::string nickname;
		std::string number;
		std::string secret;
	public:
		void setName(std::string str);
		std::string getName();
		void setLastname(std::string str);
		std::string getLastname();
		void setNickname(std::string str);
		std::string getNickname();
		void setNumber(std::string str);
		std::string getNumber();
		void setSecret(std::string str);
		std::string getSecret();
};

#endif
