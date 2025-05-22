#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
	Bureaucrat Bur50("BoB50", 50);
        Bureaucrat Bur100("BoB100", 100);
        Bureaucrat Bur1("SuperBob", 1);
	std::cout <<Bur50;
        std::cout <<Bur100;
        ShrubberyCreationForm Berry1;
        Bur100.signForm(Berry1);
        Bur100.executeForm(Berry1);
        ShrubberyCreationForm Berry2("BIGTREE");
        ShrubberyCreationForm Berry3(Berry2);
        Berry1 = Berry2;
        std::cout << Berry2.getTarget() << std::endl;
        std::cout << Berry1.getTarget() << std::endl;
        std::cout << Berry3.getTarget() << std::endl;
        Bur100.executeForm(Berry1);

        RobotomyRequestForm Robot1;
        Bur100.executeForm(Robot1);
        Bur100.signForm(Robot1);
        Bur100.executeForm(Robot1);

        Bur50.executeForm(Robot1);
        Bur50.signForm(Robot1);
        Bur50.executeForm(Robot1);
        Bur1.executeForm(Robot1);

        PresidentialPardonForm President1("BadBoB");
        Bur100.executeForm(President1);
        Bur100.signForm(President1);
        Bur100.executeForm(President1);

        Bur50.executeForm(President1);
        Bur50.signForm(President1);
        Bur50.executeForm(President1);

        Bur1.executeForm(President1);
        Bur1.signForm(President1);
        Bur1.executeForm(President1);

	return 0;
}
