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
        std::cout << Form40;
        std::cout << Form100;
        std::cout << Form150;
        //std::cout << Form9001;
        Bur50.signForm(Form40);
        Bur50.signForm(Form100);
        Bur50.signForm(Form150);
       //Bur100.signForm(Form9001);
        Bur100.signForm(Form40);
        Bur100.signForm(Form100);
        Bur100.signForm(Form150);
        //Bur100.signForm(Form9001);

        try{
                Form Form9001("Form9001",false,9001,9001);
        }
        catch (std::exception & e)
        {                                                       
                std::cout << e.what() << std::endl;
        }


	return 0;
}
