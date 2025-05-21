#include "Bureaucrat.hpp"

int main ()
{
	
	Bureaucrat Bur50("BoB50", 50);
        Bureaucrat Bur100("BoB100", 100);
	std::cout <<Bur50;
        std::cout <<Bur100;
        Form Form40("Form40",false,40,40);
        Form Form100("Form100",false,100,100);
        Form Form150("Form150",false,150,150);
        Form Form9001("Form9001",false,9001,9001);
        std::cout << Form40;
        std::cout << Form100;
        std::cout << Form150;
        std::cout << Form9001;



	return 0;
}
