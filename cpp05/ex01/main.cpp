#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
    std::cout << std::endl << "--TESTING--" << std::endl;
    {
        Bureaucrat Bur50("BoB50", 50);
        Bureaucrat Bur100("BoB100", 100);
    std::cout <<Bur50;
    std::cout <<Bur100;

    Form Form40("Form40",false,40,40);
    Form Form90("Form90",false,90,90);
    Form Form150("Form150",false,150,150);
    std::cout << Form40;
    std::cout << Form90;
    std::cout << Form150;

    Bur50.signForm(Form40);
    Bur50.signForm(Form90);
    Bur50.signForm(Form150);
    Bur100.signForm(Form40);
    Bur100.signForm(Form90);
    Bur100.signForm(Form150);
    std::cout << Form40;
    std::cout << Form90;
    std::cout << Form150;
    
    }
   
    {
    std::cout << std::endl << "--TESTING-CATCHING--" << std::endl;
    try{
            Form Form9001("Form9001",false,9,9001);
            std::cout << Form9001;
    }catch (std::exception & e){                                                       
            std::cout << e.what() << std::endl;
    }
    try{
            Form Form9001("Form9001",false,9001,9);
            std::cout << Form9001;
    }catch (std::exception & e){                                                       
            std::cout << e.what() << std::endl;
    }
    try{
            Form Form9("Form9",false,9,9);
            std::cout << Form9;
    }catch (std::exception & e){                                                       
            std::cout << e.what() << std::endl;
    }
    }
    
    {
    try{
    std::cout << std::endl << "--TESTING-COPYING--" << std::endl;
    Bureaucrat Mark1("Mark1", 42);
    Bureaucrat Mark2 = Mark1;
    Form Form1("test", false, 20, 20);
    Form Form2 = Form1;
    Form Form3(Form2);
    std::cout << Form3;
    std::cout << Mark2;
    Mark2.signForm(Form3);
    }catch (std::exception & e){                                                       
            std::cout << e.what() << std::endl;
    }
    }
    return 0;
}
