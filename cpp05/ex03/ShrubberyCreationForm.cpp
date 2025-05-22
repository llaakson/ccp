#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), _target("DefaultTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", false, 145, 137), _target(copy._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}

std::string ShrubberyCreationForm::getTarget(){return (_target);}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream outfile;
	outfile.open(_target + "_shrubbery");
    if (!outfile.is_open())
    {
         std::cerr << "Failed to create/open outfile" << std::endl;
         return ; 
    }
    outfile <<". ____  ____  ____  ____  ___  .\n" ; 
    outfile <<".(_  _)(  _ \\( ___)( ___)/ __) .\n" ; 
    outfile <<".  )(   )   / )__)  )__) \\__ \\ .\n" ; 
    outfile <<". (__) (_)\\_)(____)(____)(___/ .\n" ; 
    outfile.close();
}