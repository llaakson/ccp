#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main ()
{
        {
                try {
                Intern someRandomIntern;
                Bureaucrat SuperBoB("SuperBoB", 1);
                AForm* rrf;
              
                rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");
                SuperBoB.signAForm(*rrf);
                SuperBoB.executeAForm(*rrf);
                delete rrf;
                } catch (std::exception &e) {
                        std::cout << e.what () << std::endl;
                }

                try {
                Intern someRandomIntern1;
                Bureaucrat SuperBoB1("SuperBoB", 1);
                AForm* rrf;
              
                rrf = someRandomIntern1.makeForm("RobotomyRequestForm", "Bender");
                SuperBoB1.signAForm(*rrf);
                SuperBoB1.executeAForm(*rrf);
                delete rrf;
                } catch (std::exception &e) {
                        std::cout << e.what () << std::endl;
                }
               
                try {
                Intern someRandomIntern;
                AForm* rrf2;
                Bureaucrat SuperBoB41;
                rrf2 = someRandomIntern.makeForm("AAA", "Bender");
                SuperBoB41.signAForm(*rrf2);
                delete rrf2; 
                } catch (std:: exception &e) {
                        std::cout << e.what () << std::endl;
                }

                try {
                Intern someRandomIntern; 
                Bureaucrat SuperBoB42;
                AForm* rrf2;
                rrf2 = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
                SuperBoB42.signAForm(*rrf2);
                SuperBoB42.executeAForm(*rrf2);
                delete rrf2; 
                } catch (std:: exception &e) {
                        std::cout << e.what () << std::endl;
                }

        }
	return 0;
}
