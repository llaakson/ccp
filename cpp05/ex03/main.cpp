#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main ()
{
        {
                Intern someRandomIntern;
                Bureaucrat SuperBoB("SuperBoB", 1);
                Form* rrf;
                Form* rrf2;
                rrf = someRandomIntern.makeForm("robotomy request", "Bender");
                rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
                rrf2 = someRandomIntern.makeForm("AAA", "Bender");
                //rrf->execute(SuperBoB);
                SuperBoB.executeForm(*rrf);
                SuperBoB.signForm(*rrf);
                SuperBoB.executeForm(*rrf);
                delete rrf;
                delete rrf2;
        }
	return 0;
}
