#include "Bureaucrat.hpp"
#include  "AForm.hpp"

Bureaucrat::Bureaucrat () : _name("Bureaucrat1"), _grade(150){}

Bureaucrat::Bureaucrat (std::string name, int grade) : _name(name)
{
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	_grade = grade;	
}

Bureaucrat::Bureaucrat (const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
        	_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat (){}
                
std::string Bureaucrat::getName() { return (_name); }
int Bureaucrat::getGrade() const { return (_grade); }

void Bureaucrat::increaseGrade()
{
        if (_grade == MAX_GRADE)
                throw GradeTooHighException();
	else 
		_grade--;
}

void Bureaucrat::deacreaseGrade()
{
       if (_grade == MIN_GRADE)    
                throw GradeTooLowException();
       else
	       _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){return ("Grade too high.");}
const char *Bureaucrat::GradeTooLowException::what() const throw(){return ("Grade too low.");}

std::ostream &operator<<(std::ostream &stream, Bureaucrat &Bur)
{
	stream << Bur.getName() << ", bureaucrat grade " << Bur.getGrade() << std::endl;
	return (stream);
}

void Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
	}
	catch (std::exception & e){
		std::cout << getName() << " couldn't sign " << form.getName() << " because grade is too low." << std::endl;
		return ;
	}
	std::cout << getName() << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(Form const & form)
{
	std::cout << getName() << " executed " << form.getName() << std::endl;
	try {
	form.execute(*this);}
	catch (std::exception & e)
    {                                                       
        std::cout << e.what() << std::endl;
		return ;
    }
}