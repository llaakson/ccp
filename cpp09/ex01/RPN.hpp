#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <sstream>
#include <limits>
#include <exception>

class Polish {
    private:
        std::stack<int> _stack;
    public:
        Polish();
        Polish(const std::string &argv);
        ~Polish();
        Polish(const Polish &copy);
        Polish& operator=(const Polish &rhs); 

        void calculate_instance(int n1, int n2, char op);

};

#endif