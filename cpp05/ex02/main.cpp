#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{       try {
        std::cout << "----BASIC-TESTS-----" << std::endl;
	Bureaucrat Bur50("BoB50", 50);
        Bureaucrat Bur100("BoB100", 100);
        Bureaucrat Bur1("SuperBob", 1);
	std::cout <<Bur50;
        std::cout <<Bur100;
        ShrubberyCreationForm Berry1;
        Bur100.signAForm(Berry1);
        Bur100.executeAForm(Berry1);
        ShrubberyCreationForm Berry2("BIGTREE");
        //Bur100.signAForm(Berry2);
        ShrubberyCreationForm Berry3(Berry2);
        Bur100.executeAForm(Berry2);
        std::cout << "----BERRY-CLONING-----" << std::endl;
        Berry1 = Berry2;
        ShrubberyCreationForm Berry4 = Berry1;
        std::cout << Berry1;
        std::cout << Berry2;
        std::cout << Berry3;
        std::cout << Berry4;
        Bur100.executeAForm(Berry1);

        std::cout << "----BASIC-ROBOTRY-----" << std::endl;     
        RobotomyRequestForm Robot1;
        std::cout << Robot1;
        Bur100.executeAForm(Robot1);
        Bur100.signAForm(Robot1);

        Bur50.executeAForm(Robot1);
        Bur50.signAForm(Robot1);
        Bur50.executeAForm(Robot1);
        std::cout << "----TESTING 50/50-----" << std::endl;   
        Bur1.executeAForm(Robot1);

        std::cout << "----BASIC-PRESIDENTAL-----" << std::endl; 
        PresidentialPardonForm President1("BadBoB");
        std::cout << President1;
     
        Bur50.executeAForm(President1);
        Bur50.signAForm(President1);
        Bur50.executeAForm(President1);

        Bur1.executeAForm(President1);
        Bur1.signAForm(President1);
        Bur1.executeAForm(President1);}
        catch (std::exception & e){
                std::cout << e.what() << std::endl;
        }
	return 0;
}
