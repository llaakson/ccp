#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}
Intern::Intern(const Intern &copy)
{
	(void)copy;
}
Intern& Intern::operator=(const Intern &rhs)
{
	if (this != &rhs)
		return *this;
	return *this;
}
Intern::~Intern(){}

AForm* Intern::makeForm(std::string fname, std::string target)
{
	std::string form_names[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for(int i = 0; i < 3; i++){
		if (fname == form_names[i]){
			std::cout << "Intern creates " << fname << std::endl;
			switch (i){
				case 0:
					return (new ShrubberyCreationForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new PresidentialPardonForm(target));
			}
		}
	}
	std::cout << "Intern failed to create " << fname << std::endl;
	return (nullptr);
}