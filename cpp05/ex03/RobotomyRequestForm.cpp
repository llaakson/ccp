#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45), _target("DefaultTarget") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", false, 72, 45), _target(copy._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm(){}

std::string RobotomyRequestForm::getTarget(){return (_target);}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "Making some drilling noices" << std::endl;
	srand(time(NULL));
	if (rand()%100 % 2 == 0)
		std::cout << _target << " has been robotomized." << std::endl;
	else
		std::cout << "Failed to robotomize " << _target << std::endl;
}