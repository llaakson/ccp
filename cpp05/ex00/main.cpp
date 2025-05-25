#include "Bureaucrat.hpp"

int main ()
{
        std::cout << "TESTING EXCEPTION THROWING" << std::endl;
	try {
	Bureaucrat Bur1("BoB", 151);
	} catch (std::exception & e){
	        std::cout << e.what() << std::endl;
	}
	try 
        {
        Bureaucrat Bur2("BoB", 0);}
        catch (std::exception & e){                                                       
                std::cout << e.what() << std::endl;
        }

        try 
        {
        Bureaucrat Bur2("BoB", -100);}
        catch (std::exception & e){                                                       
                std::cout << e.what() << std::endl;
        }

         std::cout << "TESTING INCREASING AND DECRASING" << std::endl;
        try {
        Bureaucrat Bur3("BoB", 3);
	std::cout <<Bur3;
        Bur3.increaseGrade();
        Bur3.deacreaseGrade();
        Bur3.deacreaseGrade();
        std::cout <<Bur3;
        Bur3.increaseGrade();
         std::cout <<Bur3;
        Bur3.increaseGrade();
         std::cout <<Bur3;
        Bur3.increaseGrade();
         std::cout <<Bur3;
        Bur3.increaseGrade();
         std::cout <<Bur3;
        }
        catch (std::exception & e){                                                       
                std::cout << e.what() << std::endl;
        }
        try {
        Bureaucrat Bur3("BoB", 148);
	std::cout <<Bur3;
        Bur3.deacreaseGrade();
        std::cout <<Bur3;
        Bur3.deacreaseGrade();
        std::cout <<Bur3;
        Bur3.deacreaseGrade();
        std::cout <<Bur3;
        Bur3.deacreaseGrade();
        }
        catch (std::exception & e){                                                       
                std::cout << e.what() << std::endl;
        }


	return 0;
}
