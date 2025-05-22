#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
	
	Bureaucrat Bur50("BoB50", 50);
        Bureaucrat Bur100("BoB100", 100);
	std::cout <<Bur50;
        std::cout <<Bur100;
        ShrubberyCreationForm Berry1;
        Bur100.executeForm(Berry1);
        
        /*Bur50.signAForm(AForm40);
        Bur50.signAForm(AForm100);
        Bur50.signAForm(AForm150);
       //Bur100.signAForm(AForm9001);
        Bur100.signAForm(AForm40);
        Bur100.signAForm(AForm100);
        Bur100.signAForm(AForm150);
        //Bur100.signAForm(AForm9001);

        try{
                AForm AForm9001("AForm9001",false,9001,9001);
        }
        catch (std::exception & e)
        {                                                       
                std::cout << e.what() << std::endl;
        }*/


	return 0;
}
