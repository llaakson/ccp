#include "Bureaucrat.hpp"

int main ()
{
	
	/*Bureaucrat Bur50("BoB50", 50);
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


	return 0;*/
           {
        Bureaucrat b1;
        Bureaucrat b2("Henryk", 100);
        Bureaucrat b3("Dyrektor", 1);

        Form f1;
        Form f2;
        Form lowest("podanie", 0, 150, 150);
        Form highest("decyzja", 0, 1, 1);
        std::cout << "--test one--" << std::endl;
        std::cout << lowest << std::endl;
        std::cout << highest << std::endl;

        lowest.beSigned(b2);
        b2.signForm(lowest);
        b3.signForm(highest);
    }
    {
        std::cout << std::endl << "--test two--" << std::endl;
        Bureaucrat b1("prezes", 1);
        Bureaucrat b2("normik", 150);
        Form f1("kartka", 0, 150, 150);
        Form f2("bardzo pilne bardzo wazne", 0, 1, 1);
        Form f3("podpisana kartka", 1, 149, 149);
        b2.signForm(f1);
        b2.signForm(f2);
        b2.signForm(f1);
        b2.signForm(f3);
        b1.signForm(f2);
        b1.signForm(f2);
    }
    {
        std::cout << std::endl << "--test three--" << std::endl;
        Bureaucrat c1;
        Bureaucrat c2 = c1;
        Form z1("test", 0, 20, 20);
        Form z2 = z1;
        c2.signForm(z2);
    }
    {
        std::cout << std::endl << "--fail form test--" << std::endl;
        try{
            Form failForm("fail", 1, 151, 0);
        }
        catch(std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}
