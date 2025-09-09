#include "RPN.hpp" 

int main(int argc,char **argv)
{
    if (argc != 2){
       std::cerr << "Error! Give one argument example: ./RPN '4 2 +'" << std::endl; return 1;} 
    try
    {
        RPN RPN_one(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(...)
    {
        std::cerr << "Error!" << std::endl;
    }

    return 0;
}