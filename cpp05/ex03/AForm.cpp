#include "AForm.hpp"

AForm::AForm() : _name("AFormless"), _signature(false), _grade(150), _level(150){}

AForm::AForm(std::string name, bool signature, unsigned int grade, unsigned int level) : _name(name), _signature(signature), _grade(grade), _level(level)
{
    if (grade > MIN_GRADE)
		throw GradeTooLowException();
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
}

AForm::AForm (const AForm &copy) : _name(copy._name), _signature(copy._signature), _grade(copy._grade), _level(copy._level){}

AForm& AForm::operator=(const AForm &rhs)
{
    if (this != &rhs)
        _signature = rhs._signature;
    return *this;
}

AForm::~AForm(){}
                        
std::string AForm::getName() const {return(_name);}
bool AForm::getSignature() const {return(_signature);}
unsigned int AForm::getGrade() const {return(_grade);}
unsigned int AForm::getLevel() const {return(_level);}

const char *AForm::GradeTooHighException::what() const throw(){return ("AForm's grade too high.");}
const char *AForm::GradeTooLowException::what() const throw(){return ("AForm's grade too low.");}
const char *AForm::NoSignature::what() const throw(){return ("Form has no signature.");}
                
void AForm::beSigned(Bureaucrat &bur)
{
    if (bur.getGrade() > _grade)
        throw GradeTooLowException();
    if (_signature == true)
        std::cout << bur.getName() << " couldn't sign " << getName() << " because grade is already signed." << std::endl;
    else
        _signature = true;
}

std::ostream &operator<<(std::ostream &stream, AForm &For)
{
	stream << "For name: " << For.getName() << " signature status: " << For.getSignature() << " grade: " << For.getGrade() << " level: " << For.getLevel() << std::endl;
	return (stream);
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getLevel())
        throw GradeTooLowException();
    if (getSignature() == false)
        throw NoSignature();
    executeAction();
}
