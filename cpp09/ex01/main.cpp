#include "Polish.hpp"

int main(int argc,char **argv)
{
    if (argc != 2){
       std::cerr << "Error! Give one argument example: ./RPN '42 42 +'" << std::endl; return 1;} 
    try{
    Polish Rpn(argv[1]);
    Rpn.calculate_rpn();}
    catch (...){}

    return 0;
}