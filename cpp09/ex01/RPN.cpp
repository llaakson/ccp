#include "RPN.hpp"

Polish::Polish(){}

Polish::~Polish(){}

Polish::Polish(const Polish &copy){ 
    *this = copy;
}

Polish& Polish::operator=(const Polish &rhs){
    if (this != &rhs)
        _stack = rhs._stack;
    return *this;
}

void Polish::calculate_instance(int n1, int n2, char op)
{
    long long temp_result = 0;
    if (op == '+')
    {
        temp_result = (long long)n1 + (long long)n2;
        if (temp_result < std::numeric_limits<int>::lowest() || temp_result > std::numeric_limits<int>::max())
            throw std::overflow_error("Error! Integer overflow");
        _stack.push(n1 + n2);
    }
    else if (op == '-')
    {
        temp_result = (long long)n1 - (long long)n2;
        if (temp_result < std::numeric_limits<int>::lowest()|| temp_result > std::numeric_limits<int>::max())
            throw std::overflow_error("Error! Integer overflow");
        _stack.push(n1 - n2);
    }
    else if (op == '*')
    {
        temp_result = (long long)n1 * (long long)n2;
        if (temp_result < std::numeric_limits<int>::lowest() || temp_result > std::numeric_limits<int>::max())
            throw std::overflow_error("Error! Integer overflow");
        _stack.push(n1 * n2);
    }
    else
    {
        if (n2 == 0)
            throw std::runtime_error("Error! Division by zero");
        temp_result = (long long)n1 / (long long)n2;
        if (temp_result < std::numeric_limits<int>::lowest() || temp_result > std::numeric_limits<int>::max())
            throw std::overflow_error("Error! Integer overflow");
        _stack.push(n1 / n2);
    }
}

Polish::Polish(const std::string &argv)
{
    std::stringstream input(argv);
    std::string number;

    if (argv.size() < 5)
        throw std::runtime_error("Error! Not a valid operation");
    if (argv.find_first_not_of("+-/*01234567898 ") != std::string::npos)
        throw std::runtime_error("Error! Invalid characters use only: '+/-*0123456789 '");

    while (std::getline(input,number, ' '))
    {   
        if (number.size() > 1)
            throw std::runtime_error("Error! Split your chars with spaces");
        if (std::isdigit(number[0]))
            _stack.push(std::stoi(number));
        else 
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error! Invalid input");
            int n2 = _stack.top();
            _stack.pop();
            int n1 = _stack.top();
            _stack.pop();
            char op = number[0];
            calculate_instance(n1,n2,op);
        }
    }
    if (_stack.size() > 1)
        throw std::runtime_error("Error! Invalid input");
    std::cout <<_stack.top() << std::endl;
}