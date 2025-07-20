#include "Polish.hpp"

Polish::Polish(){}

Polish::~Polish(){}

Polish::Polish(const Polish &copy){ 
    *this = copy;
}

Polish& Polish::operator=(const Polish &rhs){
    if (this != &rhs)
        return *this;
    return *this;
}

void Polish::calculate_instance(int n1, int n2, char op){
//std::cout << n1 << " " << op << " " << n2 << std::endl;
if (op == '+')
    _stack.push(n1 + n2);
else if (op == '-')
    _stack.push(n1 - n2);
else if (op == '*')
    _stack.push(n1 * n2);
else{
    if (n2 == 0){
        std::cerr << "Error! Division by zero" << std::endl;
        throw 420;}
    _stack.push(n1 / n2);
    } 
}

Polish::Polish(const std::string &argv)
{
    std::stringstream input(argv);
    std::string number;

    if (argv.size() < 5){
    std::cerr << "Error! Not a valid operation" << std::endl;
    throw 420;}
    if (argv.find_first_not_of("+-/*01234567898 ") != std::string::npos){
    std::cerr << "Error! Invalid characters use only: '+/-*0123456789 '" << std::endl;
    throw 420;}

    while (std::getline(input,number, ' '))
    {   
        if (number.size() > 1){
            std::cerr << "Error! Split your chars with spaces" << std::endl;
        throw 420;}
        if (std::isdigit(number[0])){
            //std::cout << "Putting in stack: " << number << std::endl;
            _stack.push(std::stoi(number));
        }
        else {
            if (_stack.size() < 2){
                std::cerr << "Error! Invalid input" << std::endl;
            throw 420;}
            int n2 = _stack.top();
            _stack.pop();
            int n1 = _stack.top();
            _stack.pop();
            char op = number[0];
            calculate_instance(n1,n2,op);
        }
    }
    if (_stack.size() > 1){
                std::cerr << "Error! Invalid input" << std::endl;
            throw 420;}
    std::cout <<_stack.top() << std::endl;
}