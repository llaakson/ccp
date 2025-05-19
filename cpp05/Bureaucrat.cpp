#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat () : _name("Bureaucrat1"), _grade(150){}

Bureaucrat::Bureaucrat (std::string name, unsigned int grade) : _name(name)
{
	if (grade > MIN_GRADE)
		throw std::invalid_argument("Bureaucrat::GradeTooHighException");
	if (grade < MAX_GRADE)
		throw std::invalid_argument("Bureaucrat::GradeTooLowException");
	_grade = grade;	
}

Bureaucrat::Bureaucrat (const Bureaucrat &copy) : _grade(copy._grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		//_name = rhs._name;
        	_grade = rhs._grade;
	
	}
	return (*this);
}

Bureaucrat::~Bureaucrat (){}
                
std::string Bureaucrat::getName() { return (_name); }
unsigned int Bureaucrat::getGrade() { return (_grade); }

void Bureaucrat::increaseGrade()
{
        if (_grade < MAX_GRADE + 1)
                throw std::invalid_argument("Bureaucrat::GradeTooLowException");
	else 
		_grade++;
}

void Bureaucrat::deacreaseGrade()
{
       if (_grade > MIN_GRADE - 1)    
                throw std::invalid_argument("Bureaucrat::GradeTooHighException");
       else
	       _grade--;
}

