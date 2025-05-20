#include "Bureaucrat.hpp"

int main ()
{
	try 
	{
	Bureaucrat Bur1("BoB", 151);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try 
        {
        Bureaucrat Bur2("BoB", 0);
        }
        catch (std::exception & e)
        {                                                       
                std::cout << e.what() << std::endl;
        }

        Bureaucrat Bur3("BoB", 3);
	std::cout <<Bur3;

	try 
        {
        Bur3.increaseGrade();
        }
        catch (std::exception & e)
        {                                                       
                std::cout << e.what() << std::endl;
        }
	std::cout <<Bur3;
	try 
        {
        Bur3.increaseGrade();     
        }
        catch (std::exception & e)
        {                                                       
                std::cout << e.what() << std::endl;
        }
        std::cout <<Bur3;
	 try
        {
        Bur3.increaseGrade();     
        }
        catch (std::exception & e)
        {                                                       
                std::cout << e.what() << std::endl;
        }
        std::cout <<Bur3;



	return 0;
}
