#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <sstream>
#include <limits>
#include <exception>

class RPN {
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN(const std::string &argv);
        ~RPN();
        RPN(const RPN &copy);
        RPN& operator=(const RPN &rhs); 

        void calculate_instance(int n1, int n2, char op);
};

#endif