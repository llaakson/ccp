#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
    if (this != &rhs)
        return *this;
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::executeAction() const
{
    
std::cout <<". ____  ____  ____  ____  ___  ." << std::endl; 
std::cout <<".(_  _)(  _ \\( ___)( ___)/ __) ." << std::endl; 
std::cout <<".  )(   )   / )__)  )__) \\__ \\ ." << std::endl; 
std::cout <<". (__) (_)\\_)(____)(____)(___/ ." << std::endl; 


}

const char *ShrubberyCreationForm::ShrubberyException::what() const throw(){return ("Need more berry.");}