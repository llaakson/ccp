#define FORM_HPP
#ifndef FORM_HPP
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	public:
		const std::string _name;
		bool _signature;
		const unsigned int _grade;
		const unsigned int _egrade;
	private:
		Form();
		Form (const Form &copy);
		Form& operator=(const Form &rhs);
		~Form();
		
		std::string getName();
		bool getSignature();
		unsigned int getGrade();
		unsigned int getEGrade();

		beSigned(const Bureaucrat);
};

#define FORM_HPP
