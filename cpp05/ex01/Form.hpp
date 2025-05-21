#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _signature;
		const unsigned int _grade;
		const unsigned int _level;
	public:
		Form();
		Form(std::string name, bool signature, unsigned int grade, unsigned int level); 
		Form (const Form &copy);
		Form& operator=(const Form &rhs);
		~Form();
		
		std::string getName();
		bool getSignature();
		unsigned int getGrade();
		unsigned int getLevel();
		void beSigned(Bureaucrat &bur);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw(); 
        };              
};

std::ostream &operator<<(std::ostream &stream, Form &For);

#endif
