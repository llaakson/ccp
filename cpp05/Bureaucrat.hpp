#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>

#define MAX_GRADE 1
#define MIN_GRADE 150

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
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat &Bur);

#endif
