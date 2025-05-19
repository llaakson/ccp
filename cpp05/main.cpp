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
        Bureaucrat Bur1("BoB", 0);
        }
        catch (std::exception & e)
        {                                                       
                std::cout << e.what() << std::endl;
        }


	return 0;
}
