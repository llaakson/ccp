#include "AForm.hpp"

Form::Form() : _name("Formless"), _signature(false), _grade(150), _level(150){}

Form::Form(std::string name, bool signature, int grade, int level) : _name(name), _signature(signature), _grade(grade), _level(level)
{
    if (grade > MIN_GRADE)
		throw GradeTooLowException();
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
    if (level > MIN_GRADE)
		throw GradeTooLowException();
	if (level < MAX_GRADE)
		throw GradeTooHighException();
}

Form::Form (const Form &copy) : _name(copy._name), _signature(copy._signature), _grade(copy._grade), _level(copy._level)
{
}

Form& Form::operator=(const Form &rhs)
{
    if (this != &rhs)
        _signature = rhs._signature;
    return *this;
}

Form::~Form(){}

std::string Form::getName(){return(_name);}
bool Form::getSignature(){return(_signature);}
int Form::getGrade(){return(_grade);}
int Form::getLevel(){return(_level);}

const char *Form::GradeTooHighException::what() const throw(){return ("grade is too high.");}
const char *Form::GradeTooLowException::what() const throw(){return ("grade is too low.");}
const char *Form::NoSignature::what() const throw(){return ("form is already signed.");}
                
void Form::beSigned(Bureaucrat &bur)
{
    if (bur.getGrade() > _level)
        throw GradeTooLowException();
    if (_signature == true)
        throw NoSignature();
    else
        _signature = true;
}

std::ostream &operator<<(std::ostream &stream, Form &For)
{
	stream << "Form name: " << For.getName() << " signature status: " << For.getSignature() << " grade: " << For.getGrade() << " level: " << For.getLevel() << std::endl;
	return (stream);
}