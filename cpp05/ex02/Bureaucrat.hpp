#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150

class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		unsigned int _grade;
	public:
		Bureaucrat ();
		Bureaucrat (std::string name, unsigned int grade);
		Bureaucrat (const Bureaucrat &copy);
		Bureaucrat& operator=(const Bureaucrat &rhs);
		~Bureaucrat ();
		
		std::string getName();
		unsigned int getGrade();
		void increaseGrade();
		void deacreaseGrade();
		void signForm(AForm &AForm);
		void executeForm(AForm const & form);

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw(); 
        };              

};

std::ostream &operator<<(std::ostream &stream, Bureaucrat &Bur);

#endif
