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
		const int _grade;
		const int _level;
	public:
		Form();
		Form(std::string name, bool signature, int grade, int level); 
		Form (const Form &copy);
		Form& operator=(const Form &rhs);
		~Form();
		
		std::string getName();
		bool getSignature();
		int getGrade();
		int getLevel();
		void beSigned(Bureaucrat &bur);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw(); 
        };   
		class NoSignature : public std::exception {
            public:
                const char *what() const throw(); 
        };                              
};

std::ostream &operator<<(std::ostream &stream, Form &For);

#endif
