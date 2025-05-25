#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _signature;
		const int _grade;
		const int _level;
	public:
		AForm();
		AForm(std::string name, bool signature, int grade, int level); 
		AForm (const AForm &copy);
		AForm& operator=(const AForm &rhs);
		virtual ~AForm();
		
		std::string getName() const;
		bool getSignature() const;
		int getGrade() const;
		int getLevel() const;
		void beSigned(Bureaucrat &bur);

		void execute(Bureaucrat const & executor) const;
		virtual void executeAction() const = 0;

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
		class IsSignature : public std::exception {
            public:
                const char *what() const throw(); 
        };                                  
};

std::ostream &operator<<(std::ostream &stream, AForm &For);

#endif
